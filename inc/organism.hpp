#ifndef organism_h
#define organism_h

#include <vector>
#include <algorithm>

#include "dna.hpp"
#include "rectangle.hpp"
#include "functions.hpp"

#include "opengl/graphicsdata.hpp"

class Organism
{
        public:
                Organism(Rectangle r, DNA d);

                void            Behavior();
                void            Action();
                void            Priority();
                void            Place();
                void            setTarget();
                void            checkTarget();
                void            moveTowards(Rectangle r);
                void            passDNA(DNA d);
                void            giveNearMe(std::vector<Organism*> n){nearMe = n;};
                void            grow();
                void            takeBite(int bite);
                void            hadPregnancy(){pregnate = pregnancyReady = false;};

                DNA             getDNA()                {return myDNA;};
                DNA             getChildsDNA()          {return childsDNA;};
                GraphicsData    getGFXD()               {return gfxData;};    
                Rectangle       getRectangle()          {return rect;};
                int             getHealth()             {return health;};
                int             getBestSense()          {return myDNA.bestSense;};
                int             getType()               {return myDNA.type;};
                bool            getGender()             {return gender;};
                bool            getPregnancyReady()     {return pregnancyReady;};

        private:
                Rectangle               wTarget;
                Organism*               target;
                std::vector<Organism*>  nearMe;
                DNA                     myDNA;
                DNA                     childsDNA;
                Rectangle               rect;
                GraphicsData            gfxData;

                int                     health; 
                int                     pregnancyTime;
                int                     age;
                
                bool                    gender;
                bool                    pregnate;
                bool                    hungry; 
                bool                    pregnancyReady;
                bool                    able;     
                bool                    hasTarget;
                bool                    wander;
};

#endif
