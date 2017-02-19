#include "resource.hpp"

Resource::Resource(Location t)
{	
    L        = t;
    
    if(L.x == 0 && L.y == 0){
        L.x  = -30 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(30.0-(-30.0))));
        L.y  = -30 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(30.0-(-30.0))));
    }

    gfxData.x = L.x;
    gfxData.y = L.y;
    gfxData.r = 0.0;
    gfxData.g = 1.0;
    gfxData.b = 0.0;
    gfxData.sides = 10.0;

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
        L.h = L.w = map(amount,0,RESOURCE_AMOUNT_MAX,0,RESOURCE_SIZE_MAX);
    }
}
