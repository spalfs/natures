#ifndef dna_h
#define dna_h

#include "constants.hpp"

class Dna
{  
    public:
        Dna();
        int maxHealth;
        int speed;
        int reach;
        int bestSense;
        int bite;
        int amountToGrow;
        int expectedPregnancyTime;
        int expectedAge;
        int sizeMax;
};

#endif
