#include "creature.hpp"

Creature::Creature(Window m, SDL_Rect R)
{
    renderer = m.getRenderer();
    type = 1;
    rect = R; 
    
    if(rect.x == 0 && rect.y == 0){
        rect.x = rand()%WINDOW_X;
        rect.y = rand()%WINDOW_Y;
    }

    health      = CREATURE_START_HEALTH;
	maxHealth   = CREATURE_MAX_HEALTH;
    reach       = CREATURE_REACH;
    speed       = CREATURE_SPEED;
    bestSense   = CREATURE_BEST_SENSE;

    hungry      = false;
    hasTarget   = false;
	wander      = false;
    able        = true;
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
    if(hasTarget)
        return;

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
        SDL_Rect r = {rand()%WINDOW_X, rand()%WINDOW_Y, 0, 0};
        wTarget = r; 
    }
}


void Creature::Action()
{	
	if(hasTarget){ 
        if(Distance(rect,target->getRect())<reach){
            target->eat();
            health+=10; 
        }
        else
            Move(target->getRect());

        if(target->getAmount()<=0){
            hasTarget = false; 
        }
    }
    else{
        if(Distance(rect,wTarget)<5)
            wander = false;
        else
            Move(wTarget);
    }
}

void Creature::Move(SDL_Rect R)
{
    if( rect.x == R.x ){
        if( rect.y < R.y )
		    rect.y+=speed;
		else
			rect.y-=speed;
	}
	else if( rect.y == R.y ){
		if( rect.x < R.x )
			rect.x+=speed;
		else
			rect.x-=speed;
	}
	else if( rect.x < R.x ){
		if( rect.y < R.y ){
			rect.x+=speed;
			rect.y+=speed;
		}
		else{
			rect.x+=speed;
			rect.y-=speed;
		}
	}
	else if ( rect.x > R.x ){
		if( rect.y < R.y ){
			rect.x-=speed;
			rect.y+=speed;
		}
		else{
			rect.x-=speed;
			rect.y-=speed;
		}
	}
}
