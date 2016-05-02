#ifndef location_h
#define location_h

class Location
{
  public: 
	Location(int x1, int y1){x=x1;y=y1;}; 
    Location(){x=y=0;};
    int x; 
    int y;  
};

#endif
