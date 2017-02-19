#ifndef camera_h
#define camera_h

#include "constants.hpp"

struct Camera
{
        public:
                Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar){
                        this->pos = pos;
                        this->forward = glm::vec3(0.0f, 0.0f, -1.0f);
                        this->up = glm::vec3(0.0f, 1.0f, 0.0f);
                        this->projection = glm::perspective(fov, aspect, zNear, zFar);
                }

                inline glm::mat4 GetViewProjection() const {
                        return projection * glm::lookAt(pos, pos + forward, up);
                }

                void MoveForward(){
                        pos += forward * MOVE_AMOUNT;
                }

                void MoveBackward(){
                        pos += forward * -MOVE_AMOUNT;
                }

                void MoveRight(){
                        pos += -glm::cross(up, forward) * MOVE_AMOUNT;
                }

                void MoveLeft(){
                        pos += glm::cross(up, forward) * MOVE_AMOUNT;
                }

                void MoveUp(){
                        pos += glm::vec3(0,MOVE_AMOUNT,0);
                }

                void MoveDown(){
                        pos -= glm::vec3(0,MOVE_AMOUNT,0);
                }

                void Pitch(float angle){
                        glm::vec3 right = glm::normalize(glm::cross(up, forward));

                        forward = glm::vec3(glm::normalize(glm::rotate(angle, right) * glm::vec4(forward, 0.0)));
                        up = glm::normalize(glm::cross(forward, right));
                }

                private:
                        glm::mat4 projection;
                        glm::vec3 pos;
                        glm::vec3 forward;
                        glm::vec3 up;
};

#endif
