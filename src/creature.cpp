#include "creature.hpp"

Creature::Creature(Window m, std::string s) //Constructor
{
	texture = loadTexture(s, m);
	renderer = m.getRenderer();
	health = 100;
	hunger = 0;

	//initializes random start coordinates for creature, target position is equivalent to it's position
	int yStart = rand()%800;
	int xStart = rand()%1200;
	yPosition=yTarget=yStart;
	xPosition=xTarget=xStart;
}

void Creature::Behavior()
{
	health--; //Decrements health each time a behavior is executed
  //Detection
	this->Priority(); //Checks which action has priority (doesn't really do this right now)
  this->Action(); //Does action
}

void Creature::Priority()
{
	//Traverses location vector, if object at [i] is resource (2), then creature's target coordinates are set
	int i;
	for(i=0;i<location.size();i++)
	{
		std::cout << location[i].type;
		if(location[i].type==2)
		{
			xTarget = location[i].x;
			yTarget = location[i].y;
			std::cout << xTarget << "IN\n";
		}
	}
}

void Creature::Action()
{
	//If the distance is too small, do something?
	if(sqrt(pow(xPosition - xTarget, 2) + pow(yPosition - yTarget, 2)) < 2)
		return; //<--- eat action should be here

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
}

Location Creature::getLocation()
{
	//returns location vector of creatures position coordinates
	Location L(xPosition, yPosition, 1);
	return L;
}
