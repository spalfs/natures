#include "creature.hpp"

Creature::Creature(Window m, std::string s)
{
	texture = loadTexture(s, m);
	renderer = m.getRenderer();
	hp = 100;
	hu = 0;

	int zy = rand()%800;
	int zx = rand()%1200;
	y=yT=zy;
	x=xT=zx;
	//std::cout << x << ' ' <<  y << std::endl;

	//For the test resource
	//xT=yT=300;
}

void Creature::Behavior()
{
	hp--;
  //Detection

  //Priorities
	this->Priority();
  //Action
  this->Action();
}

void Creature::Action()
{
	//std::cout << (sqrt(((x-xT)^2)+((y-yT)^2));
	if(sqrt(pow(x-xT,2)+pow(y-yT,2))<2)
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

void Creature::Priority()
{
	int i;
	for(i=0;i<K.size();i++)
	{
		std::cout << K[i].t;
		if(K[i].t==2)
		{
			xT = K[i].x;
			yT = K[i].y;
			std::cout << xT << "IN\n";
		}
	}
}

Location Creature::getLocation()
{
	Location L(x,y,1);
	return L;
}
