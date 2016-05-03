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
	able = true;
}

void Creature::Behavior()
{
	health-=1; 

	this->Priority();

	this->Action();
}

void Creature::Priority()
{	
    for(list <Entity*>::iterator it = N.begin(); it!=N.end(); it++){
       if((*it)->getType() == 2){ 
           if(!hasTarget){
                target = *it;
                hasTarget = true; 
           }
           else
               break;
       }
    }
}

void Creature::Action()
{	
    //cout << "My coords:" << L.x << "," << L.y << endl; 
    cout << "Mytcoords:" << target->getLocation().x << "," << target->getLocation().y << endl << endl; 

	if(hasTarget){ 
        if(Distance(L,target->getLocation())<5){
            target->eat();
            health+=1000; 
        }
        if(target->getAmount()==0){
            hasTarget = false;
            cout << "done\n";
        }
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
