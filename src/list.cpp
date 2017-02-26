#include "list.hpp"

List::List()
{
        int i;
        DNA d = DNA("creature");
        Rectangle tmp;
        for(i=0;i<CREATURES;i++){
                Organism X(tmp,d);
                creatures.push_back(X);
        }
        
        d = DNA("resource");
        for(i=0;i<RESOURCES;i++){
                Organism X(tmp, d);
                resources.push_back(X);
        }

        Rectangle R1    = Rectangle(0,0,60,60);
        tree            = Quadtree(0, R1);
}

void List::Remove()
{
        for(std::list<Organism>::iterator it = creatures.begin(); it!= creatures.end(); it++)    
                if(it->getHealth()<=0){
                        DNA d = DNA("resource");
                        Organism X(it->getRectangle(), d);
                        resources.push_back(X);
                        creatures.erase(it--);
                }

        for(std::list<Organism>::iterator it = resources.begin(); it!= resources.end(); it++)
                if(it->getHealth()<=0)
                        resources.erase(it--);
}

void List::Behavior()
{
        for(std::list<Organism>::iterator it = creatures.begin(); it!= creatures.end(); it++){
                std::vector<Organism*> near = getNear(*it); 
                it->giveNearMe(near); 
                it->Behavior();

                if(it->getPregnancyReady()){
                        Organism X(it->getRectangle(),it->getChildsDNA());
                        creatures.push_back(X);
                        it->hadPregnancy();
                }
        }

        for(std::list<Organism>::iterator it = resources.begin(); it!= resources.end(); it++)
                it->grow(); 
}

void List::Place()
{ 
        tree.clear();

        Rectangle tmp;
        DNA d = DNA("resource");
        while(resources.size() < MINIMUM_RESOURCES){
                Organism X(tmp, d);
                resources.push_back(X);
        }

        for(std::list<Organism>::iterator it = creatures.begin(); it!= creatures.end(); it++){
                it->Place();
                tree.insert(&(*it));;
        }

        for(std::list<Organism>::iterator it = resources.begin(); it!=resources.end(); it++){
                it->Place();
                tree.insert(&(*it));;
        }
}

std::vector<Organism*> List::getNear(Organism c)
{
        std::vector<Organism*> near;
        near = tree.retrieve(near, c.getGFXD()); 

        for(std::vector<Organism*>::iterator it = near.begin(); it!= near.end(); it++)
                if(c.getBestSense() < Distance(c.getRectangle(),(*it)->getRectangle()))
                        near.erase(it--);

        return near;
}

std::vector<GraphicsData> List::drawQuadTree()
{
        return tree.Draw();
}

