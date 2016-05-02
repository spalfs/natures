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
		double Distance(Location A, Location B){return sqrt(pow(A.x-B.x,2)+pow(A.y-B.y,2));};

	private:
		//vectors containing objects of each type
		Window main = Window("no");//will be needed for adding R's and C's after constructor.
		vector<Resource> R;
		vector<Creature> C;
};

#endif
