#ifdef __MINGW32__
 #include <SDL.h>
#else
 #include <SDL2/SDL.h>
#endif
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO ) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        SDL_Window* window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == 0)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }
        else
        {
            SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
            SDL_Event windowEvent;
            SDL_Rect rect = {0, 0, 50, 50};
            while (1) 
            {
                rect.x = (rect.x + 1) % SCREEN_WIDTH;
                rect.y = (rect.y + 1) % SCREEN_HEIGHT;

                SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 255, 255, 255));
                SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0, 0, 255));
                SDL_UpdateWindowSurface(window);

                if (SDL_PollEvent(&windowEvent))
                {
                    if (windowEvent.type == SDL_QUIT)  break;
                } 
            }	
        }
        SDL_DestroyWindow(window);
    }

    SDL_Quit();

    return 0;
}
