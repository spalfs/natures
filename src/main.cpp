#include "main.hpp"

int main()
{
    srand(time(NULL));
	Window main;
	List L(main);
	Event e;

    Timer fps;
    int speed = 60;

	while(e.gRun())
	{
        fps.Start();

		while(e.Poll())
		{
			if(e.gEventType() == SDL_QUIT)
				e.off();
			else if(e.gEventType() == SDL_KEYDOWN)
                switch(e.gEvent().key.keysym.sym){
                    case SDLK_q:        e.off();                    break;
                    case SDLK_EQUALS:   speed+=30;                  break;
                    case SDLK_MINUS:    if(speed >30) speed-=30;    break;
                }
		}

		main.Clear();
        
        L.Remove();
        L.Behavior();
		L.Place();

		main.Render();
		
        if(fps.getTicks() < (1000 / speed))
            SDL_Delay((1000 / speed) - fps.getTicks());
	}

	main.Destroy();
	return 0;
}
