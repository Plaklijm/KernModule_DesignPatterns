#include <SDL.h>
#include <iostream>

#include "Manager.h"

// const variables
constexpr int ScreenWidth = 800;
constexpr int ScreenHeight = 512;
constexpr int FPS = 60;
constexpr unsigned int desiredDelta = 1000/FPS;

static bool firstFrame = true;

Manager* manager = nullptr;
SDL_Window* window = nullptr;

//--------------------------------------------------------------------------------------------

int main(int argc, char* argv[]) {
	
	printf( "application started.\n" );
	SDL_Init( SDL_INIT_VIDEO );
	
	manager = new Manager();

	// Window is made only to enable input
	window = SDL_CreateWindow("DesignPatterns", 100, 100, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN );
	if (!window) { return 1; }

	int exitApp = 0;
	
	while (!exitApp) 
	{
		const unsigned int startLoop = SDL_GetTicks();
		
		if (firstFrame)
		{
			manager->Init();
			firstFrame = false;
		}

		// Main Tick loop
		manager->Tick();
		
		/// event loop
		/// Only updates when an event is happening
		SDL_Event event;
		while (SDL_PollEvent( &event )) 
		{
			switch (event.type)
			{
			case SDL_QUIT:
				exitApp = 1;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) 
				{
					exitApp = 1;
				}
				manager->KeyDown(event.key.keysym.sym);
			case SDL_KEYUP:
				manager->KeyUp();
				break;
			default:
				break;
			}
		}

		/// Limit the FPS of the program to the specified FPS at the top
		/// this is implemented to have control over the flow
		unsigned int delta = SDL_GetTicks() - startLoop;
		if (delta < desiredDelta)
		{
			SDL_Delay(desiredDelta - delta);
		}
	}

	// Exit program
	printf( "\napplication End." );
	manager->Shutdown();

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
