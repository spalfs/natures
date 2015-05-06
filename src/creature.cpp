#include "creature.hpp"

Creature::Creature(Window m, std::string s)
{
	texture = loadTexture(s, m);
	renderer = m.getRenderer();
	hp = 100;
	hu = 0;

	int zy = rand()%800;
	int zx = rand()%1200;
	y=zy;
	x=zx;
	//std::cout << x << ' ' <<  y << std::endl;
	
	//For the test resource
	xT=yT=300;
}

void Creature::Behavior()
{
	hp--;
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
	{
		if(y<yT)
			y++;
		else
			y--;
	}
	else if(y==yT)
	{
		if(x<xT)
			x++;
		else
			x--;
	}
	else if(x<xT)
	{
		if(y<yT)
		{
			x++;
			y++;
		}
		else
		{
			x++;
			y--;
		}
	}
	else if (x>xT)
	{
		if(y<yT)
		{
			x--;
			y++;
		}
		else
		{
			x--;
			y--;
		}
	}



	/*	
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
			if(y<yT)
				y++;
			else
				y--;
		}
	}
	*/
}

Location Creature::getLocation()
{
	Location L(x,y,1);
	return L;
}
