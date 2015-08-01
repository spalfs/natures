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
    void giveR(vector<Resource*> n){nR=n;};
    void giveC(vector<Creature*> n){nC=n;};
    int getHealth(){return health;};
    double Distance(Location A, Location B);
    bool doesItHaveTarget();
    int getBestSense(){return bestSense;};

  private:
    int xTarget; //x-coordinate of creature's target position
    int yTarget; //y-coordinate of creature's target position

    bool hasTarget;
    bool wandering;

    int health; //health of a creature (0-100)
    int maxHealth;
    int hunger; //value associated with a creatures want to find food (0-100)
    int speed = 1;
    bool able; // ability to reproduce
    int bestSense =  100; // Distance it can see/smell/hear

    vector<Resource*> nR; //vector containing resources near the creature
    vector<Creature*> nC; //vector containing creatures near the creature
    int n; // counter for which place in resource array is targeted
};

#endif
