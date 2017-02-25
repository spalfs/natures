#ifndef creature_h
#define creature_h

#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>

#include "entity.hpp"
#include "functions.hpp"

class Creature: public Entity
{
        public:
                Creature(Rectangle r, DNA d);

                void    Behavior();
                void    Action();
                void    Priority();
                void    setTarget();
                void    checkTarget();
                void    moveTowards(Rectangle r);
                void    impregnate(DNA d);
                void    giveNearMe(std::list<Entity*> n){nearMe = {std::begin(n),std::end(n)};};

                DNA     getDNA(){return myDNA;};
                DNA     getChildsDNA(){return childsDNA;};
                int     getHealth(){return health;};
                int     getBestSense(){return myDNA.bestSense;};
                bool    getGender(){return gender;};
                bool    getPregnancyReady(){return pregnancyReady;};
                void    hadPregnancy(){pregnate = pregnancyReady = false;};

        private:
                Rectangle               wTarget;
                Entity*                 target;
                std::vector<Entity*>    nearMe;
                DNA                     myDNA;
                DNA                     childsDNA;

                int                     health; 
                int                     amountAte;
                int                     pregnancyTime;
                int                     age;

                bool                    hungry; 
                bool                    pregnancyReady;
                bool                    able;     
                bool                    hasTarget;
                bool                    wander;
};

#endif
