#include "creature.hpp"

Creature::Creature(Rectangle t, DNA D)
{
    L           = t;
    myDNA        = D;
    
    if(L.x == 0 && L.y == 0){
        L.x = -30.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(30-(-30))));
        L.y = -30.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(30-(-30))));
    }

    gfxData.sides = 4.0;
    gfxData.x     = L.x;
    gfxData.y     = L.y;

    type            = CREATURE_TYPE;
    health          = myDNA.maxHealth/2;
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
        if(pregnancyTime > myDNA.expectedPregnancyTime)
            pregnancyReady = true;
    }

    age++;
    if(age > myDNA.expectedAge)
        health = 0;
}

void Creature::Priority()
{	 
    if(health < myDNA.maxHealth / 2){
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
    for(std::list <Entity*>::iterator it = nearMe.begin(); it!=nearMe.end(); it++){
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
        Rectangle tmp;
        tmp.x = x;
        tmp.y = y;
        wTarget = tmp;
    }
}

void Creature::checkTarget()
{
    for(std::list <Entity*>::iterator it = nearMe.begin(); it!=nearMe.end(); it++)
        if( target == *it )
            return;

    hasTarget = false;
}


void Creature::Action()
{	
    if(hasTarget){ 
        if( Distance(L,target->getRectangle()) < myDNA.reach && target->getType() == RESOURCE_TYPE){
            target->eat(myDNA.bite);
            health+=myDNA.bite;
            amountAte++;
            //if(L.w <= myDNA.sizeMax && myDNA.amountToGrow <= amountAte){
            //    amountAte = 0;
            //    L.w = L.h = L.w + 1;
            //}
            if(target->getAmount()<=0)
                hasTarget = false; 
        } 
        else if( Distance(L,target->getRectangle()) < myDNA.reach && target->getType() == CREATURE_TYPE && target->getGender() != gender ){
            target->impregnate(myDNA);
            hasTarget = false;
        }
        else
            moveTowards(target->getRectangle());    
    }
    else if(wander){
        if(Distance(L,wTarget) < myDNA.reach)
            wander = false;
        else
            moveTowards(wTarget);
    }
}

void Creature::moveTowards(Rectangle t)
{
    if( L.x == t.x ){
        if( L.y < t.y )
		    L.y+=myDNA.speed;
		else
			L.y-=myDNA.speed;
	}
	else if( L.y == t.y ){
		if( L.x < t.x )
			L.x+=myDNA.speed;
		else
			L.x-=myDNA.speed;
	}
	else if( L.x < t.x ){
		if( L.y < t.y ){
			L.x+=myDNA.speed;
			L.y+=myDNA.speed;
		}
		else{
			L.x+=myDNA.speed;
			L.y-=myDNA.speed;
		}
	}
	else if ( L.x > t.x ){
		if( L.y < t.y ){
			L.x-=myDNA.speed;
			L.y+=myDNA.speed;
		}
		else{
			L.x-=myDNA.speed;
			L.y-=myDNA.speed;
		}
	}
}

void Creature::impregnate(DNA D)
{
    if(!pregnate){
        pregnate = true;
        pregnancyTime = 0;
        childsDNA = myDNA.combine(D);
    }
}
