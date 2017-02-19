#ifndef graphicsobjects_h
#define graphicsobjects_h

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>


struct Camera
{
public:
	Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar)
	{
		this->pos = pos;
		this->forward = glm::vec3(0.0f, 0.0f, -1.0f);
		this->up = glm::vec3(0.0f, 1.0f, 0.0f);
		this->projection = glm::perspective(fov, aspect, zNear, zFar);
	}

	inline glm::mat4 GetViewProjection() const
	{
		return projection * glm::lookAt(pos, pos + forward, up);
	}

	void MoveForward()
	{
		pos += forward * amt;
	}

	void MoveBackward()
	{
		pos += forward * -amt;
	}

	void MoveRight()
	{
		pos += -glm::cross(up, forward) * amt;
	}

	void MoveLeft()
	{
		pos += glm::cross(up, forward) * amt;
	}

	void MoveUp()
	{
		//pos += glm::cross(up, forward) * amt;
		pos += glm::vec3(0,.2,0);
	}

	void MoveDown()
	{
		//pos += glm::cross(up, forward) * amt;
		pos -= glm::vec3(0,.2,0);
	}

	void Pitch(float angle)
	{
		glm::vec3 right = glm::normalize(glm::cross(up, forward));

		forward = glm::vec3(glm::normalize(glm::rotate(angle, right) * glm::vec4(forward, 0.0)));
		up = glm::normalize(glm::cross(forward, right));
	}

	/*void RotateY(float angle)
	{
		static const glm::vec3 UP(0.0f, 1.0f, 0.0f);

		glm::mat4 rotation = glm::rotate(angle, UP);

		forward = glm::vec3(glm::normalize(rotation * glm::vec4(forward, 0.0)));
		up = glm::vec3(glm::normalize(rotation * glm::vec4(up, 0.0)));
	}*/

private:
	float amt = .2;
	//glm::vec3 speed = glm::vec3(0,0,0.2);
	glm::mat4 projection;
	glm::vec3 pos;
	glm::vec3 forward;
	glm::vec3 up;
};



struct Transform
{
public:
	Transform(const glm::vec3& pos = glm::vec3(), const glm::vec3& rot = glm::vec3(), const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f))
	{
		this->pos = pos;
		this->rot = rot;
		this->scale = scale;
	}

	inline glm::mat4 GetModel() const
	{
		glm::mat4 posMat = glm::translate(pos);
		glm::mat4 scaleMat = glm::scale(scale);
		glm::mat4 rotX = glm::rotate(rot.x, glm::vec3(1.0, 0.0, 0.0));
		glm::mat4 rotY = glm::rotate(rot.y, glm::vec3(0.0, 1.0, 0.0));
		glm::mat4 rotZ = glm::rotate(rot.z, glm::vec3(0.0, 0.0, 1.0));
		glm::mat4 rotMat = rotX * rotY * rotZ;

		return posMat * rotMat * scaleMat;
	}

	inline glm::mat4 GetMVP(const Camera& camera) const
	{
		glm::mat4 VP = camera.GetViewProjection();
		glm::mat4 M = GetModel();

		return VP * M;//camera.GetViewProjection() * GetModel();
	}

	inline glm::vec3* GetPos() { return &pos; }
	inline glm::vec3* GetRot() { return &rot; }
	inline glm::vec3* GetScale() { return &scale; }

	inline void SetPos(glm::vec3& pos) { this->pos = pos; }
	inline void SetRot(glm::vec3& rot) { this->rot = rot; }
	inline void SetScale(glm::vec3& scale) { this->scale = scale; }
protected:
private:
	glm::vec3 pos;
	glm::vec3 rot;
	glm::vec3 scale;
};






class Location
{
  public:
  	Location(float x1, float y1){x=x1;y=y1; w=5; h=5;};
    Location(){x=y=0; w=5; h=5;};
	
	float getX(){
		return x;
	}
	
	float getY(){
		return y;
	}
	
    float x;
    float y;
	float w;
    float h;
};


class GraphicsData
{
  public:

    float x;
    float y;
    float r;
    float g;
    float b;
    float sides;
    //float theret[6];
    //float* ret[6];

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


class Rectangle
{
  public:
  	Rectangle(float x1, float y1, float wid, float heit){x=x1;y=y1;width=wid; height=heit;};
    Rectangle(){x=y=width=height=0;};


	void setX(float x1){
		x=x1;
	}
	
	void setY(float y1){
		y=y1;
	}


	
	float getX(){
		return x;
	}
	
	float getY(){
		return y;
	}
	
	float getWidth(){
		return width;
	}
	
	float getHeight(){
		return height;
	}
	
    float x;
    float y;
	float width;
	float height;
};

#endif