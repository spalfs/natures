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
    void giveN(vector<Entity*> n){N = n;};
 
    Location getLocation(){return L;};
    double Distance(Location A, Location B){return sqrt(pow(A.x-B.x,2)+pow(A.y-B.y,2));};
    int getHealth(){return health;};
    bool doesItHaveTarget(){return hasTarget;};
    int getBestSense(){return bestSense;};

  private:
    bool hasTarget;
    bool wandering;

    int health; 
    int maxHealth;
    int hunger; 
    int speed = 1;
    bool able;     
    int bestSense = 100; 
    
    vector<Entity*> N;
    Entity *target;

    int n; 
};

#endif
