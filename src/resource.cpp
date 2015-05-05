#include "resource.hpp"

Resource::Resource(Window m, std::string s)
{
	texture = loadTexture(s, m);
	renderer = m.getRenderer();
	//int z = % 
	x=y=300;
}
