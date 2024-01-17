#!/bin/bash
mkdir -p build/mac
g++ main.cpp -g -ggdb -w -lSDL2 -o build/mac/main
