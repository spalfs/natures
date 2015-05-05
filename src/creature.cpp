#include "creature.hpp"

Creature::Creature(Window m, std::string s)
{
	texture = loadTexture(s, m);
	renderer = m.getRenderer();

	srand(time(NULL));
	int z = rand()%800;
	y=z;

	z = rand()%800;
	x=z;
	std::cout << x << ' ' <<  y << std::endl;

	//For the test resource
	xT=yT=300;
}

void Creature::Behavior()
{
  //Detection

  //Priorities

  //Action
  this->Action();
}

void Creature::Action()
{
	//std::cout << (sqrt(((x-xT)^2)+((y-yT)^2));
	if((sqrt(((x-xT)^2)+((y-yT)^2)))<2)
		return; //eat//reproduce//etc;

	if(x==xT)
		if(y<yT)
			y++;
		else
			y--;
	else if(y==yT)
		if(x<xT)
			x++;
		else
			x--;
	else
	{
		int z = rand()%2;
		if(z)
		{
			if(x<xT)
				x++;
			else
				x--;
		}
		else
		{
			if(y<xT)
				y++;
			else
				y--;
		}
	}
}
