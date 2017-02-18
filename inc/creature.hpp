#ifndef creature_h
#define creature_h

#include <SDL2/SDL.h>
#include <vector>
#include <algorithm>

#include "entity.hpp"
#include "constants.hpp"
#include "functions.hpp"
#include "dna.hpp"

class Creature: public Entity
{
  public:
    Creature(Window M, SDL_Rect R, Dna D);
    void    Behavior();
    void    Action();
    void    Priority();
    void    setTarget();
    void    checkTarget();
    void    moveTowards(SDL_Rect R);
    void    impregnate(Dna D);
    void    giveN(std::vector<Entity*> n){N = n;};
    
    Dna     getDNA(){return mine;};
    Dna     getChildDNA(){return childs;};
    int     getHealth(){return health;};
    int     getBestSense(){return mine.bestSense;};
    bool    getGender(){return gender;};
    bool    getPregnancyReady(){return pregnancyReady;};
    void    hadPregnancy(){pregnate = pregnancyReady = false;};
  
  private:
    SDL_Rect                wTarget;
    Entity                  *target;
    std::vector<Entity*>    N;
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
