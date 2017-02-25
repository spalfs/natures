#include "list.hpp"

List::List()
{
        int i;
        DNA d;
        Rectangle tmp;
        for(i=0;i<CREATURES;i++){
                Creature X(tmp,d);
                creatures.push_back(X);
        }

        for(i=0;i<RESOURCES;i++){
                Resource Y(tmp);
                resources.push_back(Y);
        }

        Rectangle R1    = Rectangle(0,0,60,60);
        tree            = Quadtree(0, R1);
}

void List::Remove()
{
        for(std::list<Creature>::iterator it = creatures.begin(); it!= creatures.end(); it++)    
                if(it->getHealth()<=0){
                        Resource Y(it->getRectangle());
                        resources.push_back(Y);
                        creatures.erase(it--);
                }

        for(std::list<Resource>::iterator it = resources.begin(); it!= resources.end(); it++)
                if(it->getAmount()<=0)
                        resources.erase(it--);
}

void List::Behavior()
{
        for(std::list<Creature>::iterator it = creatures.begin(); it!= creatures.end(); it++){
                std::list<Entity*> N = getNear(*it); 
                it->giveNearMe(N); 
                it->Behavior();

                if(it->getPregnancyReady()){
                        DNA d           = it->getChildsDNA();
                        Rectangle tmp   = it->getRectangle();
                        Creature X(tmp,d);
                        creatures.push_back(X);
                        it->hadPregnancy();
                }
        }

        for(std::list<Resource>::iterator it = resources.begin(); it!= resources.end(); it++)
                it->grow(); 
}

void List::Place()
{ 
        tree.clear();

        Rectangle tmp;
        while(resources.size() < MINIMUM_RESOURCES){
                Resource Y(tmp);
                resources.push_back(Y);
        }

        for(std::list<Creature>::iterator it = creatures.begin(); it!= creatures.end(); it++){
                it->Place();
                tree.insert(&(*it));;
        }

        for(std::list<Resource>::iterator it = resources.begin(); it!=resources.end(); it++){
                it->Place();
                tree.insert(&(*it));;
        }
}

std::list<Entity*> List::getNear(Creature nC)
{
        std::list<Entity*> N;
        N = tree.retrieve(N, nC.getGFXD()); 

        return N;
}

std::vector<GraphicsData> List::drawQuadTree(){
        return tree.Draw();
}

