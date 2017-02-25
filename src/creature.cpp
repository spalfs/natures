#include "creature.hpp"

Creature::Creature(Rectangle r, DNA d)
{
        rect    = r;
        myDNA   = d;

        if(rect.x == 0 && rect.y == 0){
                rect.x = getRandom(30);
                rect.y = getRandom(30);
        }

        type            = CREATURE_TYPE;
        health          = myDNA.maxHealth/2;
        gender          = rand() % 2;
        age             = 0;
        pregnancyTime   = 0;
        pregnancyReady  = false;
        pregnate        = false;
        hasTarget       = false;

        if(gender)
                gfxData = GraphicsData(rect.x, rect.y, 1, 0, 0, CREATURE_SIDES);
        else
                gfxData = GraphicsData(rect.x, rect.y, 0, 0, 1, CREATURE_SIDES);
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
        std::random_shuffle(nearMe.begin(),nearMe.end());

        for(std::vector <Entity*>::iterator it = nearMe.begin(); it!=nearMe.end(); it++){
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
                Rectangle tmp;
                tmp.x = getRandom(30);
                tmp.y = getRandom(30);
                wTarget = tmp;
        }
}

void Creature::checkTarget()
{
        for(std::vector <Entity*>::iterator it = nearMe.begin(); it!=nearMe.end(); it++)
                if( target == *it )
                        return;

        hasTarget = false;
}


void Creature::Action()
{	
        if(hasTarget){ 
                if(Distance(rect,target->getRectangle()) < myDNA.reach){
                        if(target->getType() == RESOURCE_TYPE){
                                target->eat(myDNA.bite);
                                health+=myDNA.bite;
                                amountAte++;
                                if(target->getAmount()<=0)
                                        hasTarget = false;
                        }
                        else if (target->getType() == CREATURE_TYPE){
                                if(target->getGender() != gender){
                                        target->impregnate(myDNA);
                                }
                                hasTarget = false;
                        }

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
