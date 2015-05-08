#include "resource.hpp"

Resource::Resource(Window m, std::string s) //Constructor
{
	texture = loadTexture(s, m);
	renderer = m.getRenderer();

	//Initialized random position coordinates
	yPosition = rand()%800;
	xPosition = rand()%1200;

	amount = 100;
}

Resource::Resource(Window m, std::string s, Location z)
{
	texture = loadTexture(s, m);
	renderer = m.getRenderer();

	yPosition = z.y;
	xPosition = z.x;

	amount = 100;
}

Location Resource::getLocation() //Returns resource object
{
	Location L(xPosition,yPosition,2);
	return L;
}
