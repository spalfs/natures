#ifndef window_h
#define window_h

#include <SDL2/SDL.h>
#include <algorithm>

#include "constants.hpp"

using namespace std;

class Window
{
	public:
		Window();
		Window(string){};
		void Destroy();

		void Clear();
		void Render();
		SDL_Renderer* getRenderer();

	private:
		SDL_Window* main;
		SDL_Renderer* renderer;
};

#endif
