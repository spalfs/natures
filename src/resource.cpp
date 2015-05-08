#include "resource.hpp"

Resource::Resource(Window m, std::string s) //Constructor
{
	texture = loadTexture(s, m);
	renderer = m.getRenderer();

	//Initialized random position coordinates
	int yStart = rand()%800;
	int xStart = rand()%1200;
	yPosition = yStart;
	xPosition = xStart;
}

Location Resource::getLocation() //Returns resource location vector
{
	Location L(xPosition,yPosition,2);
	return L;
}
