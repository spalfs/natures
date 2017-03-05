#include "organism.hpp"

Organism::Organism(Rectangle r, DNA d)
{
        rect    = r;
        myDNA   = d;

        if(rect.x == 0 && rect.y == 0){
                rect.x = getRandom(30);
                rect.y = getRandom(30);
        }

        health          = myDNA.maxHealth/2;
        gender          = rand() % 2;
        age             = 0;
        pregnancyTime   = 0;
        pregnancyReady  = false;
        pregnate        = false;
        hasTarget       = false;
        wander          = false;
}

void Organism::Behavior()
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

void Organism::Priority()
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

void Organism::setTarget()
{
        std::random_shuffle(nearMe.begin(),nearMe.end());

        for(std::vector<Organism*>::iterator it = nearMe.begin(); it!=nearMe.end(); it++){
                if( (*it)->getType() == myDNA.eatType && hungry){ 
                        target = *it;
                        hasTarget = true;
                        wander = false;
                        break;
                } 
                if( (*it)->getType() == myDNA.type && able && (*it)->getGender() != gender ){
                        target = *it;
                        hasTarget = true;
                        wander = false;
                        break;
                }       
        }

        if(!hasTarget&&!wander){
                wander = true;
                Rectangle tmp(getRandom(30),getRandom(30),0,0);
                wTarget = tmp;
        }
}

void Organism::checkTarget()
{
        for(std::vector<Organism*>::iterator it = nearMe.begin(); it!=nearMe.end(); it++)
                if( target == *it )
                        return;

        hasTarget = false;
}

void Organism::Action()
{	
        if(hasTarget){ 
                if(Distance(rect,target->getRectangle()) < myDNA.reach){
                        if(target->getType() == myDNA.eatType){
                                target->takeBite(myDNA.bite);
                                health+=myDNA.bite;
                                if(target->getHealth()<=0)
                                        hasTarget = false;
                        }
                        else if (target->getType() == myDNA.type){
                                if(target->getGender() != gender){
                                        target->passDNA(myDNA);
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

void Organism::moveTowards(Rectangle t)
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

void Organism::passDNA(DNA d)
{
        if(!pregnate){
                pregnate = true;
                pregnancyTime = 0;
                childsDNA = myDNA.combine(d);
        }
}

void Organism::grow()
{
        if(health < myDNA.maxHealth)
                health+=myDNA.growAmount; 
}

void Organism::takeBite(int bite)
{
        health-=bite;
}
