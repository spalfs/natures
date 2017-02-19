#include "creature.hpp"

Creature::Creature(Rectangle t, DNA D)
{
    rect           = t;
    myDNA        = D;
    
    if(rect.x == 0 && rect.y == 0){
        rect.x = -30.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(30-(-30))));
        rect.y = -30.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(30-(-30))));
    }

    gfxData.sides = 4.0;
    gfxData.x     = rect.x;
    gfxData.y     = rect.y;

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
        if( Distance(rect,target->getRectangle()) < myDNA.reach && target->getType() == RESOURCE_TYPE){
            target->eat(myDNA.bite);
            health+=myDNA.bite;
            amountAte++;
            //if(rect.w <= myDNA.sizeMax && myDNA.amountToGrow <= amountAte){
            //    amountAte = 0;
            //    rect.w = rect.h = rect.w + 1;
            //}
            if(target->getAmount()<=0)
                hasTarget = false; 
        } 
        else if( Distance(rect,target->getRectangle()) < myDNA.reach && target->getType() == CREATURE_TYPE && target->getGender() != gender ){
            target->impregnate(myDNA);
            hasTarget = false;
        }
        else
            moveTowards(target->getRectangle());    
    }
    else if(wander){
        if(Distance(rect,wTarget) < myDNA.reach)
            wander = false;
        else
            moveTowards(wTarget);
    }
}

void Creature::moveTowards(Rectangle t)
{
    if( rect.x == t.x ){
        if( rect.y < t.y )
		    rect.y+=myDNA.speed;
		else
			rect.y-=myDNA.speed;
	}
	else if( rect.y == t.y ){
		if( rect.x < t.x )
			rect.x+=myDNA.speed;
		else
			rect.x-=myDNA.speed;
	}
	else if( rect.x < t.x ){
		if( rect.y < t.y ){
			rect.x+=myDNA.speed;
			rect.y+=myDNA.speed;
		}
		else{
			rect.x+=myDNA.speed;
			rect.y-=myDNA.speed;
		}
	}
	else if ( rect.x > t.x ){
		if( rect.y < t.y ){
			rect.x-=myDNA.speed;
			rect.y+=myDNA.speed;
		}
		else{
			rect.x-=myDNA.speed;
			rect.y-=myDNA.speed;
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
