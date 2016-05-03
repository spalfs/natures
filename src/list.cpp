#include "list.hpp"

List::List(Window m)
{
  int i;

  for(i=0;i<2;i++)
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
  for(vector<Creature>::iterator it = C.begin(); it!=C.end(); it++)
    it->Place();

  for(vector<Resource>::iterator it = R.begin(); it!=R.end(); it++){
    if(it->getAmount()<=0)
        R.erase(it--);
    else
        it->Place();
  } 
}

void List::Behavior()
{
    for(vector<Creature>::iterator it = C.begin(); it!=C.end(); it++){
        
        vector<Entity*> N = getNear(*it);
        it->giveN(N); 
        
        it->Behavior();
         
        if(it->getHealth()<=0){
            Location z = it->getLocation();
            Resource r = Resource(main,"img/Cdead.png",z);
            R.push_back(r);
            C.erase(it--);
        }
    }
}

vector<Entity*> List::getNear(Creature nC)
{
    vector<Entity*> N;

    for(vector <Resource>::iterator it = R.begin(); it!=R.end(); it++){
        if( nC.getBestSense() > Distance(nC.getLocation(),it->getLocation()) )
            N.push_back(&(*it));
    }
       
    for(vector <Creature>::iterator it = C.begin(); it!=C.end(); it++){
        if( &nC == &(*it))
            continue;
        else if( nC.getBestSense() > Distance(nC.getLocation(),it->getLocation()) )
            N.push_back(&(*it));
    }
               
    return N;
}


