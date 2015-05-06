#ifndef location_h
#define location_h

class Location
{
  public:
    Location(){x=y=t=0;};
	  Location(int x, int y, int z){};
    int getType(){return t;};
    
  private:
    int x;
	  int y;
	  int t;
};

#endif
