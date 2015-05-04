#include "list.hpp"

List::List(Window m)
{
  C.insert(Creature(m,"img/Cbasic.png"));
  R.insert(Resource(m,"img/Rbasic.png"));
}