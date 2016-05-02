#ifndef timer_h
#define timer_h

#include "window.hpp"

class Timer
{
 public:
    Timer();
    void Start();
    void Stop();
    void Pause();
    void unPause();
    int getTicks();
    bool isStarted(){return started;};
    bool isPaused(){return paused;};

 private:
    int startTicks;
    int pausedTicks;
    bool paused;
    bool started;
};

#endif
