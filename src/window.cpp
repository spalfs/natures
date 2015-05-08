#include "window.hpp"

Window::Window() //Constructor
{
	SDL_Init(SDL_INIT_VIDEO);
	main = SDL_CreateWindow("main",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1280,800,SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(main,-1,SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}

void Window::Destroy() //Kills window
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(main);
	SDL_Quit();
}

void Window::Clear() //Clears renderer
{
	SDL_RenderClear(renderer);
}

void Window::Render() //Brings image forward
{
	SDL_RenderPresent(renderer);
}

SDL_Renderer* Window::getRenderer()
{
	return renderer;
}
