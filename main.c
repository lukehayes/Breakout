#include "SDL2/SDL.h"
#include <stdio.h>
#include <stdbool.h>
#include "Game.h"

int main(int argc, char* argv[]) {

    //----------------------------------------------------------
    // SETUP
    //----------------------------------------------------------
    Game g;
    gameInit(&g);

    SDL_Window *window;                    

    SDL_Init(SDL_INIT_VIDEO);              

    window = SDL_CreateWindow(
        g.title,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        g.width,
        g.height,
        SDL_WINDOW_OPENGL
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }


    //----------------------------------------------------------
    // GAME LOOP
    //----------------------------------------------------------
    const int MS_PER_UPDATE = 30;
	double previous = SDL_GetTicks();
	double lag = 0.0;
    SDL_Event event;

	while (true)
	{

		double current = SDL_GetTicks();
		double elapsed = current - previous;
		previous = current;
		lag += elapsed;

		// processInput();

		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) {
			break;
		}

		while (lag >= MS_PER_UPDATE)
		{
			// update();
			lag -= MS_PER_UPDATE;

		}

	}

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}
