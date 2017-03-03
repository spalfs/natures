#ifndef quadtree_h
#define quadtree_h

#include <vector>

#include "constants.hpp"
#include "organism.hpp"
#include "rectangle.hpp"

#include "sdl/window.hpp"

class Quadtree {
        public:
                Quadtree();
                Quadtree(int pLevel, Rectangle pBounds);

                void clear();
                void insert(Organism* iter);

                std::vector<Organism*> retrieve(std::vector<Organism*> returnObject, Rectangle obj);
                std::vector<Organism*> objects;

                Quadtree* nodes;

                std::vector<Rectangle> Draw();

        private:
                void    split();
                int     getIndex(Rectangle object);
                int     level;
                bool    isNull = true;

                Rectangle rect;
                Rectangle bounds;
};

#endif
