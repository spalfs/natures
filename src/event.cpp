#include "event.hpp"

Event::Event()
{
	run = true;
}

int Event::Poll()
{
	SDL_PollEvent(&v);
}

void Event::off()
{
	run = false;
}

bool Event::gRun()
{
	return run;
}

SDL_Event& Event::gEvent()
{
	SDL_Event* x = &v;
	return *x;
}

int Event::gEventType()
{
	return v.type;
}
