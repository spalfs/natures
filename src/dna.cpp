#include "dna.hpp"

DNA::DNA(std::string s)
{
        if(s == "herbavore"){
                type                    = HERBAVORE_TYPE;
                eatType                 = PLANT_TYPE;
                maxHealth               = CREATURE_MAX_HEALTH;
                bestSense               = CREATURE_BEST_SENSE;
                bite                    = CREATURE_BITE;
                expectedPregnancyTime   = CREATURE_EXP_PREG_TIME;
                expectedAge             = CREATURE_EXP_AGE;
                hungryAmount            = CREATURE_HUNGRY_AMOUNT;
                starveAmount            = CREATURE_STARVE_AMOUNT;
                reach                   = CREATURE_REACH;
                speed                   = CREATURE_SPEED;
                mutationPercent         = CREATURE_MUTATION_PERCENT;
                mutationChance          = CREATURE_MUTATION_CHANCE;
                appearance.red          = 0;
                appearance.green        = 1;
                appearance.blue         = 1;
        }
        else if(s == "carnivore"){
                type                    = CARNIVORE_TYPE;
                eatType                 = HERBAVORE_TYPE;
                maxHealth               = CREATURE_MAX_HEALTH;
                bestSense               = CREATURE_BEST_SENSE * 2;
                bite                    = CREATURE_BITE * 2;
                expectedPregnancyTime   = CREATURE_EXP_PREG_TIME;
                expectedAge             = CREATURE_EXP_AGE * 2;
                hungryAmount            = CREATURE_HUNGRY_AMOUNT;
                starveAmount            = CREATURE_STARVE_AMOUNT;
                reach                   = CREATURE_REACH * 2;
                speed                   = CREATURE_SPEED * 2;
                mutationPercent         = CREATURE_MUTATION_PERCENT;
                mutationChance          = CREATURE_MUTATION_CHANCE;
                appearance.red          = 1;
                appearance.green        = 0;
                appearance.blue         = 1;
        }
        else if(s == "plant"){
                type                    = PLANT_TYPE;
                maxHealth               = PLANT_MAX_HEALTH;
                growAmount              = PLANT_GROW_AMOUNT;
                appearance.red          = 0;
                appearance.green        = 1;
                appearance.blue         = 0;
        }
        else if(s == "corpse"){
                type                    = CORPSE_TYPE;
                maxHealth               = CORPSE_MAX_HEALTH;
                growAmount              = CORPSE_DECAY_AMOUNT;
                appearance.red          = 0;
                appearance.green        = 0;
                appearance.blue         = 1;
        }
}

DNA DNA::combine(DNA D)
{
        DNA N;
        N.type                  = type; 
        N.eatType               = eatType;
        N.maxHealth             = (maxHealth                    + D.maxHealth)/2; 
        N.bestSense             = (bestSense                    + D.bestSense)/2; 
        N.bite                  = (bite                         + D.bite)/2; 
        N.expectedPregnancyTime = (expectedPregnancyTime        + D.expectedPregnancyTime)/2; 
        N.expectedAge           = (expectedAge                  + D.expectedAge)/2; 
        N.growAmount            = (growAmount                   + D.growAmount)/2;
        N.hungryAmount          = (hungryAmount                 + D.hungryAmount)/2;
        N.starveAmount          = (starveAmount                 + D.starveAmount)/2;
        N.reach                 = (reach                        + D.reach)/2; 
        N.speed                 = (speed                        + D.speed)/2; 
        N.mutationPercent       = (mutationPercent              + D.mutationPercent)/2;
        N.mutationChance        = (mutationChance               + D.mutationChance)/2;
        N.appearance.red        = appearance.red;
        N.appearance.green      = appearance.green;
        N.appearance.blue       = appearance.blue;

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
