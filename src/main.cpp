#include "main.h"

int main()
{
	Window main;
	Creature testcreature(main, "img/Cbasic.png");
	Resource testresource(main, "img/Rbasic.png");
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
		testcreature.Behavior();
		testcreature.Place();
		testresource.Place();
		main.Render();
	}

	main.Destroy();
	return 0;
}
