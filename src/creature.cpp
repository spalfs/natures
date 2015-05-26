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
	hasTarget = false;
	n=0;
}

int Creature::Behavior()
{
	health-=1; //Decrements health each time a behavior is executed

	this->Priority();

	if(this->Action())
	{
		if(nR.size())
		{
			nR[n]->eat();
			if(health<500)
				health+=10;
		}
	}

	return 0;
}

void Creature::Priority()
{
	double d; // lol

	for(int i = 0; i < nR.size(); i++)
	{
		if(!i)
			d = Distance(this->getLocation(),nR[0]->getLocation());

		if(d>Distance(this->getLocation(),nR[i]->getLocation()))
		{
			d=Distance(this->getLocation(),nR[i]->getLocation());
			n=i;
		}
	}

	if(nR.size())
	{
		xTarget = nR[n]->getLocation().x;
		yTarget = nR[n]->getLocation().y;
		hasTarget = true;
	}
	else
		hasTarget = false;
}

bool Creature::Action()
{
	//If the distance is close, will return an bool
	//if(xPosition == xTarget && yPosition == yTarget)
	//	return false;

	if(nR.size())
		if(5 > Distance(this->getLocation(),nR[n]->getLocation()))
		{
			if(hasTarget)
				return true;
			else
				return false;
		}

	//Makes moves towards target coordinates
	if(xPosition==xTarget)
	{
		if(yPosition<yTarget)
			yPosition+=speed;
		else
			yPosition-=speed;
	}

	else if(yPosition==yTarget)
	{
		if(xPosition<xTarget)
			xPosition+=speed;
		else
			xPosition-=speed;
	}

	else if(xPosition<xTarget)
	{
		if(yPosition<yTarget)
		{
			xPosition+=speed;
			yPosition+=speed;
		}

		else
		{
			xPosition+=speed;
			yPosition-=speed;
		}
	}

	else if (xPosition>xTarget)
	{
		if(yPosition<yTarget)
		{
			xPosition-=speed;
			yPosition+=speed;
		}

		else
		{
			xPosition-=speed;
			yPosition-=speed;
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

double Creature::Distance(Location A, Location B)
{
  //computes distance between two points
  return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}
