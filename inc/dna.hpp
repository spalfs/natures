#ifndef dna_h
#define dna_h

#include <string>

#include "constants.hpp"
#include "functions.hpp"

class DNA
{  
        public:
                DNA(){};
                DNA(std::string s);

                DNA combine(DNA D);

                int     type;
                int     maxHealth;
                int     bestSense;
                int     bite;
                int     expectedPregnancyTime;
                int     expectedAge;
                int     growAmount;

                float   reach;
                float   speed;
                float   mutationPercent;
                float   mutationChance;

                struct  Visuals{
                        float  sides;
                        float  red;
                        float  green;
                        float  blue;
                } appearance;
};

#endif
