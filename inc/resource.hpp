#ifndef resource_h
#define resource_h

#include <cstdlib>

#include "entity.hpp"
#include "functions.hpp"

class Resource: public Entity
{
        public:
                Resource(Rectangle r);

                void    grow();
                void    eat(int bite);

                int     getAmount(){return amount;};

        private:
                int     amount;
                int     growAmount;
};

#endif
