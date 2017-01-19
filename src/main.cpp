#include "main.hpp"

int main()
{
    srand(time(NULL));
	Window main;
	List L(main);
	Event e;

    Timer fps;

	while(e.gRun())
	{
        fps.Start();

		while(e.Poll())
		{
			if(e.gEventType() == SDL_QUIT)
				e.off();
			//else if(e.gEventType() == SDL_KEYDOWN)
			//	eventHandle(e.gEvent());
		}

		main.Clear();
        
        L.Remove();
        L.Behavior();
		L.Place();

		main.Render();
		
        if(fps.getTicks() < (1000 / 60))
            SDL_Delay((1000 / 60) - fps.getTicks());
	}

	main.Destroy();
	return 0;
}
