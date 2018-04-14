# 数据结构

对于学习计算机的同学来说，"数据结构"的重要性不言而喻，同时也是其他理工专业的热门选修课。

## 工具

### MSYS2

没有使用Cygwin 或 MinGW 是因为它们下载速度实在是太慢了,而且中间会出现好几次错误，一般需要翻墙才能正常下载完成。

MSYS2 首先修改 pacman 的镜像,这样可以让下载的速度更快。可以参照下面的网址：

https://mirrors.tuna.tsinghua.edu.cn/help/msys2/

我们需要安装下面这几个模块：

```shell
pacman -S mingw-w64-x86_64-gcc //针对64位

pacman -S mingw-w64-i686-gcc //针对32位

pacman -S mingw-w64-x86_64-gdb //针对64位

pacman -S mingw-w64-i686-gdb //针对32位
```

### LLVM
为什么既要装 Clang 又要装 MinGW，是因为 Clang 没有头文件,并且在VSCode中 Clang 可以实现良好的提示功能。在Win中编译CPP需要注意目标平台版本，32位和64位的区别。需要在编译命令中添加 --target 的选项设置

32位：--target=i686-w64-mingw32

64位：--target=x86_64-w64-mingw32

### Visual Studio Code
#### 插件
- C/C++
- C/C++ Clang Command Adapter:提供静态检测（Lint）
- Code Runner
- Include Autocomplete：头文件补全支持
- C/C++ Snippets
##### 可选插件
- Bracket Pair Colorizer:彩虹花括号
- VSCode Great Icons
- One Dark Pro
#### 配置

Windows首选项设置：

```json
{
    "workbench.colorTheme": "One Dark Pro Vivid",
    "code-runner.runInTerminal": true,
    "code-runner.ignoreSelection": true,
    "workbench.iconTheme": "vscode-great-icons",
    "code-runner.executorMap": {
        "javascript": "node",
        "java": "cd $dir && javac $fileName && java $fileNameWithoutExt",
        "c": "cd $dir && clang -Wno-invalid-source-encoding --target=x86_64-w64-mingw32 $fileName -o $fileNameWithoutExt.exe && $dir$fileNameWithoutExt",
        "cpp": "cd $dir && clang++ -Wno-invalid-source-encoding $fileName -o $fileNameWithoutExt.exe && $dir$fileNameWithoutExt",
        "objective-c": "cd $dir && gcc -framework Cocoa $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
        "php": "php",
        "python": "python",
        "perl": "perl",
        "perl6": "perl6",
        "ruby": "ruby",
        "go": "go run",
        "lua": "lua",
        "groovy": "groovy",
        "powershell": "powershell -ExecutionPolicy ByPass -File",
        "bat": "cmd /c",
        "shellscript": "bash",
        "fsharp": "fsi",
        "csharp": "scriptcs",
        "vbscript": "cscript //Nologo",
        "typescript": "ts-node",
        "coffeescript": "coffee",
        "scala": "scala",
        "swift": "swift",
        "julia": "julia",
        "crystal": "crystal",
        "ocaml": "ocaml",
        "r": "Rscript",
        "applescript": "osascript",
        "clojure": "lein exec",
        "haxe": "haxe --cwd $dirWithoutTrailingSlash --run $fileNameWithoutExt",
        "rust": "cd $dir && rustc $fileName && $dir$fileNameWithoutExt",
        "racket": "racket",
        "ahk": "autohotkey",
        "autoit": "autoit3",
        "dart": "dart",
        "pascal": "cd $dir && fpc $fileName && $dir$fileNameWithoutExt",
        "d": "cd $dir && dmd $fileName && $dir$fileNameWithoutExt",
        "haskell": "runhaskell",
        "nim": "nim compile --verbosity:0 --hints:off --run"
    },
    "files.autoGuessEncoding": true
}
```

launch.json

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch", // 配置名称，将会在启动配置的下拉菜单中显示
            "type": "cppdbg", // 配置类型，这里只能为cppdbg
            "request": "launch", // 请求配置类型，可以为launch（启动）或attach（附加）
            "program": "${fileDirname}/${fileBasenameNoExtension}.exe", // 将要进行调试的程序的路径
            "args": [], // 程序调试时传递给程序的命令行参数，一般设为空即可
            "stopAtEntry": false, // 设为true时程序将暂停在程序入口处，我一般设置为true
            "cwd": "${workspaceFolder}", // 调试程序时的工作目录
            "environment": [], // （环境变量？）
            "externalConsole": true, // 调试时是否显示控制台窗口，一般设置为true显示控制台
            "internalConsoleOptions": "neverOpen", // 如果不设为neverOpen，调试时会跳到“调试控制台”选项卡，你应该不需要对gdb手动输命令吧？
            "MIMode": "gdb", // 指定连接的调试器，可以为gdb或lldb。但目前lldb在windows下没有预编译好的版本。
            "miDebuggerPath": "gdb.exe", // 调试器路径。
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": false
                }
            ],
            "preLaunchTask": "Compile" // 调试会话开始前执行的任务，一般为编译程序。与tasks.json的label相对应
        }
    ]
}
```

tasks.json

```json
{
    // See https://go.microsoft.com/fwlink/?LinkId=733558
    // for the documentation about the tasks.json format
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Compile", // 任务名称，与launch.json的preLaunchTask相对应
            "command": "clang++", // 要使用的编译器
            "args": [
                "${file}",
                "-o", // 指定输出文件名，不加该参数则默认输出a.exe
                "${fileDirname}/${fileBasenameNoExtension}.exe",
                "-g", // 生成和调试有关的信息
                "-Wall", // 开启额外警告
                "-static-libgcc", // 静态链接
                "-fcolor-diagnostics",
                "--target=x86_64-w64-mingw" // 默认target为msvc，不加这一条就会找不到头文件
            ], // 编译命令参数
            "type": "shell",
            "group": {
                "kind": "build",
                "isDefault": true // 设为false可做到一个tasks.json配置多个编译指令，需要自己修改本文件，我这里不多提
            },
            "presentation": {
                "echo": true,
                "reveal": "always", // 在“终端”中显示编译信息的策略，可以为always，silent，never。具体参见VSC的文档
                "focus": false, // 设为true后可以使执行task时焦点聚集在终端，但对编译c和c++来说，设为true没有意义
                "panel": "shared" // 不同的文件的编译信息共享一个终端面板
            }
            // "problemMatcher":"$gcc" // 如果你不使用clang，去掉前面的注释符，并在上一条之后加个逗号。照着我的教程做的不需要改（也可以把这行删去)
        }
    ]
}
```

## 参考资料

- 严蔚敏, 吴伟民. 数据结构(C语言版)[M]. 电子工业出版社, 2010.

- 高一凡. 数据结构算法解析. 第2版[M]. 清华大学出版社, 2015.