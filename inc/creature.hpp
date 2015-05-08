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
    void giveKnown(std::vector<Location> Z){location = Z;};

  private:
    int xTarget; //x-coordinate of creature's target position
    int yTarget; //y-coordinate of creature's target position
    int health; //health of a creature (0-100)
    int hunger; //value associated with a creatures want to find food (0-100)
    std::vector<Location> location; //vector containing creatures location on window or target location?
};

#endif
