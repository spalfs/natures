#ifndef dna_h
#define dna_h

#include "constants.hpp"

class DNA
{  
        public:
                DNA();

                DNA combine(DNA D);

                int     maxHealth;
                int     reach;
                int     bestSense;
                int     bite;
                int     amountToGrow;
                int     expectedPregnancyTime;
                int     expectedAge;
                int     sizeMax;

                float   speed;
};

#endif
