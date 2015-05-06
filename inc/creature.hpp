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
    Location getLocation();

  private:
    int xT;
    int yT;
    int hp;
    int hu;
    Location K[3];
};

#endif
