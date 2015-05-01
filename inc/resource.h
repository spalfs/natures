#ifndef resource_h
#define resource_h

#include "entity.h"

class Resource: public Entity
{
  public:
    Resource(Window m, std::string s);
};

#endif
