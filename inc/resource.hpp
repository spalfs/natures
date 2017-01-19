#ifndef resource_h
#define resource_h

#include "entity.hpp"

class Resource: public Entity
{
  public:
    Resource(Window m, SDL_Rect Rect);
    void eat(int bite);

    int getAmount(){return amount;};
    void grow();
    int map(int x, int inMin, int inMax, int outMin, int outMax);

  private:
    int amount;
    int growAmount;
};

#endif
