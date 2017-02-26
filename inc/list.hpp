#ifndef list_h
#define list_h

#include <list>
#include <vector>

#include "constants.hpp"
#include "creature.hpp"
#include "resource.hpp"
#include "quadtree.hpp"

class List
{
	public:
		List();
		void Behavior();
		void Place();
                void Remove();

                std::vector<Entity*>            getNear(Creature c);

                std::list<Resource>             resources;
                std::list<Creature>             creatures;

                Quadtree                        tree;
                std::vector<GraphicsData>       drawQuadTree();
};

#endif
