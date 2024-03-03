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
#ifdef _WIN64
 #include <SDL.h>
 #include <SDL_image.h>
#else
 #include <SDL2/SDL.h>
 #include <SDL2/SDL_image.h>
#endif
#include "common.h"
#include "sdl_utils.h"

int
main(int argc, char *args[])
{
    SDL_Window *Window;
    SDL_Renderer *Renderer;
    // Init SDL without texture filtering for better pixelart results
    if (sdl_utils_Init("SDL Tutorial", &Window, &Renderer, 0)) 
    {
        SDL_Texture* Texture = IMG_LoadTexture(Renderer, "res/characters.png");
        
        // Sprite source rectangle
        SDL_Rect SrcRect = {9, 42, 15, 21};
        // Target rectangle (note that we will paint it at x4 its original size)
        SDL_Rect DestRect = {0, 0, SrcRect.w * 4, SrcRect.h * 4};
        while (1)
        {
            SDL_RenderClear(Renderer);
            SDL_RenderCopy(Renderer, Texture, &SrcRect, &DestRect);
            SDL_RenderPresent(Renderer);

            SDL_Event Event;
            if (SDL_PollEvent(&Event))
            {
                if (Event.type == SDL_QUIT) break;
            } 
        }

        SDL_DestroyTexture(Texture);		
    }
    sdl_utils_Quit(Window, Renderer);
    return 0;
}
