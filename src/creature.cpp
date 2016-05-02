#include "creature.hpp"

Creature::Creature(Window m, std::string s)
{
	texture = loadTexture(s, m);
	renderer = m.getRenderer();
	health = 500;
	maxHealth = 1000;
	hunger = 0;

	L.y=yTarget=rand()%800;
	L.x=xTarget=rand()%1200;
	
    hasTarget = false;
	wandering = false;
	able = true;
	n=0;
}

int Creature::Behavior()
{
	health-=1;

	this->Priority();

	if(this->Action())
	{
		if(nR.size())
		{
			nR[n]->eat();
			if(health<maxHealth)
				health+=10;
		}
	}

	return 0;
}

void Creature::Priority()
{
	double d;

	// Gets location for closest resource
	for(int i = 0; i < nR.size(); i++)
	{
		if(i==0)
		{
			d = Distance(this->getLocation(),nR[0]->getLocation());
			n = 0;
			continue;
		}

		if(d>Distance(this->getLocation(),nR[i]->getLocation()))
		{
			d=Distance(this->getLocation(),nR[i]->getLocation());
			n=i;
		}
	}

	if(nR.size()==0)
		hasTarget=false;

	// If there is available targets and the unit doesnt have a target, assign the closest one.
	//cout << "size: " << nR.size() << endl;
	//cout << "hastarget: "<< hasTarget << endl;
	if(nR.size()>0&&!hasTarget)
	{
		xTarget = nR[n]->getLocation().x;
		yTarget = nR[n]->getLocation().y;
		hasTarget = true;
		wandering = false;
	}
	// If there is not available targets and doesnt have a target, set a random location as a target
	else if(nR.size()==0&&!hasTarget)
	{
		if(!wandering)
		{
			xTarget = rand()%1200;
			yTarget = rand()%800;
			wandering = true;
			hasTarget = false;
		}
		else
		{
			Location L(xTarget,yTarget,1);
			if(Distance(this->getLocation(),L)<5)
				wandering = false;
			hasTarget = false;
		}
	}
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
			{
				hasTarget = false;
				return true;
			}
			else
				return false;
		}

	//Makes moves towards target coordinates
	if(L.x==xTarget)
	{
		if(L.y<yTarget)
			L.y+=speed;
		else
			L.y-=speed;
	}

	else if(L.y==yTarget)
	{
		if(L.x<xTarget)
			L.x+=speed;
		else
			L.x-=speed;
	}

	else if(L.x<xTarget)
	{
		if(L.y<yTarget)
		{
			L.x+=speed;
			L.y+=speed;
		}

		else
		{
			L.x+=speed;
			L.y-=speed;
		}
	}

	else if (L.x>xTarget)
	{
		if(L.y<yTarget)
		{
			L.x-=speed;
			L.y+=speed;
		}

		else
		{
			L.x-=speed;
			L.y-=speed;
		}
	}

	return false;
}

Location Creature::getLocation()
{
	//returns location object of the specific creature
	//Location L(xPosition, yPosition, 1);
	return L;
}


