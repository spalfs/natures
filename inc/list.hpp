#ifndef list_h
#define list_h

#include <SDL2/SDL.h>
#include <list>

#include "functions.hpp"
#include "creature.hpp"
#include "resource.hpp"
#include "window.hpp"
#include "constants.hpp"

class List
{
	public:
		List(Window m);
		void Behavior();
		void Place();
        void Remove();
        list<Entity*> getNear(Creature C);

	private:
		Window main = Window("do not create new window.");
		list<Resource> R;
		list<Creature> C;
};

#endif
