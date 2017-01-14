#ifndef creature_h
#define creature_h

#include <SDL2/SDL.h>
#include <list>

#include "entity.hpp"
#include "constants.hpp"

class Creature: public Entity
{
  public:
    Creature(Window m, SDL_Rect R);
    void Behavior();
    void Action();
    void Priority();
    void setTarget();
    void Move(SDL_Rect R);

    void giveN(list<Entity*> n){N = n;};
    double Distance(SDL_Rect A, SDL_Rect B){return sqrt(pow(A.x-B.x,2)+pow(A.y-B.y,2));};
    int getHealth(){return health;};
    bool doesItHaveTarget(){return hasTarget;};
    int getBestSense(){return bestSense;};

  private:
    bool hasTarget;
    bool wander;
    SDL_Rect wTarget;
    
    int health; 
    int reach;
    int maxHealth;
    bool hungry; 
    int speed;
    bool able;     
    int bestSense;
    
    list<Entity*> N;
    Entity *target; 
};

#endif
