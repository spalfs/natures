#ifndef creature_h
#define creature_h

#include "entity.hpp"

class Creature: public Entity
{
  public:
    Creature(Window m, std::string s);
    void Behavior();
	void Action();
	
  private:
    int xT;
    int yT;
};

#endif
