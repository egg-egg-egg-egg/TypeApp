# 介绍

这是一个C++实现的控制台打字软件, 出于教学目的设计。

整个项目会从一个基础的控制台打字软件开始，逐步完善，最终实现一个功能完善的打字软件。项目的目标是通过实现一个打字软件，学习C++的各种知识点。

并且每个版本都会逐步更新到`typeApp[n]`文件夹中。

## 流程图

这是最初的程序流程图，随着程序的不断完善和丰富，流程图也会不断更新。

![typeApp流程图](./assets/typeApp.png)

## 环境配置

操作系统：Windows 10/11

编辑器：

- 前期使用dev-c++
- 后期会使用vscode，且vscode使用的编译器和make工具用的都是用dev-c++的。

编辑器设置：

- dev-c++:
    - 添加编译命令`-std=c++11 -finput-charset=GBK -fexec-charset=UTF-8`。图先欠着。
    - 项目中添加额外的包含路径, 以确保可以`#include <json.hpp>`导入。视频有讲解。
    ---

- vecode需要配置`.vscode/tasks.json`, 修改`command`处即可。下面是一个示例：
    ```json
    {
        "tasks": [
            {
                "label": "Build with Makefile",
                "type": "shell",
                "command": "d:\\Dev-Cpp\\MinGW64\\bin\\mingw32-make.exe", // 改成你的
                "args": [
                    "-f",
                    "Makefile.win"
                ],
                "options": {
                    "cwd": "${workspaceFolder}/typeApp"
                },
                "group": {
                    "kind": "build",
                    "isDefault": true
                },
                "problemMatcher": [
                    "$gcc"
                ],
                "detail": "使用 Makefile.win 构建项目的任务。"
            }
        ],
        "version": "2.0.0"
    }
    ```
---


# 感谢

本项目的字典数据都是来自[qwerty-learner](https://github.com/RealKai42/qwerty-learner)项目，感谢作者和各路伙伴的开源。