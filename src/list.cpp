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
                std::vector<Entity*> N = getNear(*it); 
                it->giveNearMe(N); 
                it->Behavior();

                if(it->getPregnancyReady()){
                        Creature X(it->getRectangle(),it->getChildsDNA());
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

std::vector<Entity*> List::getNear(Creature c)
{
        std::vector<Entity*> near;
        near = tree.retrieve(near, c.getGFXD()); 

        for(std::vector<Entity*>::iterator it = near.begin(); it!= near.end(); it++)
                if(c.getBestSense() < Distance(c.getRectangle(),(*it)->getRectangle()))
                        near.erase(it--);

        return near;
}

std::vector<GraphicsData> List::drawQuadTree(){
        return tree.Draw();
}

