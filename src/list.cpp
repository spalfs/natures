#include "list.hpp"

List::List()
{
        int i;
        DNA d = DNA("herbavore");
        Rectangle tmp;
        for(i=0;i<HERBAVORES;i++){
                Organism X(tmp,d);
                creatures.push_back(X);
        }
        
        d = DNA("carnivore");
        for(i=0;i<CARNIVORES;i++){
                Organism X(tmp, d);
                creatures.push_back(X);
        }
        
        d = DNA("plant");
        for(i=0;i<PLANTS;i++){
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
                        DNA d = DNA("plant");
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
        DNA d = DNA("plant");
        while(resources.size() < MINIMUM_PLANTS){
                Organism X(tmp, d);
                resources.push_back(X);
        }

        for(std::list<Organism>::iterator it = creatures.begin(); it!= creatures.end(); it++)
                tree.insert(&(*it));;
        
        for(std::list<Organism>::iterator it = resources.begin(); it!=resources.end(); it++)
                tree.insert(&(*it));;
        
}

std::vector<Organism*> List::getNear(Organism c)
{
        std::vector<Organism*> near;
        near = tree.retrieve(near, c.getRectangle()); 

        for(std::vector<Organism*>::iterator it = near.begin(); it!= near.end(); it++)
                if(c.getBestSense() < Distance(c.getRectangle(),(*it)->getRectangle()))
                        near.erase(it--);

        return near;
}

std::vector<Rectangle> List::drawQuadTree()
{
        return tree.Draw();
}

