# 数据结构

## 工具
### Visual Studio Code
#### 插件
- C/C++ Clang Command Adapter
- Code Runner
#### 配置
```json
{
    "workbench.colorTheme": "One Dark Pro Vivid",
    "code-runner.runInTerminal": true,
    "code-runner.ignoreSelection": true,
    "files.encoding": "gbk",
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
    }
}
```

### MSYS2
pacman -S mingw-w64-x86_64-gcc

pacman -S mingw-w64-i686-gcc
### LLVM
在Win中编译CPP需要注意目标平台版本，32位和64位的区别。需要在编译命令中添加 --target 的选项设置。

32位：--target=i686-w64-mingw32
64位：--target=x86_64-w64-mingw32

https://mirrors.tuna.tsinghua.edu.cn/help/msys2/

## 参考资料

- 严蔚敏, 吴伟民. 数据结构(C语言版)[M]. 电子工业出版社, 2010.

- 高一凡. 数据结构算法解析.第2版[M]. 清华大学出版社, 2015.