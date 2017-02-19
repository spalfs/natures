#ifndef window_h
#define window_h

#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <GL/glew.h>

#include "constants.hpp"

class Window
{
	public:
		Window(int width, int height, const std::string& title);
                ~Window();

                void Clear();
                void swapBuffers();
                bool getClosed(){return closed;};


	private:
		SDL_Window* main;
                SDL_GLContext glContext;
                bool closed;
};

#endif
