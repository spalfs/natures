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
    
    double Distance(Location A, Location B){return sqrt(pow(A.x-B.x,2)+pow(A.y-B.y,2));};
    int getHealth(){return health;};
    bool doesItHaveTarget(){return hasTarget;};
    int getBestSense(){return bestSense;};

  private:
    int xTarget; 
    int yTarget; 

    bool hasTarget;
    bool wandering;

    int health; 
    int maxHealth;
    int hunger; 
    int speed = 2;
    bool able;     
    int bestSense = 100; 

    vector<Resource*> nR; //vector containing resources near the creature
    vector<Creature*> nC; //vector containing creatures near the creature
    int n; 
};

#endif
