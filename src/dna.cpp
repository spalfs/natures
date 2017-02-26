#include "dna.hpp"

DNA::DNA(std::string s)
{
        if(s == "creature"){
                type                    = CREATURE_TYPE;
                maxHealth               = CREATURE_MAX_HEALTH;
                bestSense               = CREATURE_BEST_SENSE;
                bite                    = CREATURE_BITE;
                expectedPregnancyTime   = CREATURE_EXP_PREG_TIME;
                expectedAge             = CREATURE_EXP_AGE;
                growAmount              = 0;
                reach                   = CREATURE_REACH;
                speed                   = CREATURE_SPEED;
                mutationPercent         = CREATURE_MUTATION_PERCENT;
                mutationChance          = CREATURE_MUTATION_CHANCE;
        }
        else if(s == "resource"){
                type                    = RESOURCE_TYPE;
                maxHealth               = RESOURCE_MAX_HEALTH;
                bestSense               = 0;
                bite                    = 0;
                expectedPregnancyTime   = 0;
                expectedAge             = 0;
                growAmount              = RESOURCE_GROW_AMOUNT;
                reach                   = 0;
                speed                   = 0;
                mutationPercent         = 0;
                mutationChance          = 0;
        }
}

DNA DNA::combine(DNA D)
{
        DNA N;
        N.type                  = CREATURE_TYPE; 
        N.maxHealth             = (maxHealth                    + D.maxHealth)/2; 
        N.bestSense             = (bestSense                    + D.bestSense)/2; 
        N.bite                  = (bite                         + D.bite)/2; 
        N.expectedPregnancyTime = (expectedPregnancyTime        + D.expectedPregnancyTime)/2; 
        N.expectedAge           = (expectedAge                  + D.expectedAge)/2; 
        N.growAmount            = (growAmount                   + D.growAmount)/2;
        N.reach                 = (reach                        + D.reach)/2; 
        N.speed                 = (speed                        + D.speed)/2; 
        N.mutationPercent       = (mutationPercent              + D.mutationPercent)/2;
        N.mutationChance        = (mutationChance               + D.mutationChance)/2;

        if(roll(mutationChance)){
                float pn;
                if(rand()%2)
                        pn = 1;
                else
                        pn = -1;
                switch(rand()%10){
                        case 0: N.maxHealth             = abs(N.maxHealth               *(N.mutationPercent+pn));       break;
                        case 1: N.bestSense             = abs(N.bestSense               *(N.mutationPercent+pn));       break;
                        case 2: N.bite                  = abs(N.bite                    *(N.mutationPercent+pn));       break;
                        case 3: N.expectedPregnancyTime = abs(N.expectedPregnancyTime   *(N.mutationPercent+pn));       break;
                        case 4: N.expectedAge           = abs(N.expectedAge             *(N.mutationPercent+pn));       break;
                        case 5: N.growAmount            = abs(N.growAmount              *(N.mutationPercent+pn));       break;
                        case 6: N.reach                 = abs(N.reach                   *(N.mutationPercent+pn));       break;
                        case 7: N.speed                 = abs(N.speed                   *(N.mutationPercent+pn));       break;
                        case 8: N.mutationPercent       = abs(N.expectedAge             *(N.mutationPercent+pn));       break;
                        case 9: N.mutationChance        = abs(N.mutationChance          *(N.mutationPercent+pn));       break;
                }
        }
        return N;
}
