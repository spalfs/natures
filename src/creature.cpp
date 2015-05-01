#include "creature.h"

Creature::Creature(Window m, std::string s)
{
	texture = loadTexture(s, m);
	renderer = m.getRenderer();
	x=y=500;
}
