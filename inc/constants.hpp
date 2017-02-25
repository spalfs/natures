#ifndef constants_h
#define constants_h

// General
const int   CREATURES                   = 100;
const int   RESOURCES                   = 1000;
const int   MINIMUM_RESOURCES           = 800;
const int   WINDOW_X                    = 1000;
const int   WINDOW_Y                    = 1000;

// Types
const int   CREATURE_TYPE               = 1;
const int   RESOURCE_TYPE               = 2;

// Creatures
const int   CREATURE_MAX_HEALTH         = 1000;
const int   CREATURE_REACH              = 1;
const int   CREATURE_BEST_SENSE         = 1;
const int   CREATURE_BITE               = 10;
const int   CREATURE_AMOUNT_TO_GROW     = 50;
const int   CREATURE_EXP_PREG_TIME      = 100;
const int   CREATURE_EXP_AGE            = 1000000;
const int   CREATURE_SIZE_MAX           = 10;
const float CREATURE_SPEED              = .1;

// Resource
const int   RESOURCE_SIZE_START         = 1;
const int   RESOURCE_SIZE_MAX           = 4;
const int   RESOURCE_AMOUNT_START       = 100;
const int   RESOURCE_AMOUNT_MAX         = 200;
const int   RESOURCE_GROW               = 1;

// Opengl
const int   NUM_SHADERS                 = 3;
const int   NUM_UNIFORMS                = 3;
const float CREATURE_SIDES              = 4.0;
const float RESOURCE_SIDES              = 10;

// Quadtree 
const int   MAX_OBJECTS                 = 5;
const int   MAX_LEVELS                  = 6;

// Camera
const float MOVE_AMOUNT                 = .2;                     

#endif
