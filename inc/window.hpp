#ifndef window_h
#define window_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

class Window
{
	public:
		Window();
		void Destroy();

		void Clear();
		void Render();
		SDL_Renderer* getRenderer();

	private:
		SDL_Window* main;
		SDL_Renderer* renderer;
};

#endif
