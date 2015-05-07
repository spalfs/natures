#include "list.hpp"

List::List(Window m)
{
  int i;
  for(i=0;i<5;i++)
  {
    Creature X = Creature(m,"img/Cbasic.png");
    C.push_back(X);
  }

  for(i=0;i<5;i++)
  {
    Resource Y(m,"img/Rbasic.png");
    R.push_back(Y);
    L.push_back(Y.getLocation());
  }
}

void List::Behavior()
{
  int i, j;
  std::vector<Location> Z;

  for(i = 0; i < C.size(); i++)
  {
    C[i].Behavior();
    for(j = 0; j < L.size(); j++)
      if(200>(Distance(C[i].getLocation(),L[j])))
      {
        Z.push_back(L[j]);
      }

    C[i].giveKnown(Z);
    Z.clear();
  }
}

void List::Place()
{
  int i;

  for(i = 0;i < L.size(); i++)
    if(L[i].t==1)
      L.erase(L.begin()+i);

  for(i = 0; i < C.size(); i++)
  {
    C[i].Place();
    L.push_back(C[i].getLocation());
  }

  for(i = 0; i < R.size(); i++)
  {
    R[i].Place();
  }
}

double List::Distance(Location A, Location B)
{
  double z = sqrt(pow(A.x-B.x,2)+pow(A.y-B.y,2));
  //std::cout << z << "\n";
  return z;
}
