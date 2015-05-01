#ifndef creature_h
#define creature_h

#include "entity.h"

class Creature: public Entity
{
  public:
    Creature(Window m, std::string s);
};

#endif
