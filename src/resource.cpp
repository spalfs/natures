#include "resource.hpp"

Resource::Resource(Window m, int size)
{	
    Init(m);
    type = 2;

    rect.h = rect.w = size;
    
    L.x = rect.x;
    L.y = rect.y;

	amount = RESOURCE_AMOUNT;
}

Resource::Resource(Window m, int size, Location z)
{
    Init(m,z);
    type = 2;
    
    rect.h = rect.w = size;
    
    L.x = rect.x;
    L.y = rect.y;

    amount = RESOURCE_AMOUNT;
}

void Resource::eat()
{
	amount-=10;
}
