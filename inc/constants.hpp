#ifndef constants_h
#define constants_h

// General
const int   HERBAVORES                  = 100;
const int   CARNIVORES                  = 50;;
const int   MINIMUM_PLANTS              = 4000;
const int   PLANTS                      = 5000;
const int   WINDOW_X                    = 1000;
const int   WINDOW_Y                    = 1000;
const float BOUNDS                      = 30;

// Types
const int   HERBAVORE_TYPE              = 1;
const int   CARNIVORE_TYPE              = 2;
const int   PLANT_TYPE                  = 3;
const int   CORPSE_TYPE                 = 4;

// Creature stats
const int   CREATURE_MAX_HEALTH         = 100;
const int   CREATURE_BEST_SENSE         = 2;
const int   CREATURE_BITE               = 5;
const int   CREATURE_EXP_PREG_TIME      = 1000;
const int   CREATURE_EXP_AGE            = 10000;
const int   CREATURE_HUNGRY_AMOUNT      = 50;
const int   CREATURE_STARVE_AMOUNT      = 90;
const float CREATURE_SPEED              = .05;
const float CREATURE_REACH              = .1;
const float CREATURE_MUTATION_PERCENT   = .25;
const float CREATURE_MUTATION_CHANCE    = .05;

// Plant Stats
const int   PLANT_MAX_HEALTH            = 200;
const int   PLANT_GROW_AMOUNT           = 1;

// Corpse Stats
const int  CORPSE_MAX_HEALTH            = 400;
const int  CORPSE_DECAY_AMOUNT          = -1;

// Opengl
const int   NUM_SHADERS                 = 3;
const int   NUM_UNIFORMS                = 3;
const float SIDES                       = 5;

// Quadtree 
const int   MAX_OBJECTS                 = 5;
const int   MAX_LEVELS                  = 20;

// Camera
const float MOVE_AMOUNT                 = .2;                     

#endif
