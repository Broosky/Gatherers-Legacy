# Gatherers-Historic

This was a project I started and completed the bulk of during reading week while at school near the end of 2010.

I was passionate about video games (and still am) and got interested in the resource gathering mechanism of Starcraft. So, I built my own.

Originally it was built using Dev-C++ (https://www.bloodshed.net/) which comes bundled with the MinGW compiler, but have since ported it to run with VS Code, with the C/C++ extensions. Even after a few versions of Windows it still works well, and on Linux too (Ubuntu tested). 

A little bit of history: after a few POC's in C++ for classes + using stdlib for vectors (I think I have this source still hanging around) I decided to build it in C. There was not the best debugging tools with that IDE; this project was built literally with no debugging and a lot of diet cokes.

This repository was renamed to Gatherers-Historic to preserve its sentimental value. A new repository named Gatherers will supersede this which I will contribute to whenever I have some free time.

Ubuntu:

sudo apt-get install gcc-mingw-w64
sudo apt-get install wine

Compile w/i686-w64-mingw32-xxx toolchain and launch over Wine.
Compile w/x86_64-w64-mingw32-xxx toolchain and launch over Wine64.

Windows:

Install MSYS2 to C.

In Action:

![Demo](Gatherers.gif)
