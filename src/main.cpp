#include "main.h"

int main()
{
	Window main;
	Creature testcreature(main, "images/Cbasic.png");
	Resource testresource(main, "images/Rbasic.png");
	Event e;

	while(e.gRun())
	{
		while(e.Poll())
		{
			if(e.gEventType() == SDL_QUIT)
				e.off();
			//else if(e.gEventType() == SDL_KEYDOWN)
			//	eventHandle(e.gEvent());
		}
		main.Clear();
		testcreature.Place();
		testresource.Place();
		main.Render();
	}

	main.Destroy();
	return 0;
}
