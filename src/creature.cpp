#include "creature.hpp"

Creature::Creature(Window m, SDL_Rect R)
{
    renderer                = m.getRenderer();
    rect                    = R; 
    
    if(rect.x == 0 && rect.y == 0){
        rect.x              = rand()%WINDOW_X;
        rect.y              = rand()%WINDOW_Y;
    }

    type                    = CREATURE_TYPE;
    health                  = CREATURE_START_HEALTH;
    maxHealth               = CREATURE_MAX_HEALTH;
    reach                   = CREATURE_REACH;
    speed                   = CREATURE_SPEED;
    bestSense               = CREATURE_BEST_SENSE;
    bite                    = CREATURE_BITE;
    amountToGrow            = CREATURE_AMOUNT_TO_GROW;
    expectedPregnancyTime   = CREATURE_EXPECTED_PREGNANCY_TIME;

    gender                  = rand() % 2;
    hungry                  = false;
    hasTarget               = false;
    wander                  = false;
    pregnate                = false;
    pregnancyReady          = false;
    able                    =  true;
}

void Creature::Behavior()
{
	health-=1; 

	this->Priority();

    if(!hasTarget)
        this->setTarget();
    else
        this->checkTarget();

	this->Action();

    if(pregnate){
        pregnancyTime++;
        if(pregnancyTime > expectedPregnancyTime)
            pregnancyReady = true;
    }

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
        if( (*it)->getType() == RESOURCE_TYPE && hungry){ 
            target = *it;
            hasTarget = true;
            wander = false;
            break;
        } 
        if( (*it)->getType() == CREATURE_TYPE && able && (*it)->getGender() != gender ){
            target = *it;
            hasTarget = true;
            wander = false;
            break;
        }       
    }

    if(!hasTarget&&!wander){
        wander = true;
        SDL_Rect r = {rand() % WINDOW_X, rand() % WINDOW_Y, 0, 0};
        wTarget = r;
    }
}

void Creature::checkTarget()
{
    for(list <Entity*>::iterator it = N.begin(); it!=N.end(); it++)
        if( target == *it )
            return;
    
    hasTarget = false;
    return;
}


void Creature::Action()
{	
    if(hasTarget){ 
        if( Distance(rect,target->getRect()) < reach && target->getType() == RESOURCE_TYPE){
            target->eat(bite);
            health+=bite;
            amountAte++;
            if(rect.w <= CREATURE_SIZE_MAX && amountToGrow <= amountAte){
                amountAte = 0;
                rect.w = rect.h = rect.w + 1;
            }
            if(target->getAmount()<=0)
                hasTarget = false; 
        } 
        else if( Distance(rect,target->getRect()) < reach && target->getType() == CREATURE_TYPE && target->getGender() != gender ){
            target->impregnate();
            hasTarget = false;
        }
        else
            Move(target->getRect());    
    }
    else if(wander){
        if(Distance(rect,wTarget) < reach)
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

void Creature::impregnate()
{
    if(!pregnate){
        pregnate = true;
        pregnancyTime = 0;
    }
}
