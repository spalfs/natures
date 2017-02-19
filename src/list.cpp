#include "list.hpp"

List::List()
{
    int i;
    Dna defaultDNA;
    //SDL_Rect rect = {0,0,defaultDNA.sizeMax/5,defaultDNA.sizeMax/5};
    Location tmp;
    tmp.x = tmp.y = 0;
    for(i=0;i<CREATURES;i++){
        Creature X(tmp,defaultDNA);
        C.push_back(X);
    }

    //rect = {0,0,RESOURCE_SIZE_START,RESOURCE_SIZE_START};
    for(i=0;i<RESOURCES;i++){
        Resource Y(tmp);
        R.push_back(Y);
    }

    R1 = Rectangle(0,0,60,60);
    tree = Quadtree(0,R1);
}

void List::Remove()
{
    for(std::list<Creature>::iterator it = C.begin(); it!=C.end(); it++)    
        if(it->getHealth()<=0){
            Location tmp = it->getLocation();
            Resource r = Resource(tmp);
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
        std::list<Entity*> N = getNear(*it); 
        it->giveN(N); 
        it->Behavior();
        
        if(it->getPregnancyReady()){
            Dna D  = it->getChildDNA();
            Location tmp = it->getLocation();
            Creature X(tmp,D);
            C.push_back(X);
            it->hadPregnancy();
        }
    }
    
    for(std::list<Resource>::iterator it = R.begin(); it!=R.end(); it++)
        it->grow(); 
}

void List::Place()
{ 
    tree.clear();

    Location tmp;
    tmp.x = tmp.y = 0;
    while(R.size() < MINIMUM_RESOURCES){
        Resource Y(tmp);
        R.push_back(Y);
    }

    for(std::list<Creature>::iterator it = C.begin(); it!=C.end(); it++){
        it->Place();
        tree.insert(&(*it));;
    }

    for(std::list<Resource>::iterator it = R.begin(); it!=R.end(); it++){
        it->Place();
        tree.insert(&(*it));;
    }
}

std::list<Entity*> List::getNear(Creature nC)
{
    std::list<Entity*> N;
    N.clear();
    N = tree.retrieve(N, nC.getGFXD()); 

    //std::vector<Entity*> x{std::begin(N),std::begin(N)};
    return N;
}

std::vector<GraphicsData> List::drawQuadTree(){
    return tree.Draw();
}


