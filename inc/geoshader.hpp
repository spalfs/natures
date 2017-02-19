#ifndef geoshader_h
#define geoshader_h

#include <string>
#include <GL/glew.h>
#include "graphicsobjects.hpp"

//#define GLSL(src) "#version 150 core\n" #src

class GeoShader
{
  public:
    GeoShader(const std::string& fileName);

    void Bind();
    void Update(const Transform& transform, const Camera& camera);
    virtual ~GeoShader();
    GLuint m_program;

  private:
    static const unsigned int NUM_SHADERS = 3;
    static const unsigned int NUM_UNIFORMS = 3;
    std::string LoadShader(const std::string& fileName);
    void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
    GLuint CreateShader(const std::string& text, GLenum shaderType);

    GLuint m_shaders[NUM_SHADERS];
    GLuint m_uniforms[NUM_UNIFORMS];
};

#endif
