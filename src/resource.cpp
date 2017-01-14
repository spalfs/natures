#include "resource.hpp"

Resource::Resource(Window m, SDL_Rect R)
{	
    renderer = m.getRenderer();
    type = 2;
    rect = R;
    
    if(rect.x == 0 && rect.y == 0){
        rect.x = rand()%WINDOW_X;
        rect.y = rand()%WINDOW_Y;
    }

	amount = RESOURCE_AMOUNT;
}

void Resource::eat()
{
	amount-=10;
}
