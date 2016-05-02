#include "entity.hpp"

void Entity::Place()
{
	SDL_Rect rect = {L.x, L.y, width/8, height/8};
	SDL_RenderCopyEx(renderer,texture,NULL,&rect,degrees,NULL,SDL_FLIP_NONE);
}

SDL_Texture* Entity::loadTexture(string path, Window main)
{
	SDL_Surface* surface = IMG_Load(path.c_str());
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 255, 255));
	height = surface->h;
	width = surface->w;
	SDL_Texture* texture = SDL_CreateTextureFromSurface(main.getRenderer(),surface);
	SDL_FreeSurface(surface);
	return texture;
}
