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
  int i;
  for(i = 0; i < C.size(); i++)
  {
    C[i].Behavior();
  }
}

void List::Place()
{
  int i;

  for(i = 0;i < L.size(); i++)
    if(L.getType()==1)
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
