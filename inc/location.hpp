#ifndef location_h
#define location_h

class Location
{
  public:
    Location(){x=y=t=0;};
	  Location(int x1, int y1, int t1){x=x1;y=y1;t=t1;};

    int x;
	  int y;
	  int t;
};

#endif
