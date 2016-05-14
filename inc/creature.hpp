#ifndef creature_h
#define creature_h

#include "entity.hpp"
#include "resource.hpp"
#include "location.hpp"

class Creature: public Entity
{
  public:
    Creature(Window m, std::string s);
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
    int maxHealth;
    bool hungry; 
    int speed = 1;
    bool able;     
    int bestSense = 100; 
    
    list<Entity*> N;
    Entity *target; 
};

#endif
