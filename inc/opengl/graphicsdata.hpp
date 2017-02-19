#ifndef graphicsdata_h
#define graphicsdata_h

class GraphicsData
{
        public:
                GraphicsData(){
                        this->x = 0;
                        this->y = 0;
                        this->r = 0;
                        this->g = 0;
                        this->b = 0;
                        this->sides = 0;
                }

                GraphicsData(float x1, float y1, float r1, float g1, float b1, float sides1){
                        this->x = x1;
                        this->y = y1;
                        this->r = r1;
                        this->g = g1;
                        this->b = b1;
                        this->sides = sides1;
                }
                
                float x;
                float y;
                float r;
                float g;
                float b;
                float sides;
};

#endif
