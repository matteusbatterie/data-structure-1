# An Academic Data Structure Project

## Introduction
This project contemplates the entire development of an academic work proposed by the professor [Mauro Fonseca](http://buscatextual.cnpq.br/buscatextual/visualizacv.do;jsessionid=85D72C66D058569B153210BED81588F4.buscatextual_3) who lectures Data Structure I at [UTFPr](http://www.utfpr.edu.br/). The student (me, author of this repository) developed this project in order to meet the work's criteria while also taking a step further exploring different Design Patterns and SOLID principles as it seemed appropriate. The project itself serves as an example for students that might be studying this subject as well, nonetheless.


## Environment
As this work was developed in both a Windows 10 and a Mint 19 machines, it is at least _supposed to_ be able to run in either operational systems. If one decides to clone and run this repository in their own machine, there are a few installations they would have to make sure they've already been through, being some of them:

### For Windows users
- [mingw64](https://sourceforge.net/projects/mingw-w64/) (or any C/C++/G++ compiler of your liking);
- [Visual Studio Code](https://code.visualstudio.com/Download) (Optional);
    - [Microsoft's C/C++ Extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) (Recommended);
    - [autin's C++ Intellisense](https://marketplace.visualstudio.com/items?itemName=austin.code-gnu-global) (Recommended);

### For Ubuntu users
- [g++](https://packages.ubuntu.com/search?keywords=g%2B%2B) (or any G++ compiler of your liking);
    - [Hint] if you don't have it already installed, you can do so by typing `sudo apt install g++` or `sudo apt install build-essential` on some shell you have available;
- [Visual Studio Code](https://code.visualstudio.com/Download) (Optional);
    - [Microsoft's C/C++ Extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) (Recommended);
    - [autin's C++ Intellisense](https://marketplace.visualstudio.com/items?itemName=austin.code-gnu-global) (Recommended);


There are `tasks` and `launch` configurations (used by VS Code) written for compiling and running this project on Windows or Ubuntu, but some minor changes are necessary before starting this project on your own machine. 

First of all, you will notice that there are three tasks configured within the `tasks.json` file. All of them run a command that is configurable through the `command` argument, which takes the command your shell will run when compiling a `.c` or `.cpp` file. Its value can be the command itself, if it's available in your operational system's environment variables, or you can set it to the directory where your compiler is found at (e.g.: `"command": "path/to/g++"`). Keep in mind that you must specify the location where this command is gonna be started through `cwd` option, which by default I set to its containing directory (e.g.: if my g++ is found at `/usr/bin/g++`, then my configuration will be `"cwd": "/usr/bin"`).

Similarly, `launch.json` has three launch settings related specifically to each one from `tasks.json` file. You will be willing to change its `miDebuggerPath` to where your `gdb` can be found at (e.g.: `"miDebuggerPath": "path/to/gdb"`).


Finally, with everything set up, you can compile the `_main` file or any active `.c`/`.cpp` file by pressing `CTRL+SHIFT+B` on your keyboard. Notice that there are different build configurations for Windows and Linux, feel free to add any configuration of your own. The build will generate an executable of the compiled file, then you can run this executable and a terminal should pop out in your screen.

Alternatively, you can hit `F5` and run one of the launch settings available (there are also different settings for either Windows or Linux). It will pre-run its own task before launching. By doing so you should have the application instantly initiated and see debugging options in VS Code, as it starts the application in debug mode.
