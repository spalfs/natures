#include "main.hpp"

int main()
{
	Window main;
	List L(main);
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

		L.Place();
		L.Behavior();

		main.Render();
		SDL_Delay(10);
	}

	main.Destroy();
	return 0;
}
