#ifndef resource_h
#define resource_h

#include "entity.hpp"
#include "location.hpp"

class Resource: public Entity
{
  public:
    Resource(Window m, std::string s);
    Resource(Window m, std::string s, Location z);
    Location getLocation();
    void eat(){amount-=10;};
    int getAmount(){return amount;};

  private:
    int amount; //value associated with the amount of whatever (food, etc) left in the resource
};

#endif
