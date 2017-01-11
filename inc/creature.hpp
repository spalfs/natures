#ifndef creature_h
#define creature_h

#include <SDL2/SDL.h>
#include <list>

#include "location.hpp"
#include "entity.hpp"
#include "constants.hpp"

class Creature: public Entity
{
  public:
    Creature(Window m, int size);
    void Behavior();
    void Action();
    void Priority();
    void setTarget();
    void Move(Location l);

    void giveN(list<Entity*> n){N = n;};
    Location getLocation(){return L;};
    double Distance(Location A, Location B){return sqrt(pow(A.x-B.x,2)+pow(A.y-B.y,2));};
    int getHealth(){return health;};
    bool doesItHaveTarget(){return hasTarget;};
    int getBestSense(){return bestSense;};

  private:
    bool hasTarget;
    bool wander;
    Location wTarget;
    int health; 
    int reach = CREATURE_REACH;
    int maxHealth;
    bool hungry; 
    int speed = CREATURE_SPEED;
    bool able;     
    int bestSense = CREATURE_BEST_SENSE;
    
    list<Entity*> N;
    Entity *target; 
};

#endif
