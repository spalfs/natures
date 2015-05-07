#ifndef creature_h
#define creature_h

#include "entity.hpp"
#include "location.hpp"

class Creature: public Entity
{
  public:
    Creature(Window m, std::string s);
    void Behavior();
	  void Action();
    void Priority();
    Location getLocation();
    void giveKnown(std::vector<Location> Z){K=Z;};

  private:
    int xT;
    int yT;
    int hp;
    int hu;
    std::vector<Location> K;
};

#endif
