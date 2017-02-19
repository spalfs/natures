#ifndef rectangle_h
#define rectangle_h

class Rectangle
{
        public:
                Rectangle(){x=y=w=h=0;}; 
                Rectangle(float x1, float y1, float w1, float h1){x=x1;y=y1;w=w1;h1=h;};
                float x;
                float y;
                float w;
                float h;
};

#endif
