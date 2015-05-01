#include "main.h"

int main()
{
	Window main;
	Entity ship(main, "images/basic.png");
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
		ship.Place();
		main.Render();
	}

	main.Destroy();
	return 0;
}
