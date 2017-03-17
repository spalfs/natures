#ifndef dna_h
#define dna_h

#include <string>

#include "constants.hpp"
#include "functions.hpp"

class DNA
{  
        public:
                DNA(){};
                DNA(int t);

                DNA combine(DNA D);

                int     type;
                int     eatType;
                int     maxHealth;
                int     bestSense;
                int     bite;
                int     expectedPregnancyTime;
                int     expectedAge;
                int     growAmount;
                int     hungryAmount;
                int     starveAmount;

                float   reach;
                float   speed;
                float   mutationPercent;
                float   mutationChance;

                struct  Visuals{
                        float  red;
                        float  green;
                        float  blue;
                } appearance;
};

#endif
