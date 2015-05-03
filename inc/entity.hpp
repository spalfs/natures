#ifndef entity_h
#define entity_h

#include "window.hpp"

class Entity
{
	public:
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
