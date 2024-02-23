#!/bin/bash
mkdir -p build/linux
g++ main.cpp -g -ggdb -w -lSDL2 -lSDL2_image -o build/linux/main
