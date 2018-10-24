<p align="center">
<img width="250" height="250" src="assets/images/logo/lazerus-logo.png">
</p>

# Lazerus Game Engine
Welcome to Lazerus Game Engine. 
Lazerus is a MIT-licensed open source project using SDL2 cross platform development library, kiss_sdl, and pico_sha256.
Lazerus is meant to be a lightweight option to develope games across the following Operating Systems:
- Linux
  - Debian
  - Ubuntu
  - Red Hat
- Mac OSx Yosemite
- Windows 7,8,10
Lazerus Game Engine has been set up using Code::Blocks IDE (a cross platform IDE for C++) however, 
you can use other IDE and transfer the game_engine file to it.

To Download Code::Blocks 
http://www.codeblocks.org/downloads/26
* Note: Use download with mingw setup for windows

SDL2 Libraries have been included in the project folder, however if there are any missing files
during unzipping you can get a fresh copy of the SDL2 Libraries in the below links
1) https://www.libsdl.org/download-2.0.php
2) https://www.libsdl.org/projects/SDL_mixer/
3) https://www.libsdl.org/projects/SDL_image/
4) https://www.libsdl.org/projects/SDL_ttf/
* Note: Download Development Libraries which is named  SDL2_image-devel-2.0.3-mingw.tar.gz (MinGW 32/64-bit)


# Windows Set Up
Welcome if you are a civilized normie and are using Windows, GREAT! As a reminder this is set up using Code:Blocks IDE.
Alright to set up your Window's Development Environment follow the steps below:

1. Open up the Lazerus project folder by clicking on Lazerus.cbp or locating the file in code blocks
2. Go to Compiler settings and make sure this is checked
> Have g++ follow the C++11 ISO C++ language standard [-std=c++11]
3. Build and Run and the Lazerus Window should show up and you can begin coding
4. All game logic code should go into the game folder and in the AssetHandler File

# Linux Set Up (Ubuntu)
Welcome if you are an ascended being and are using Linux, Okay... As a reminder this set up is using Code::Blocks IDE that you can download using
> sudo apt install codeblocks

To download SDL2 files use this 

> sudo apt-get install libsdl2-dev
> sudo apt-get install libsdl2-image-dev
> sudo apt-get install libsdl2-mixer-dev
> sudo apt-get install libsdl2-ttf-dev

1. Open up the lazerus project folder by clicking on on Lazerus.cbp
2. Go to Project >> Properties then click on Project build options...
3. In linker tab remove -lmingw32 from the linker command line
4. Go to Compiler settings and make sure this is checked
> Have g++ follow the C++11 ISO C++ language standard [-std=c++11]
5. Build and Run and the Lazerus Window should show up and you can begin coding
6. All game logic code should go into the game folder and in the AssetHandler File
