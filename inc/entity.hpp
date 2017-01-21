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
        virtual void impregnate(void){};
        virtual bool getGender(void){};
        virtual int  getAmount(void){}; 

	protected:
		int type;
        int gender;
        bool pregnate;
        SDL_Rect rect;
		SDL_Renderer* renderer;
};

#endif
