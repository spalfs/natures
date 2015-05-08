#include "creature.hpp"

Creature::Creature(Window m, std::string s) //Constructor
{
	texture = loadTexture(s, m);
	renderer = m.getRenderer();
	health = 100;
	hunger = 0;

	//initializes random start coordinates for creature, target position is equivalent to it's position
	yPosition=yTarget=rand()%800;
	xPosition=xTarget=rand()%1200;
}

int Creature::Behavior()
{
	health-=1; //Decrements health each time a behavior is executed
	this->Priority(); //Checks which action has priority (doesn't really do this right now)

	if(this->Action())
	{
		health+=10;
		return 2;
	}
	return 0;
}

void Creature::Priority()
{
	//Traverses location vector, if object at [i] is resource (2), then creature's target coordinates are set
	int i;
	for(i=0;i<location.size();i++)
	{
		if(location[i].type==2)
		{
			xTarget = location[i].x;
			yTarget = location[i].y;
		}
	}
}

bool Creature::Action()
{
	//If the distance is close, will return an bool

	//if(xPosition == xTarget && yPosition == yTarget)
	//	return false;

	if(sqrt(pow(xPosition - xTarget, 2) + pow(yPosition - yTarget, 2)) < 2)
		return true;

	//Makes moves towards target coordinates
	if(xPosition==xTarget)
	{
		if(yPosition<yTarget)
			yPosition++;
		else
			yPosition--;
	}

	else if(yPosition==yTarget)
	{
		if(xPosition<xTarget)
			xPosition++;
		else
			xPosition--;
	}

	else if(xPosition<xTarget)
	{
		if(yPosition<yTarget)
		{
			xPosition++;
			yPosition++;
		}

		else
		{
			xPosition++;
			yPosition--;
		}
	}

	else if (xPosition>xTarget)
	{
		if(yPosition<yTarget)
		{
			xPosition--;
			yPosition++;
		}

		else
		{
			xPosition--;
			yPosition--;
		}
	}
	return false;
}

Location Creature::getLocation()
{
	//returns location object of the specific creature
	Location L(xPosition, yPosition, 1);
	return L;
}
