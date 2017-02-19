#ifndef graphicsdata_h
#define graphicsdata_h

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include "camera.hpp"

class GraphicsData
{
  public:

    float x;
    float y;
    float r;
    float g;
    float b;
    float sides;

    GraphicsData(){
		this->x = 0;
		this->y = 0;
		this->r = 0;
		this->g = 0;
		this->b = 0;
		this->sides = 0;
	}


    GraphicsData(float x,float y,float r,float g,float b,float sides){
		this->x = 0;
		this->y = 0;
		this->r = 0;
		this->g = 0;
		this->b = 0;
		this->sides = 0;
	}

	float getX(){
		return x;
	}
	
	float getY(){
		return y;
	}

};

#endif
