#ifndef functions_h
#define functions_h

static double Distance(SDL_Rect A, SDL_Rect B){
    return sqrt( pow(A.x-B.x,2) + pow(A.y-B.y,2));
}

static int map(int x, int inMin, int inMax, int outMin, int outMax){
    return (x-inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}

#endif
