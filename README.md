# SDL base project

![sdl sample screenshot](.docs/screenshot.png)

This project is part of a tutorial by The Science of Code. For a complete walkthrough, please check the following links otherwise continue reading the *quickstart*:

* [English guide](https://thescienceofcode.com/sdl-vscode-c-cpp-debug/)
* [Guía en Español](https://thescienceofcode.com/es/sdl-vscode-c-cpp-debug/)

Sprites used are licensed under CC0 (Public Domain) by [Buch](https://opengameart.org/content/a-platformer-in-the-forest).

## Quickstart

Configure the environment for your OS (see instructions below), and then prepare your IDE:

* For **VSCodium** install these extensions:
    * [Native Debug](https://open-vsx.org/extension/webfreak/debug)
    * [C/C++ extension pack](https://open-vsx.org/extension/franneck94/vscode-c-cpp-dev-extension-pack)
    * [clangd](https://open-vsx.org/extension/llvm-vs-code-extensions/vscode-clangd)

* For **VSCode** install these extensions:
    * [Native Debug](https://marketplace.visualstudio.com/items?itemName=webfreak.debug)
    * [C/C++ extension pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack)
    * [clangd](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd)

Open the project and press **ctrl + shift + b** to build. Then press **F5** to Debug. You should see an empty window and you may add debug breakpoints as required.


## Configuring the environment

### Linux

* Fedora:
  ```
  sudo dnf install gcc-c++
  sudo dnf install SDL2 SDL2-devel SDL2_image-devel SDL2_mixer-devel SDL2_ttf-devel
  ```

* Ubuntu:
  ```
  sudo apt install build-essential
  sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev
  ```

### Mac

Install pre-requisites by using these commands:

```
xcode-select --install
brew install SDL2
brew install sdl2_image
brew install sdl2_mixer
brew install sdl2_ttf
```

By default, we enabled LLDB as debugger otherwise you will need to [certify the **GDB** binary](https://stackoverflow.com/questions/66470788/how-to-set-gdb-as-debugger-for-the-c-c-extension-pf-vscode-on-macos).

### Windows

#### Install MinGW-w64 

Install [MSYS2](https://www.msys2.org/) under the default folder **c:\\msys64\\**, otherwise you will need to modify the tasks under *.vscode* folder.

 When complete, ensure the Run MSYS2 now box is checked and select Finish. This will open a MSYS2 terminal window for you. Run this command and install all suggested packages:

 ```
 pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
 ```

#### Installing SDL2

1. Go to [SDL2 Releases](https://github.com/libsdl-org/SDL/releases/tag/release-2.28.5) and download **SDL2-devel-2.28.5-mingw.zip**. Open the zip file and inside it go to **SDL2-2.28.5\\x86_64-w64-mingw32\\**, extract the contents (four folders) into **c:\sdl2\\**.

2. Go to [SDL2 Image Releases](https://github.com/libsdl-org/SDL_image/releases/tag/release-2.8.2) and download **SDL2_image-devel-2.8.2-mingw.zip**. Open the zip file and inside it go to **SDL2_image-2.8.2\x86_64-w64-mingw32**, extract the contents (three folders) into **c:\sdl2\\**.

3. Go to [SDL2 Mixer Releases](https://github.com/libsdl-org/SDL_mixer/releases/tag/release-2.8.0) and download **SDL2_mixer-devel-2.8.0-mingw.zip**. Open the zip file and inside it go to **SDL2_mixer-2.8.0\x86_64-w64-mingw32**, extract the contents (three folders) into **c:\sdl2\\**.

4. Go to [SDL2 TTF Releases](https://github.com/libsdl-org/SDL_ttf/releases/tag/release-2.22.0) and download **SDL2_ttf-devel-2.22.0-mingw.zip**. Open the zip file and inside it go to **SDL2_ttf-2.22.0\x86_64-w64-mingw32**, extract the contents (three folders) into **c:\sdl2\\**.

#### Environment variables

* Search for **variables** under your Windows menu and select **Edit environment variables for your system**.
* Click on **Environment variables** button, and then select **Path** and click **Edit**. Add two **new** lines:

```
C:\msys64\ucrt64\bin
C:\sdl2\bin
```

Select OK to save and re-open any program or console to use the updated PATH.

Test these commands on a terminal to check if everything went OK:

```
gcc --version
g++ --version
gdb --version
```

If something fails, double check your PATH values against real folder locations.

#### Fix highlighter error for SDL.h include

On Windows VSCode syntax highlighter won't find SDL includes by default, to fix this just **hit f1**, type **User Settings (JSON)** and press **Enter**. Finally, add the following lines to the opened JSON file:

```json
"C_Cpp.intelliSenseEngine": "disabled",
"clangd.fallbackFlags": [
    "-IC:/sdl2/include/SDL2"
]
```
