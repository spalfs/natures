#ifndef functions_h
#define functions_h

#include <cstdlib>
#include <cmath>

#include "rectangle.hpp"

static double Distance(Rectangle A, Rectangle B){
        return sqrt(pow(A.x-B.x,2) + pow(A.y-B.y,2));
}

static int map(int x, int inMin, int inMax, int outMin, int outMax){
        return (x-inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}

static float getRandom(float x){
        return (-x + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(x-(-x)))));
}

static bool roll(float x){
        float y = (float)(rand()%101)/100;
        if(x >= y)
                return true;
        else
                return false;
}
#endif
