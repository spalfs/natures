#ifndef creature_h
#define creature_h

#include "entity.hpp"
#include "resource.hpp"
#include "location.hpp"

class Creature: public Entity
{
  public:
    Creature(Window m, std::string s);
    int Behavior();
    bool Action();
    void Priority();
    Location getLocation();
    void give(vector<Resource*> n){nR=n;};
    int getHealth(){return health;};
    double Distance(Location A, Location B);

  private:
    int xTarget; //x-coordinate of creature's target position
    int yTarget; //y-coordinate of creature's target position
    bool hasTarget;
    int health; //health of a creature (0-100)
    int hunger; //value associated with a creatures want to find food (0-100)
    int speed = 1;
    vector<Resource*> nR; //vector containing objects near the creature
    int n; // counter for which place in resource array is targeted 
};

#endif
