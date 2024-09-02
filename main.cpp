// SDL VSCODE C/C++
//
// This project is part of a tutorial by The Science of Code:
// - English: https://thescienceofcode.com/sdl-vscode-c-cpp-debug/
// - Español: https://thescienceofcode.com/es/sdl-vscode-c-cpp-debug/
//
// NOTES:
// - This project uses unity build, includes inside secondary files are used only for IDE purpouses (code completition, syntax hl, etc).
// - "IWYU pragma: keep" comments are used to ignore clangd warnings related with unity builds.

#define UNITY_BUILD 1
#include <stdio.h>              // IWYU pragma: keep
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
#ifdef _WIN64
 #include <SDL.h>
 #include <SDL_image.h>
#else
 #include <SDL2/SDL.h>
 #include <SDL2/SDL_image.h>
#endif
#include "common.h"
#include "sdl_utils.h"


SDL_Window *window;
SDL_Renderer *renderer;

SDL_Texture* texture;

// Sprite source rectangle
SDL_Rect srcRect = {9, 42, 15, 21};
// Target rectangle (note that we will paint it at x4 its original size)
SDL_Rect destRect = {0, 0, srcRect.w * 4, srcRect.h * 4};


void
mainloop()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
    SDL_RenderPresent(renderer);

    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT) {
            #ifdef __EMSCRIPTEN__
             emscripten_cancel_main_loop();
            #else
             exit(0);
            #endif
        }
    }
}

int
main(int argc, char *args[])
{
    // Init SDL without texture filtering for better pixelart results
    if (sdl_utils_Init("SDL Tutorial", &window, &renderer, 0)) 
    {
        texture = IMG_LoadTexture(renderer, "./res/characters.png");
        #ifdef __EMSCRIPTEN__
         emscripten_set_main_loop(mainloop, 0, 1);
        #else
         while (1) { mainloop(); }
        #endif
    }
    return 0;
}
