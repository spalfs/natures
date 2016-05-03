#include "creature.hpp"

Creature::Creature(Window m, std::string s)
{
	texture = loadTexture(s, m);
	renderer = m.getRenderer();
	health = 500;
	maxHealth = 1000;
	hunger = 0;

	L.y=rand()%800;
	L.x=rand()%1200;
    type = 1;

    hasTarget = false;
	wandering = false;
	able = true;
	n=0;
}

void Creature::Behavior()
{
	//health-=1; 

	this->Priority();

	this->Action();
}

void Creature::Priority()
{	
    for(vector <Entity*>::iterator it = N.begin(); it!=N.end(); it++){
       if((*it)->getType() == 2){
           if(!hasTarget){
                target = *it;
                wandering = false;
                hasTarget = true; 
           }
           else
               break;
       }
    }
}

void Creature::Action()
{	

	if(hasTarget){ 
        if(Distance(L,target->getLocation())<5){
            target->eat();
            health+=1000; 
        }
        if(target->getAmount()==0)
            hasTarget = false;
    } 

	//Makes moves towards target coordinates
	if(L.x==target->getLocation().x)
	{
		if(L.y<target->getLocation().y)
			L.y+=speed;
		else
			L.y-=speed;
	}

	else if(L.y==target->getLocation().y)
	{
		if(L.x<target->getLocation().x)
			L.x+=speed;
		else
			L.x-=speed;
	}

	else if(L.x<target->getLocation().x)
	{
		if(L.y<target->getLocation().y)
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

	else if (L.x>target->getLocation().x)
	{
		if(L.y<target->getLocation().y)
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
}
