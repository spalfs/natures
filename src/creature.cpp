#include "creature.hpp"

Creature::Creature(Location t, Dna D)
{
    L           = t;
    mine        = D;
    
    if(L.x == 0 && L.y == 0){
        L.x = -30.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(30-(-30))));
        L.y = -30.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(30-(-30))));
    }

    gfxData.sides = 4.0;
    gfxData.x     = L.x;
    gfxData.y     = L.y;

    type            = CREATURE_TYPE;
    health          = mine.maxHealth/2;
    gender          = rand() % 2;
    age             = 0;
    pregnancyTime   = 0;
    pregnancyReady  = false;
    pregnate        = false;
    hasTarget       = false;

    if(gender){
        gfxData.r = 1.0;
        gfxData.g = 0.0;
        gfxData.b = 0.0;
    }
    else if(pregnate){
        gfxData.r = 1.0;
        gfxData.g = 0.0;
        gfxData.b = 1.0;
    }
    else{
        gfxData.r = 0.0;
        gfxData.g = 0.0;
        gfxData.b = 1.0;
    }
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
    //std::random_shuffle(N.begin(),N.end());
    for(std::list <Entity*>::iterator it = N.begin(); it!=N.end(); it++){
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
        float x = -30.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(30-(-30))));
        float y = -30.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(30-(-30))));
        Location tmp;
        tmp.x = x;
        tmp.y = y;
        wTarget = tmp;
    }
}

void Creature::checkTarget()
{
    for(std::list <Entity*>::iterator it = N.begin(); it!=N.end(); it++)
        if( target == *it )
            return;

    hasTarget = false;
}


void Creature::Action()
{	
    if(hasTarget){ 
        if( Distance(L,target->getLocation()) < mine.reach && target->getType() == RESOURCE_TYPE){
            target->eat(mine.bite);
            health+=mine.bite;
            amountAte++;
            //if(L.w <= mine.sizeMax && mine.amountToGrow <= amountAte){
            //    amountAte = 0;
            //    L.w = L.h = L.w + 1;
            //}
            if(target->getAmount()<=0)
                hasTarget = false; 
        } 
        else if( Distance(L,target->getLocation()) < mine.reach && target->getType() == CREATURE_TYPE && target->getGender() != gender ){
            target->impregnate(mine);
            hasTarget = false;
        }
        else
            moveTowards(target->getLocation());    
    }
    else if(wander){
        if(Distance(L,wTarget) < mine.reach)
            wander = false;
        else
            moveTowards(wTarget);
    }
}

void Creature::moveTowards(Location t)
{
    if( L.x == t.x ){
        if( L.y < t.y )
		    L.y+=mine.speed;
		else
			L.y-=mine.speed;
	}
	else if( L.y == t.y ){
		if( L.x < t.x )
			L.x+=mine.speed;
		else
			L.x-=mine.speed;
	}
	else if( L.x < t.x ){
		if( L.y < t.y ){
			L.x+=mine.speed;
			L.y+=mine.speed;
		}
		else{
			L.x+=mine.speed;
			L.y-=mine.speed;
		}
	}
	else if ( L.x > t.x ){
		if( L.y < t.y ){
			L.x-=mine.speed;
			L.y+=mine.speed;
		}
		else{
			L.x-=mine.speed;
			L.y-=mine.speed;
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
