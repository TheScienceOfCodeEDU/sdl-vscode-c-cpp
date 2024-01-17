#!/bin/bash
mkdir -p build/linux
g++ main.cpp -g -ggdb -w -lSDL2 -o build/linux/main
