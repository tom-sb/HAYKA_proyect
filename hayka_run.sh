#! /bin/bash


yes | sudo pacman -Sy

yes | sudo pacman -S libbsd qt5-base tmux --needed


git clone https://github.com/tom-sb/HAYKA_proyect.git

HAYKA=$HOME/HAYKA_proyect/

cd $HAYKA

g++ -std=c++11 test_hayka.cxx -o test -lbsd
gcc servidor_hayka.c -o server


cd $HAYKA/hayra

qmake hayra.pro
make


