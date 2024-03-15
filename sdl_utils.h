#ifndef UNITY_BUILD
 #include <stdio.h>
 #include "common.h"
 #ifdef _WIN64
  #include <SDL.h>
  #include <SDL_image.h>
 #else
  #include <SDL2/SDL.h>
  #include <SDL2/SDL_image.h>
 #endif
#endif


function inline bool
sdl_utils_Init(const char *title, SDL_Window **window, SDL_Renderer **renderer, bool textureFiltering)
{
    if (SDL_Init(SDL_INIT_VIDEO ) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }
    if (textureFiltering)
    {
        if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }
    }

    *window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == 0)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == 0)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }
    SDL_SetRenderDrawColor(*renderer, BG_R, BG_G, BG_B, 0xFF);
    
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return 0;
    }
    
    return 1;
}

function void
sdl_utils_Quit(SDL_Window *window, SDL_Renderer *renderer)
{
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();
}
