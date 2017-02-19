#ifndef entity_h
#define entity_h

#include "dna.hpp"
#include "rectangle.hpp"

#include "opengl/graphicsdata.hpp"

class Entity
{
        public:
                void            Place(); 
                
                virtual void    eat(int bite){};
                virtual void    impregnate(DNA D){};

                int             getType(){return type;};
                virtual bool    getGender(void){};
                virtual int     getAmount(void){}; 
                Rectangle       getRectangle(){return rect;};
                GraphicsData    getGFXD(){return gfxData;};


        protected:
                int             type;
                int             gender;
                bool            pregnate;
                Rectangle       rect;
                GraphicsData    gfxData;
};

#endif
