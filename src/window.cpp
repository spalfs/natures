#include "window.h"

Window::Window()
{
	SDL_Init(SDL_INIT_VIDEO);
	main = SDL_CreateWindow("main",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1280,800,SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(main,-1,SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
};

void Window::Destroy()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(main);
	SDL_Quit();
};

void Window::Clear()
{
	SDL_RenderClear(renderer);
};

void Window::Render()
{
	SDL_RenderPresent(renderer);
};

SDL_Renderer* Window::getRenderer()
{
	return renderer;
};
