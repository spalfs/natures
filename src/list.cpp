#include "list.hpp"

List::List(Window m)
{
  Creature X0(m,"img/Cbasic.png");
  C.push_back(X0);
  Creature X1(m,"img/Cbasic.png");
  C.push_back(X1);

  Resource Y(m,"img/Rbasic.png");
  R.push_back(Y);
};

void List::Behavior()
{
  int i;
  for(i = 0; i < C.size(); i++)
    C[i].Behavior();
}

void List::Place()
{
  int i;
  for(i = 0; i < C.size(); i++)
    C[i].Place();

  for(i = 0; i < R.size(); i++)
    R[i].Place();
}
