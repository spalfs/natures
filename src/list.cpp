#include "list.hpp"

List::List(Window m) //Constructor
{
  int i;

  for(i=0;i<3;i++)
  {
    Creature X(m,"img/Cbasic.png");
    C.push_back(X);
  }

  for(i=0;i<100;i++)
  {
    Resource Y(m,"img/Rbasic.png");
    R.push_back(Y);
  }

  main = m;
}

void List::Place()
{
  //places each creature on window
  for(vector<Creature>::iterator it = C.begin(); it!=C.end(); it++)
    it->Place();

  /*
  if(R.size()<15)
  {
    Resource Y(m,"img/Rbasic.png");
    R.push_back(Y);
  }
  */

  //places all resources
  for(int j = 0; j<R.size(); j++)
  {
    if(R[j].getAmount()<=0)
      R.erase(R.begin()+j);
    else
      R[j].Place();
  }
}

void List::Behavior()
{
  for(int i = 0; i<C.size(); i++)
  {
    C[i].Behavior();

    vector<Resource*> N;

    for(int j = 0; j < R.size(); j++)
      if(C[i].getBestSense()>Distance(C[i].getLocation(),R[j].getLocation()))
        N.push_back(&R[j]);

    C[i].giveR(N);
    N.clear();

    vector<Creature*> M;
    for(int j = 0; j < C.size(); j++)
    {
      if(j==i)
        continue;
      else if(C[i].getBestSense()>Distance(C[i].getLocation(),C[j].getLocation()))
        M.push_back(&C[j]);
    }

    C[i].giveC(M);
    M.clear();

    // This kills the creature
    if(C[i].getHealth()<=0)
    {
      Location z = C[i].getLocation();
      Resource r = Resource(main,"img/Cdead.png",z);
      R.push_back(r);
      C.erase(C.begin()+i);
    }
  }
}

double List::Distance(Location A, Location B)
{
  //computes distance between two points
  return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}
