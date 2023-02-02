#include <cstdio>
#include <SDL2/SDL.h>

int main(int argc, char* args[])
{

	int SCREEN_WIDTH = 1000;
	int SCREEN_HEIGHT = 500;
	// The window we are rendering to
	SDL_Window* window = NULL;

	// The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	// Initialize SDL
	// Returns 0 on success or a negative error code on failure.
	if (SDL_Init (SDL_INIT_VIDEO) < 0)
	{
		printf("SDL_Init could not initialize. SDL_Error: %s\n", SDL_GetError());
	}
	else 
	{
		// Create window
		window = SDL_CreateWindow("THEIA", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created. SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			// Keep SDL window up
			SDL_Event e; 
			bool quit = false; 
			while(quit == false)
			{
				while(SDL_PollEvent(&e))
				{
					if (e.type == SDL_QUIT)
						quit = true;
				}
			}
		}
		
		// Destroy Window
		SDL_DestroyWindow(window);

		// Quit SDL Subsystems
		SDL_Quit();

		return 0;
	}
}

