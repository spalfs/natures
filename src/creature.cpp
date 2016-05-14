#include "creature.hpp"

Creature::Creature(Window m, std::string s)
{
	texture = loadTexture(s, m);
	renderer = m.getRenderer();
	health = 500;
	maxHealth = 1000;

	L.y=rand()%800;
	L.x=rand()%1200;
    type = 1;

    hungry = false;
    hasTarget = false;
	wander = false;
    able = true;
}

void Creature::Behavior()
{
	health-=1; 

	this->Priority();

    this->setTarget();

	this->Action();
}

void Creature::Priority()
{	 
    if(health < maxHealth/2){
        hungry = true;
        able = false;
    }
    else{
        hungry = false;
        able = true;
    }
}

void Creature::setTarget()
{
    for(list <Entity*>::iterator it = N.begin(); it!=N.end(); it++){
       if((*it)->getType() == 2 && hungry){ 
           if(!hasTarget){
                target = *it;
                hasTarget = true; 
                wander = false;
           }
           else
               break;
       }
    }

    if(!hasTarget&&!wander){
        wander = true;
        wTarget = Location(rand()%1200,rand()%800);
    }
}


void Creature::Action()
{	
	if(hasTarget){ 
        if(Distance(L,target->getLocation())<5){
            target->eat();
            health+=10; 
        }
        else
            Move(target->getLocation());

        if(target->getAmount()<=0){
            hasTarget = false; 
        }
    }
    else{
        if(Distance(L,wTarget)<5)
            wander = false;
        else
            Move(wTarget);
    }
}

void Creature::Move(Location l)
{
    if( L.x == l.x ){
        if( L.y < l.y )
		    L.y+=speed;
		else
			L.y-=speed;
	}
	else if( L.y == l.y ){
		if( L.x < l.x )
			L.x+=speed;
		else
			L.x-=speed;
	}
	else if( L.x < l.x ){
		if( L.y < l.y ){
			L.x+=speed;
			L.y+=speed;
		}
		else{
			L.x+=speed;
			L.y-=speed;
		}
	}
	else if ( L.x > l.x ){
		if( L.y < l.y ){
			L.x-=speed;
			L.y+=speed;
		}
		else{
			L.x-=speed;
			L.y-=speed;
		}
	}
}
