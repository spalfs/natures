#ifndef location_h
#define location_h

class Location
{
  public: 
	Location(int x1, int y1, int t1){x=x1;y=y1;type=t1;}; 
    Location(){x=y=type=0;};
    int x; 
    int y; 
    int type; //value associated with type of entity at location. 1: Creature, 2: Resource
};

#endif
