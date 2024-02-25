#!/bin/bash
mkdir -p build/mac
g++ main.cpp -g -ggdb -w -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -o build/mac/main
