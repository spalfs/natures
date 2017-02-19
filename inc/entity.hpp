#ifndef entity_h
#define entity_h

#include <SDL2/SDL.h>

#include "dna.hpp"
#include "graphicsobjects.hpp"

class Entity
{
	public:
		void            Place();
 
        int             getType(){return type;};
        virtual bool    getGender(void){};
        virtual int     getAmount(void){}; 
        Location        getLocation(){return L;};
        
        virtual void    eat(int bite){};
        virtual void    impregnate(Dna D){};
        GraphicsData    getGFXD(){return gfxData;};
        GraphicsData    gfxData;

	protected:
		int             type;
        int             gender;
        bool            pregnate;
        Location        L;
};

#endif
