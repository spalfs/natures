#ifndef entity_h
#define entity_h

#include <SDL2/SDL.h>

#include "dna.hpp"
#include "graphicsobjects.hpp"
#include "rectangle.hpp"

class Entity
{
        public:
                void            Place(); 
                
                virtual void    eat(int bite){};
                virtual void    impregnate(DNA D){};

                int             getType(){return type;};
                virtual bool    getGender(void){};
                virtual int     getAmount(void){}; 
                Rectangle       getRectangle(){return L;};
                GraphicsData    getGFXD(){return gfxData;};


        protected:
                int             type;
                int             gender;
                bool            pregnate;
                Rectangle       L;
                GraphicsData    gfxData;
};

#endif
