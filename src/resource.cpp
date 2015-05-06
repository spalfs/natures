#include "resource.hpp"

Resource::Resource(Window m, std::string s)
{
	texture = loadTexture(s, m);
	renderer = m.getRenderer();
	int zy = rand()%800;
	int zx = rand()%1200;
	y=zy;
	x=zx;
}

Location Resource::getLocation()
{
	Location L(x,y,2);
	return L;
}
