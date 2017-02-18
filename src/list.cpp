#include "list.hpp"

List::List(Window m)
{
  main = m;

  int i;
  Dna defaultDNA;
  SDL_Rect Rect = {0,0,defaultDNA.sizeMax/5,defaultDNA.sizeMax/5};
  for(i=0;i<CREATURES;i++){
    Creature X(main,Rect,defaultDNA);
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
    for(std::list<Creature>::iterator it = C.begin(); it!=C.end(); it++)    
        if(it->getHealth()<=0){
            SDL_Rect Rect = it->getRect();
            Resource r = Resource(main,Rect);
            R.push_back(r);
            C.erase(it--);
        }
    
    for(std::list<Resource>::iterator it = R.begin(); it!=R.end(); it++)
        if(it->getAmount()<=0)
            R.erase(it--);
}

void List::Behavior()
{
    for(std::list<Creature>::iterator it = C.begin(); it!=C.end(); it++){
        std::vector<Entity*> N = getNear(*it); 
        it->giveN(N); 
        it->Behavior();
        
        if(it->getPregnancyReady()){
            Dna D  = it->getChildDNA();
            SDL_Rect Rect = it->getRect();
            Rect.h = Rect.w = D.sizeMax / 5; 
            Creature X(main,Rect,D);
            C.push_back(X);
            it->hadPregnancy();
        }
    }
    
    for(std::list<Resource>::iterator it = R.begin(); it!=R.end(); it++)
        it->grow(); 
}

void List::Place()
{ 
    SDL_Rect Rect = {0,0,RESOURCE_SIZE_START,RESOURCE_SIZE_START};
    while(R.size() < MINIMUM_RESOURCES){
        Resource Y(main,Rect);
        R.push_back(Y);
    }

    for(std::list<Creature>::iterator it = C.begin(); it!=C.end(); it++)
        it->Place();

    for(std::list<Resource>::iterator it = R.begin(); it!=R.end(); it++)
        it->Place();
}

std::vector<Entity*> List::getNear(Creature nC)
{
    std::vector<Entity*> N;

    for(std::list<Resource>::iterator it = R.begin(); it!=R.end(); it++)
        if( nC.getBestSense() > Distance(nC.getRect(),it->getRect()) )
            N.push_back(&(*it));
        
    for(std::list<Creature>::iterator it = C.begin(); it!=C.end(); it++)
        if( &nC == &(*it))
            continue;
        else if( nC.getBestSense() > Distance(nC.getRect(),it->getRect()) )
            N.push_back(&(*it));

    return N;
}


