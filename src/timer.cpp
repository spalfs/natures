#include "timer.hpp"

Timer::Timer()
{
    startTicks = 0;
    pausedTicks= 0;
    paused = false;
    started = false;
}

void Timer::Start()
{
    started = true;
    paused = false;
    startTicks = SDL_GetTicks();
}

void Timer::Stop()
{
    started =false;
    paused = false;
}

void Timer::Pause()
{
    if ((started == true) && (paused == false )){
        paused = true;
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void Timer::unPause()
{
    if (paused){
        paused = false;
        startTicks = SDL_GetTicks() - pausedTicks;
        pausedTicks = 0;
    }
}

int Timer::getTicks()
{
    if(started){
        if (paused)
            return pausedTicks;
        else
            return SDL_GetTicks() - startTicks;
    }
    else
        return 0;
}
