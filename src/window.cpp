#include "sdl/window.hpp"

Window::Window(int width, int height, const std::string& title) 
{
        SDL_Init(SDL_INIT_EVERYTHING);

        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        main            = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_OPENGL);
        glContext       = SDL_GL_CreateContext(main);
        SDL_GL_SetSwapInterval(0);
        GLenum status   = glewInit();
        closed          = false;

        if(status != GLEW_OK)
                std::cerr << "Failiure to init." << std::endl;
}

Window::~Window()
{
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(main);
	SDL_Quit();
}

void Window::swapBuffers()
{
        SDL_GL_SwapWindow(main);
}

void Window::Clear() 
{
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
}

