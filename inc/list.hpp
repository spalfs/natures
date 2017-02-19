#ifndef list_h
#define list_h

#include <SDL2/SDL.h>
#include <list>
#include <vector>

#include "functions.hpp"
#include "creature.hpp"
#include "resource.hpp"
#include "window.hpp"
#include "constants.hpp"
#include "rectangle.hpp"
#include "quadtree.hpp"

class List
{
	public:
		List();
		void Behavior();
		void Place();
        void Remove();
        std::list<Entity*> getNear(Creature C);
        std::list<Resource> R;
        std::list<Creature> C;

        Quadtree tree;
        std::vector<GraphicsData> drawQuadTree();
        Rectangle R1;
};

#endif
