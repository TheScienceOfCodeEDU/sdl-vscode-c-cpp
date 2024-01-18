#ifdef __MINGW32__
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#include <stdio.h>

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO ) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		// Create window
		SDL_Window* window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			// The surface contained by the window
			SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
			SDL_Event windowEvent;
			SDL_Rect rect = {0, 0, 50, 50};
			while (true) 
			{
				rect.x = (rect.x + 1) % SCREEN_WIDTH;
				rect.y = (rect.y + 1) % SCREEN_HEIGHT;

				SDL_FillRect(screenSurface, NULL, SDL_MapRGB( screenSurface->format, 255, 255, 255));
				SDL_FillRect(screenSurface, &rect, SDL_MapRGB( screenSurface->format, 0, 0, 255));
				SDL_UpdateWindowSurface(window);

				if (SDL_PollEvent(&windowEvent))
				{
					 if (windowEvent.type == SDL_QUIT )
					 	break;
				} 
			}	
		}
		// Destroy window
		SDL_DestroyWindow(window);
	}

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
