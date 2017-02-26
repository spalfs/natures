#ifndef list_h
#define list_h

#include <list>
#include <vector>

#include "constants.hpp"
#include "organism.hpp"
#include "quadtree.hpp"

class List
{
	public:
		List();
		void                            Behavior();
		void                            Place();
                void                            Remove();

                std::vector<Organism*>          getNear(Organism o);

                std::list<Organism>             resources;
                std::list<Organism>             creatures;

                Quadtree                        tree;
                std::vector<GraphicsData>       drawQuadTree();
};

#endif
