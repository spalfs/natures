#ifndef resource_h
#define resource_h

#include "entity.hpp"
#include "functions.hpp"

class Resource: public Entity
{
  public:
    Resource(Window m, SDL_Rect R);
    int getAmount(){return amount;};
    void grow();
    void eat(int bite);

  private:
    int amount;
    int growAmount;
};

#endif
