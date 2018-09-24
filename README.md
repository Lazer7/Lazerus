![Image of Lazerus](assets/images/logo/lazerus-logo.png)

# Lazerus
Welcome to Lazerus Game Engine. 
Lazerus is a MIT-licensed open source project using SDL2 cross platform development library.
Lazerus is meant to be a lightweight option to develope games across the following Operating Systems:
- Linux
  - Debian
  - Ubuntu
  - Red Hat
- Mac OSx Yosemite
- Windows 7,8,10

Lazerus Game Engine is set up using Code::Blocks IDE (a cross platform IDE for C++) and the set up will use 
this IDE for it, you can use other IDE and transfer the game_engine file to it.
Please Download the following files for SDL2
1) https://www.libsdl.org/download-2.0.php
2) https://www.libsdl.org/projects/SDL_mixer/
3) https://www.libsdl.org/projects/SDL_image/

* Note download: Development Libraries:  SDL2_image-devel-2.0.3-mingw.tar.gz (MinGW 32/64-bit)

#Windows Set Up
Welcome if you are a civilized normie and are using Windows, GREAT! As a reminder this is set up using Code:Blocks IDE.
Alright to set up your Window's Development Environment follow the steps below:
1. Open up the Lazerus project folder by clicking on Lazerus.cbp or locating the file in code blocks
2. Go to Project >> Properties then click on Project build options...
3. In linker tab add these lines
    -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer
4. Go the Search directories and compiler tab add the folder directory for SDL2 for all SDL2 files you have downloaded from above
\i686-w64-mingw32\include\SDL2 
* you should have 3 directories for SDL2, SDL_mixer, SDL_image
5. Go the Search directories and linker tab add the folder library directory for SDL2 for all SDL2 files you have downloaded from above
\i686-w64-mingw32\lib
* you should have 3 directories for SDL2, SDL_mixer, SDL_image
6. Press okay for all settings and you can now run the files