#include "dna.hpp"

Dna::Dna()
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
