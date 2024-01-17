# SDL base project

## Quickstart

Configure the environment for your OS (see instructions below), and then use the instructions for your IDE:

### VSCodium

* Install VSCodium.
* Install these extensions:
    * [Native Debug](https://open-vsx.org/extension/webfreak/debug)
    * [C/C++ extension pack](https://open-vsx.org/extension/franneck94/vscode-c-cpp-dev-extension-pack)

Open the project and press **ctrl + shift + b** to build. Then press **F5** to Debug. You should see an empty window and you may add debug breakpoints as required.

### VSCode

* Install VSCode.
* Install these extensions:
    * [Native Debug](https://marketplace.visualstudio.com/items?itemName=webfreak.debug)
    * [C/C++ extension pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack)


Open the project and press **ctrl + shift + b** to build. Then press **F5** to Debug. You should see an empty window and you may add debug breakpoints as required.


## Configure the environment

### Linux

* Fedora:
  ```
  sudo dnf install gcc-c++
  sudo dnf install SDL2 SDL2-devel
  ```

* Ubuntu:
  ```
  sudo apt install build-essential
  sudo apt install libsdl2-dev
  ```

### Mac

Install pre-requisites by using these commands:

```
xcode-select --install
brew install SDL2
```

### Windows

#### Install MinGW-w64 

Install [MSYS2](https://www.msys2.org/) under the default folder **c:\\msys64\\**, otherwise you will need to modify the tasks under *.vscode* folder.

 When complete, ensure the Run MSYS2 now box is checked and select Finish. This will open a MSYS2 terminal window for you. Run this command and install all suggested packages:

 ```
 pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
 ```

#### SDL2

Go to [SDL2 Releases](https://github.com/libsdl-org/SDL/releases/tag/release-2.28.5) and download **SDL2-devel-2.28.5-mingw.zip**.

Open the zip file and inside it go to **SDL2-2.28.5\\x86_64-w64-mingw32\\**, extract the contents (four folders) into **c:\sdl2\\**


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
