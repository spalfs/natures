#include "list.hpp"

List::List(Window m)
{
  main = m;

  int i;
  SDL_Rect Rect = {0,0,CREATURE_SIZE_START,CREATURE_SIZE_START};
  for(i=0;i<CREATURES;i++){
    Creature X(main,Rect);
    C.push_back(X);
  }

  Rect = {0,0,RESOURCE_SIZE_START,RESOURCE_SIZE_START};
  for(i=0;i<RESOURCES;i++){
    Resource Y(main,Rect);
    R.push_back(Y);
  }

}

void List::Remove()
{
    for(list<Creature>::iterator it = C.begin(); it!=C.end(); it++)    
        if(it->getHealth()<=0){
            SDL_Rect Rect = it->getRect();
            Resource r = Resource(main,Rect);
            R.push_back(r);
            C.erase(it--);
        }
    
    for(list<Resource>::iterator it = R.begin(); it!=R.end(); it++)
        if(it->getAmount()<=0)
            R.erase(it--);
}

void List::Behavior()
{
    for(list<Creature>::iterator it = C.begin(); it!=C.end(); it++){
        list<Entity*> N = getNear(*it); 
        it->giveN(N); 
        it->Behavior();
        if(it->getPregnancyReady()){
            SDL_Rect Rect = it->getRect();
            Rect.h = Rect.w = CREATURE_SIZE_START; 
            Creature X(main,Rect);
            C.push_back(X);
            it->hadPregnancy();
        }
    }
    
    for(list<Resource>::iterator it = R.begin(); it!=R.end(); it++)
        it->grow(); 
}

void List::Place()
{ 
    SDL_Rect Rect = {0,0,RESOURCE_SIZE_START,RESOURCE_SIZE_START};
    while(R.size() < MINIMUM_RESOURCES){
        Resource Y(main,Rect);
        R.push_back(Y);
    }

    for(list<Creature>::iterator it = C.begin(); it!=C.end(); it++)
        it->Place();

    for(list<Resource>::iterator it = R.begin(); it!=R.end(); it++)
        it->Place();
}

list<Entity*> List::getNear(Creature nC)
{
    list<Entity*> N;

    for(list <Resource>::iterator it = R.begin(); it!=R.end(); it++)
        if( nC.getBestSense() > Distance(nC.getRect(),it->getRect()) )
            N.push_back(&(*it));
        
    for(list <Creature>::iterator it = C.begin(); it!=C.end(); it++)
        if( &nC == &(*it))
            continue;
        else if( nC.getBestSense() > Distance(nC.getRect(),it->getRect()) )
            N.push_back(&(*it));
                
    return N;
}


