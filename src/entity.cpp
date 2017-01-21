#include "entity.hpp"

void Entity::Place()
{
    if(type == CREATURE_TYPE){
        if(gender)
            SDL_SetRenderDrawColor(renderer,255,0,0,255);
        else
            if(pregnate)
                SDL_SetRenderDrawColor(renderer,255,0,255,255);
            else
                SDL_SetRenderDrawColor(renderer,0,0,255,255);
    }
    else if (type == RESOURCE_TYPE)
        SDL_SetRenderDrawColor(renderer,0,255,0,255);

    SDL_RenderFillRect(renderer, &rect);
    
    SDL_SetRenderDrawColor(renderer,0,0,0,0);
}
