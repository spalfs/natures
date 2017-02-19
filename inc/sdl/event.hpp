#ifndef event_h
#define event_h

#include <SDL2/SDL.h>

class Event
{
        public:
	        Event();

		int             Poll();
		void            off();
		bool            gRun();
		SDL_Event&      gEvent();
		int             gEventType();

	private:
		bool            run;
		SDL_Event       v;
};

#endif
