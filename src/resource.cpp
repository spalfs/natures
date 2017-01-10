#include "resource.hpp"

Resource::Resource(Window m, int size)
{	
    Init(m);
    type = 2;

    rect.h = rect.w = size;
    
    L.x = rect.x;
    L.y = rect.y;

	amount = 100;
}

Resource::Resource(Window m, int size, Location z)
{
    Init(m,z);
    type = 2;
    
    rect.h = rect.w = size;
    
    L.x = rect.x;
    L.y = rect.y;

    amount = 200;
}

void Resource::eat()
{
	amount-=10;
}
