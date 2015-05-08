#ifndef location_h
#define location_h

class Location
{
  public:
    Location(){x=y=type=0;}; //is this line needed?
	  Location(int x1, int y1, int t1){x=x1;y=y1;type=t1;};

    int x; //x-coordinate of entity
	  int y; //y-coordinate of entity
	  int type; //value associated with type of entity at location. 1: Creature, 2: Resource
};

#endif
