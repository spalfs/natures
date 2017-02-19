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
        void Clear(float r, float g, float b, float a);
        void swapBuffers();
        bool getClosed(){return closed;};

        virtual ~Window();

	private:
		SDL_Window* main;
        SDL_GLContext glContext;
        bool closed;
};

#endif
