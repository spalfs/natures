#include "resource.hpp"

Resource::Resource(Window M, SDL_Rect R)
{	
    renderer    = M.getRenderer();
    rect        = R;
    
    if(rect.x == 0 && rect.y == 0){
        rect.x  = rand()%WINDOW_X;
        rect.y  = rand()%WINDOW_Y;
    }

    type        = RESOURCE_TYPE;
	amount      = RESOURCE_AMOUNT_START;
    growAmount  = RESOURCE_GROW;
}

void Resource::eat(int bite)
{
	amount-=bite;
}

void Resource::grow()
{
    if(amount < RESOURCE_AMOUNT_MAX){
        amount+=growAmount; 
        rect.h = rect.w = map(amount,0,RESOURCE_AMOUNT_MAX,0,RESOURCE_SIZE_MAX);
    }
}
