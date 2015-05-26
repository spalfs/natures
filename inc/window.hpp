#ifndef window_h
#define window_h

//Theres alot here that are probs not used needs cleaning
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;

class Window
{
	public:
		Window();
		Window(std::string){};
		void Destroy();

		void Clear();
		void Render();
		SDL_Renderer* getRenderer();

	private:
		SDL_Window* main;
		SDL_Renderer* renderer;
};

#endif
