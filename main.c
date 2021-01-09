#include "SDL2/SDL.h"
#include <stdio.h>
#include <stdbool.h>
#include "Game.h"
#include "Mouse.h"

int main(int argc, char* argv[]) {

    //----------------------------------------------------------
    // SETUP
    //----------------------------------------------------------
    Game g;
    gameInit(&g);

    Mouse mouse;

    SDL_Window* window;                    
    SDL_Renderer* renderer;                    

    if( SDL_Init(SDL_INIT_EVERYTHING) > 0)
    {
        SDL_Log("issue");
    }


    window = SDL_CreateWindow(
            g.title, 
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            g.width, 
            g.height,
            SDL_WINDOW_RESIZABLE
    );

    renderer = SDL_CreateRenderer(
            window,
            -1,
            SDL_RENDERER_SOFTWARE
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    // Check that the window was successfully created
    if (renderer == NULL) {
        // In the case that the window could not be made...
        printf("Could not create renderer: %s\n", SDL_GetError());
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

        printf("Mx: %i My:%i \n", mouse.x, mouse.y);

		// processInput();
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) {
			break;
		}

		if (event.type == SDL_MOUSEMOTION) {
            mouseUpdate(&mouse, event.motion.x, event.motion.y);
		}

		while (lag >= MS_PER_UPDATE)
		{
			// update();
			lag -= MS_PER_UPDATE;

		}
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);


	}

    // Close and destroy the window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}
