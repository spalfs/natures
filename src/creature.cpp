#include "creature.hpp"

Creature::Creature(Window M, SDL_Rect R, Dna D)
{
    renderer    = M.getRenderer();
    rect        = R; 
    mine        = D;
    
    if(rect.x == 0 && rect.y == 0){
        rect.x  = rand()%WINDOW_X;
        rect.y  = rand()%WINDOW_Y;
    }

    type            = CREATURE_TYPE;
    health          = mine.maxHealth/2;
    gender          = rand() % 2;
    age             = 0;
    pregnancyTime   = 0;
    pregnancyReady  = false;
    pregnate        = false;
    hasTarget       = false;
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
        if(pregnancyTime > mine.expectedPregnancyTime)
            pregnancyReady = true;
    }

    age++;
    if(age > mine.expectedAge)
        health = 0;
}

void Creature::Priority()
{	 
    if(health < mine.maxHealth / 2){
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
    std::random_shuffle(N.begin(),N.end());
    for(std::vector <Entity*>::iterator it = N.begin(); it!=N.end(); it++){
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
    for(std::vector <Entity*>::iterator it = N.begin(); it!=N.end(); it++)
        if( target == *it )
            return;

    hasTarget = false;
}


void Creature::Action()
{	
    if(hasTarget){ 
        if( Distance(rect,target->getRect()) < mine.reach && target->getType() == RESOURCE_TYPE){
            target->eat(mine.bite);
            health+=mine.bite;
            amountAte++;
            if(rect.w <= mine.sizeMax && mine.amountToGrow <= amountAte){
                amountAte = 0;
                rect.w = rect.h = rect.w + 1;
            }
            if(target->getAmount()<=0)
                hasTarget = false; 
        } 
        else if( Distance(rect,target->getRect()) < mine.reach && target->getType() == CREATURE_TYPE && target->getGender() != gender ){
            target->impregnate(mine);
            hasTarget = false;
        }
        else
            moveTowards(target->getRect());    
    }
    else if(wander){
        if(Distance(rect,wTarget) < mine.reach)
            wander = false;
        else
            moveTowards(wTarget);
    }
}

void Creature::moveTowards(SDL_Rect R)
{
    if( rect.x == R.x ){
        if( rect.y < R.y )
		    rect.y+=mine.speed;
		else
			rect.y-=mine.speed;
	}
	else if( rect.y == R.y ){
		if( rect.x < R.x )
			rect.x+=mine.speed;
		else
			rect.x-=mine.speed;
	}
	else if( rect.x < R.x ){
		if( rect.y < R.y ){
			rect.x+=mine.speed;
			rect.y+=mine.speed;
		}
		else{
			rect.x+=mine.speed;
			rect.y-=mine.speed;
		}
	}
	else if ( rect.x > R.x ){
		if( rect.y < R.y ){
			rect.x-=mine.speed;
			rect.y+=mine.speed;
		}
		else{
			rect.x-=mine.speed;
			rect.y-=mine.speed;
		}
	}
}

void Creature::impregnate(Dna D)
{
    if(!pregnate){
        pregnate = true;
        pregnancyTime = 0;
        childs = mine.combine(D);
    }
}
