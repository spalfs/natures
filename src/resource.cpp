#include "resource.hpp"

Resource::Resource(Window m, std::string s)
{
	texture = loadTexture(s, m);
	renderer = m.getRenderer();

	L.y = rand()%800;
	L.x = rand()%1200;
    L.type = 2;

	amount = 100;
}

Resource::Resource(Window m, std::string s, Location z)
{
	texture = loadTexture(s, m);
	renderer = m.getRenderer();

	L.y = z.y;
	L.x = z.x;
    L.type = 2;
	
    amount = 100;
}

void Resource::eat()
{
	amount-=10;
}
