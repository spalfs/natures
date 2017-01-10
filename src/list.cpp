#include "list.hpp"

List::List(Window m)
{
  int i;

  for(i=0;i<10;i++){
    Creature X(m,10);
    C.push_back(X);
  }

  for(i=0;i<100;i++){
    Resource Y(m,5);
    R.push_back(Y);
  }

  main = m;
}

void List::Place()
{ 
  for(list<Creature>::iterator it = C.begin(); it!=C.end(); it++)
    it->Place();

  for(list<Resource>::iterator it = R.begin(); it!=R.end(); it++){
    if(it->getAmount()<=0)
        R.erase(it--);
    else
        it->Place();
  } 
}

void List::Behavior()
{
    for(list<Creature>::iterator it = C.begin(); it!=C.end(); it++){
        
        list<Entity*> N = getNear(*it); 
        it->giveN(N); 
        
        it->Behavior();
         
        if(it->getHealth()<=0){
            Location z = it->getLocation();
            SDL_Rect rect = it->getRect();
            Resource r = Resource(main,rect.w,z);
            R.push_back(r);
            C.erase(it--);
        }
    }
}

list<Entity*> List::getNear(Creature nC)
{
    list<Entity*> N;

    for(list <Resource>::iterator it = R.begin(); it!=R.end(); it++){
        if( nC.getBestSense() > Distance(nC.getLocation(),it->getLocation()) )
            N.push_back(&(*it));
    }
       
    for(list <Creature>::iterator it = C.begin(); it!=C.end(); it++){
        if( &nC == &(*it))
            continue;
        else if( nC.getBestSense() > Distance(nC.getLocation(),it->getLocation()) )
            N.push_back(&(*it));
    }
               
    return N;
}


