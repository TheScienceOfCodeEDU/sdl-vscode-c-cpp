mkdir "build/win"
g++ main.cpp -IC:\sdl2\include\SDL2 -LC:\sdl2\lib -g -ggdb -lmingw32 -lSDL2main -lSDL2 -o build/win/main