#define UNITY_BUILD 1
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
    if (sdl_utils_Init("SDL Tutorial", &Window, &Renderer)) 
    {
        SDL_Texture* Texture = sdl_loadTexture("res/huxley-tech.jpg", Renderer);
        
        while (1)
        {
            SDL_RenderClear(Renderer);
            SDL_RenderCopy(Renderer, Texture, 0, 0);
            SDL_RenderPresent(Renderer);

            SDL_Event Event;
            if (SDL_PollEvent(&Event))
            {
                if (Event.type == SDL_QUIT ) break;
            } 
        }

        SDL_DestroyTexture(Texture);		
    }
    sdl_utils_Quit(Window, Renderer);
    return 0;
}
