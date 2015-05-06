#ifndef list_h
#define list_h

#include "creature.hpp"
#include "resource.hpp"
#include "window.hpp"
#include "location.hpp"

class List
{
	public:
		List(Window m);
		void Behavior();
		void Place();

	private:
		//Window main;
		std::vector<Resource> R;
		std::vector<Creature> C;
		std::vector<Location> L;
};

#endif
