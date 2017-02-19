#ifndef quadtree_h
#define quadtree_h

#include <list>
#include <vector>

#include "constants.hpp"
#include "creature.hpp"
#include "resource.hpp"
#include "entity.hpp"
#include "rectangle.hpp"

#include "opengl/graphicsdata.hpp"
#include "sdl/window.hpp"

class Quadtree {
        public:
                Quadtree();
                Quadtree(int pLevel,Rectangle pBounds);

                void clear();
                void insert(Entity* iter);

                std::list<Entity*> retrieve(std::list<Entity*> returnObject, GraphicsData obj);
                std::list<Entity*> objects;

                Quadtree* nodes;

                std::vector<GraphicsData> Draw();

        private:
                void    split();
                int     getIndex(GraphicsData object);
                int     level;
                bool    isNull = true;

                GraphicsData gfxDataRect;
                Rectangle bounds;
};

#endif
