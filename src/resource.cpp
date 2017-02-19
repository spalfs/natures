#include "resource.hpp"

Resource::Resource(Rectangle t)
{	
        rect = t;

        if(rect.x == 0 && rect.y == 0){
                rect.x = getRandom(50);
                rect.y = getRandom(50);
        }

        gfxData.x       = rect.x;
        gfxData.y       = rect.y;
        gfxData.r       = 0.0;
        gfxData.g       = 1.0;
        gfxData.b       = 0.0;
        gfxData.sides   = 10.0;

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
