#ifndef timer_h
#define timer_h

#include <SDL2/SDL.h>

class Timer
{
        public:
                Timer();

                void    Start();
                void    Stop();
                void    Pause();
                void    unPause();

                int     getTicks();
                bool    getStarted(){return started;};
                bool    getPaused(){return paused;};

        private:
                int     startTicks;
                int     pausedTicks;
                bool    paused;
                bool    started;
};

#endif
