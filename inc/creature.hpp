#ifndef creature_h
#define creature_h

#include <SDL2/SDL.h>
#include <list>

#include "entity.hpp"
#include "constants.hpp"
#include "functions.hpp"

class Creature: public Entity
{
  public:
    Creature(Window m, SDL_Rect R);
    void    Behavior();
    void    Action();
    void    Priority();
    void    setTarget();
    void    checkTarget();
    void    Move(SDL_Rect R);
    void    impregnate();
    void    giveN(list<Entity*> n){N = n;};
    
    int     getHealth(){return health;};
    int     getBestSense(){return bestSense;};
    bool    getGender(){return gender;};
    bool    getPregnancyReady(){return pregnancyReady;};
    void    hadPregnancy(){pregnate = pregnancyReady = false;};
  
  private:
    SDL_Rect        wTarget;
    Entity          *target;
    list<Entity*>   N;

    int     health; 
    int     reach;
    int     maxHealth;
    int     speed;
    int     bestSense;
    int     bite;
    int     amountAte;
    int     amountToGrow;
    int     pregnancyTime;
    int     expectedPregnancyTime;

    bool    hungry; 
    bool    pregnancyReady;
    bool    able;     
    bool    hasTarget;
    bool    wander;
};

#endif
