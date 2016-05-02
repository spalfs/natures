#include "list.hpp"

List::List(Window m)
{
  int i;

  for(i=0;i<10;i++)
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
        it->Behavior();

        vector<Resource*> N;
        for(vector <Resource>::iterator jt = R.begin(); jt!=R.end(); jt++){
            if( it->getBestSense() > Distance(it->getLocation(),jt->getLocation()) )
                N.push_back(&(*jt));
        }
        it->giveR(N);
        
        vector<Creature*> M;
        for(vector <Creature>::iterator jt = C.begin(); jt!=C.end(); jt++){
            if( jt == it)
                continue;
            else if( it->getBestSense() > Distance(it->getLocation(),jt->getLocation()) )
                M.push_back(&(*jt));
        }
        it->giveC(M);
        
        M.clear();
        N.clear();

        if(it->getHealth()<=0){
            Location z = it->getLocation();
            Resource r = Resource(main,"img/Cdead.png",z);
            R.push_back(r);
            C.erase(it--);
        }
    }
}
