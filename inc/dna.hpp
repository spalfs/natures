#ifndef dna_h
#define dna_h

#include "constants.hpp"

class Dna
{  
    public:
        Dna();
        Dna combine(Dna D);
        int maxHealth;
        float speed;
        int reach;
        int bestSense;
        int bite;
        int amountToGrow;
        int expectedPregnancyTime;
        int expectedAge;
        int sizeMax;
};

#endif
