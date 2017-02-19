#include "dna.hpp"

DNA::DNA()
{
    maxHealth                = CREATURE_MAX_HEALTH;
    speed                    = CREATURE_SPEED;
    reach                    = CREATURE_REACH;
    bestSense                = CREATURE_BEST_SENSE;
    bite                     = CREATURE_BITE;
    amountToGrow             = CREATURE_AMOUNT_TO_GROW;
    expectedPregnancyTime    = CREATURE_EXP_PREG_TIME;
    expectedAge              = CREATURE_EXP_AGE;
    sizeMax                  = CREATURE_SIZE_MAX;
}

DNA DNA::combine(DNA D)
{
    DNA N;

    N.maxHealth             = (this->maxHealth + D.maxHealth)/2; 
    N.speed                 = (this->speed + D.speed)/2; 
    N.reach                 = (this->reach + D.reach)/2; 
    N.bestSense             = (this->bestSense + D.bestSense)/2; 
    N.bite                  = (this->bite + D.bite)/2; 
    N.amountToGrow          = (this->amountToGrow + D.amountToGrow)/2; 
    N.expectedPregnancyTime = (this->expectedPregnancyTime + D.expectedPregnancyTime)/2; 
    N.expectedAge           = (this->expectedAge + D.expectedAge)/2; 
    N.sizeMax               = (this->sizeMax + D.sizeMax)/2; 

    return N;
}
