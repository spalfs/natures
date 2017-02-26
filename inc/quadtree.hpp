#ifndef quadtree_h
#define quadtree_h

#include <vector>

#include "constants.hpp"
#include "organism.hpp"
#include "rectangle.hpp"

#include "opengl/graphicsdata.hpp"
#include "sdl/window.hpp"

class Quadtree {
        public:
                Quadtree();
                Quadtree(int pLevel,Rectangle pBounds);

                void clear();
                void insert(Organism* iter);

                std::vector<Organism*> retrieve(std::vector<Organism*> returnObject, GraphicsData obj);
                std::vector<Organism*> objects;

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
