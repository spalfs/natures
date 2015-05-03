#include "resource.hpp"

Resource::Resource(Window m, std::string s)
{
	texture = loadTexture(s, m);
	renderer = m.getRenderer();
	x=y=300;
}
