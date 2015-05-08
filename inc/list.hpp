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
		double Distance(Location A, Location B);

	private:
		//vectors containing objects of each type
		std::vector<Resource> R;
		std::vector<Creature> C;
		std::vector<Location> L;
};

#endif
