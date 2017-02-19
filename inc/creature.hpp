#ifndef creature_h
#define creature_h

#include <SDL2/SDL.h>
#include <vector>
#include <list>
#include <algorithm>

#include "entity.hpp"
#include "constants.hpp"
#include "functions.hpp"
#include "dna.hpp"

class Creature: public Entity
{
  public:
    Creature(Location t, Dna D);
    void    Behavior();
    void    Action();
    void    Priority();
    void    setTarget();
    void    checkTarget();
    void    moveTowards(Location t);
    void    impregnate(Dna D);
    void    giveN(std::list<Entity*> n){N = n;};
    
    Dna     getDNA(){return mine;};
    Dna     getChildDNA(){return childs;};
    int     getHealth(){return health;};
    int     getBestSense(){return mine.bestSense;};
    bool    getGender(){return gender;};
    bool    getPregnancyReady(){return pregnancyReady;};
    void    hadPregnancy(){pregnate = pregnancyReady = false;};
  
  private:
    Location                wTarget;
    Entity                  *target;
    std::list<Entity*>    N;
    Dna                     mine;
    Dna                     childs;

    int     health; 
    int     amountAte;
    int     pregnancyTime;
    int     age;

    bool    hungry; 
    bool    pregnancyReady;
    bool    able;     
    bool    hasTarget;
    bool    wander;
};

#endif
