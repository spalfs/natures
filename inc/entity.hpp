#ifndef entity_h
#define entity_h

#include "window.hpp"
#include "location.hpp"

class Entity
{
	public:
        void Init(Window m);
        void Init(Window m, Location z);
		void Place();

        int getType(){return type;};
        Location getLocation(){return L;};
        SDL_Rect getRect(){return rect;};
        
        virtual void eat(void){};
        virtual int getAmount(void){}; 

	protected:
		int type;
        SDL_Rect rect;
        Location L;
		SDL_Renderer* renderer;
};

#endif
