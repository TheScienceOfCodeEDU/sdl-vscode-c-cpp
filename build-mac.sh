#!/bin/bash
mkdir -p build/mac
g++ main.cpp -g -ggdb -w -lSDL2 -lSDL2_image -o build/mac/main
