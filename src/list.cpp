#include "list.hpp"

List::List(Window m) //Constructor
{
  int i;

  for(i=0;i<10;i++)
  {
    Creature X(m,"img/Cbasic.png");
    C.push_back(X);
  }

  //Creates 5 resources, inserts them into vector R; inserts locations of resources into vector L
  for(i=0;i<5;i++)
  {
    Resource Y(m,"img/Rbasic.png");
    R.push_back(Y);
    L.push_back(Y.getLocation());
  }

  main = &m;
}

void List::Place()
{
  int i;

  //if any locations are creatures, erases them from vector L
  for(i = 0;i < L.size(); i++)
    if(L[i].type==1)
      L.erase(L.begin()+i);

  //places each creature on window, inserts their locations into vector L
  for(i = 0; i < C.size(); i++)
  {
    C[i].Place();
    L.push_back(C[i].getLocation());
  }

  //places all resources
  for(i = 0; i < R.size(); i++)
  {
    R[i].Place();
  }
}

void List::Behavior()
{
  int i, j;
  std::vector<Location> Z;

  for(i = 0; i < C.size(); i++)
  {
    C[i].Behavior(); //executes the behavior of the creature at i
    
    // This kills the creature
    if(C[i].getHealth()==0)
    {
      Location z = C[i].getLocation();
      R.push_back(Resource(main,"img/Cdead.png",z));
      C.erase(C.begin()+i);
    }
    
    for(j = 0; j < L.size(); j++)
      if(200>(Distance(C[i].getLocation(),L[j]))) //if the distance between the creature and L[j] is less than 200, insert L[j] into vector Z.
        Z.push_back(L[j]);

    C[i].giveKnown(Z); //sets creature's target location?
    Z.clear(); //clear vector Z for next creature
  }
}

double List::Distance(Location A, Location B)
{
  //computes distance between two points
  return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}
