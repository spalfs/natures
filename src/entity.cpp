#include "entity.hpp"

void Entity::Place()
{
    if(type == 1)
        SDL_SetRenderDrawColor(renderer,255,0,255,255);
    else
        SDL_SetRenderDrawColor(renderer,0,255,0,255);

    SDL_RenderFillRect(renderer, &rect);
    
    SDL_SetRenderDrawColor(renderer,0,0,0,0);
}
