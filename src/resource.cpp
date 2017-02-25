#include "resource.hpp"

Resource::Resource(Rectangle r)
{	
        rect = r;

        if(rect.x == 0 && rect.y == 0){
                rect.x = getRandom(30);
                rect.y = getRandom(30);
        }

        gfxData = GraphicsData(rect.x, rect.y, 0, 1, 0, RESOURCE_SIDES);

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
