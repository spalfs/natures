#ifndef entity_h
#define entity_h

#include "window.h"

class Entity
{
	public:
		Entity(Window m, std::string s);
		void Place();
		SDL_Texture* loadTexture(std::string path, Window main);

	protected:
		int x, y;
		int height, width;
		int degrees = 0;
		SDL_Texture* texture;
		SDL_Renderer* renderer;
};

#endif
