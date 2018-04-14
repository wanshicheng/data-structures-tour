# 数据结构
对于学习计算机的同学来说，"数据结构"的重要性不言而喻，同时也是其他理工专业的热门选修课。
## 工具
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
Windows
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

### MSYS2
没有使用Cygwin 或 MinGW 是因为它们下载速度实在是太慢了,而且中间会出现好几次错误，一般需要翻墙才能正常下载完成。

MSYS2 首先修改 pacman 的镜像,可以参照下面的网址

https://mirrors.tuna.tsinghua.edu.cn/help/msys2/



pacman -S mingw-w64-x86_64-gcc

pacman -S mingw-w64-i686-gcc

从而使得下载速度加快。
pacman -S mingw-w64-x86_64-gdb
pacman -Sl | grep gdb

### LLVM
为什么既要装 Clang 又要装 MinGW，是因为 Clang 没有头文件,并且在VSCode中 Clang 可以实现良好的提示功能。在Win中编译CPP需要注意目标平台版本，32位和64位的区别。需要在编译命令中添加 --target 的选项设置

32位：--target=i686-w64-mingw32
64位：--target=x86_64-w64-mingw32

## 参考资料

- 严蔚敏, 吴伟民. 数据结构(C语言版)[M]. 电子工业出版社, 2010.

- 高一凡. 数据结构算法解析. 第2版[M]. 清华大学出版社, 2015.