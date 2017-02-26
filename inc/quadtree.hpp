#ifndef quadtree_h
#define quadtree_h

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

                std::vector<Entity*> retrieve(std::vector<Entity*> returnObject, GraphicsData obj);
                std::vector<Entity*> objects;

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
