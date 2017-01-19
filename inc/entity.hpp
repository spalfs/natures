#ifndef entity_h
#define entity_h

#include "window.hpp"

class Entity
{
	public:
		void Place();

        int getType(){return type;};
        SDL_Rect getRect(){return rect;};
        
        virtual void eat(int bite){};
        virtual int getAmount(void){}; 

	protected:
		int type;
        SDL_Rect rect;
		SDL_Renderer* renderer;
};

#endif
