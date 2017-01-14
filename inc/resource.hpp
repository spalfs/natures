#ifndef resource_h
#define resource_h

#include "entity.hpp"

class Resource: public Entity
{
  public:
    Resource(Window m, SDL_Rect Rect);
    void eat();

    int getAmount(){return amount;};

  private:
    int amount;
};

#endif
