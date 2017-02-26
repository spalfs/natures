#include "dna.hpp"

DNA::DNA()
{
        maxHealth               = CREATURE_MAX_HEALTH;
        speed                   = CREATURE_SPEED;
        reach                   = CREATURE_REACH;
        bestSense               = CREATURE_BEST_SENSE;
        bite                    = CREATURE_BITE;
        amountToGrow            = CREATURE_AMOUNT_TO_GROW;
        expectedPregnancyTime   = CREATURE_EXP_PREG_TIME;
        expectedAge             = CREATURE_EXP_AGE;
        sizeMax                 = CREATURE_SIZE_MAX;
        mutationPercent         = CREATURE_MUTATION_PERCENT;
        mutationChance          = CREATURE_MUTATION_CHANCE;
}

DNA DNA::combine(DNA D)
{
        DNA N;
       
        N.maxHealth             = (maxHealth                    + D.maxHealth)/2; 
        N.speed                 = (speed                        + D.speed)/2; 
        N.reach                 = (reach                        + D.reach)/2; 
        N.bestSense             = (bestSense                    + D.bestSense)/2; 
        N.bite                  = (bite                         + D.bite)/2; 
        N.amountToGrow          = (amountToGrow                 + D.amountToGrow)/2; 
        N.expectedPregnancyTime = (expectedPregnancyTime        + D.expectedPregnancyTime)/2; 
        N.expectedAge           = (expectedAge                  + D.expectedAge)/2; 
        N.sizeMax               = (sizeMax                      + D.sizeMax)/2; 
        N.mutationPercent       = (mutationPercent              + D.mutationPercent)/2;
        N.mutationChance        = (mutationChance               + D.mutationChance)/2;

        if(roll(mutationChance)){
                float pn;
                if(rand()%2)
                        pn = 1;
                else
                        pn = -1;
                switch(rand()%11){
                        case 0: N.maxHealth             = abs(N.maxHealth               *(N.mutationPercent+pn));       break;
                        case 1: N.speed                 = abs(N.speed                   *(N.mutationPercent+pn));       break;
                        case 2: N.reach                 = abs(N.reach                   *(N.mutationPercent+pn));       break;
                        case 3: N.bestSense             = abs(N.bestSense               *(N.mutationPercent+pn));       break;
                        case 4: N.bite                  = abs(N.bite                    *(N.mutationPercent+pn));       break;
                        case 5: N.amountToGrow          = abs(N.amountToGrow            *(N.mutationPercent+pn));       break;
                        case 6: N.expectedPregnancyTime = abs(N.expectedPregnancyTime   *(N.mutationPercent+pn));       break;
                        case 7: N.expectedAge           = abs(N.expectedAge             *(N.mutationPercent+pn));       break;
                        case 8: N.sizeMax               = abs(N.sizeMax                 *(N.mutationPercent+pn));       break;
                        case 9: N.mutationPercent       = abs(N.expectedAge             *(N.mutationPercent+pn));       break;
                        case 10:N.mutationChance        = abs(N.mutationChance          *(N.mutationPercent+pn));       break;
                }
        }
        return N;
}
