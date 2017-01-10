#include "entity.hpp"

void Entity::Init(Window m)
{
    renderer = m.getRenderer();
    rect.y = rand()%640;
    rect.x = rand()%1080;
}

void Entity::Init(Window m, Location z)
{
    renderer = m.getRenderer();
    rect.y = z.y;
    rect.x = z.x;
}

void Entity::Place()
{
    if(type == 1)
        SDL_SetRenderDrawColor(renderer,255,0,255,255);
    else
        SDL_SetRenderDrawColor(renderer,0,255,0,255);

    SDL_RenderDrawRect(renderer, &rect);
    
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
}
