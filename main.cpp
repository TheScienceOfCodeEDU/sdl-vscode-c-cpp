#define UNITY_BUILD 1
#include <stdio.h>
#ifdef __MINGW32__
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
        SDL_Texture* Texture = sdl_utils_loadTexture("res/characters.png", Renderer);
        
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
