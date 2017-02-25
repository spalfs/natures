#include "opengl/geoshader.hpp"
#include <iostream>
#include <fstream>

GeoShader::GeoShader(const std::string& fileName)
{
        m_program = glCreateProgram();

        m_shaders[0] = CreateShader(LoadShader(fileName + ".vert"), GL_VERTEX_SHADER);
        m_shaders[1] = CreateShader(LoadShader(fileName + ".frag"), GL_FRAGMENT_SHADER);
        m_shaders[2] = CreateShader(LoadShader(fileName + ".geom"), GL_GEOMETRY_SHADER);

        int i;
        for(i=0; i < NUM_SHADERS; i++)
                glAttachShader(m_program, m_shaders[i]);

        glLinkProgram(m_program);
        CheckShaderError(m_program, GL_LINK_STATUS, true, "error shader failed to link: ");

        glValidateProgram(m_program);
        CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "error shader is invalid: ");

        glUseProgram(m_program);
}

GeoShader::~GeoShader()
{
        int i;
        for(i=0; i< NUM_SHADERS; i++){
                glDetachShader(m_program, m_shaders[i]);
                glDeleteShader(m_shaders[i]);
        }
}

void GeoShader::Bind()
{
        glUseProgram(m_program);
}


void GeoShader::Update(const Transform& transform, const Camera& camera)
{
        glm::mat4 MVP = transform.GetMVP(camera);
        glm::mat4 Normal = transform.GetModel();

        glUniformMatrix4fv(m_uniforms[0], 1, GL_FALSE, &MVP[0][0]);
}

GLuint GeoShader::CreateShader(const std::string& text, GLenum shaderType)
{
        GLuint shader = glCreateShader(shaderType);

        const GLchar* shaderSource[1];
        GLint shaderSourceLengths[1];

        shaderSource[0] = text.c_str();
        shaderSourceLengths[0] = text.length();

        glShaderSource(shader, 1, shaderSource, shaderSourceLengths);
        glCompileShader(shader);

        return shader;
}


void GeoShader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
        GLint success = 0;
        GLchar error[1024] = { 0 };

        if(isProgram)
                glGetProgramiv(shader, flag, &success);
        else
                glGetShaderiv(shader, flag, &success);

        if(success == GL_FALSE){
                if(isProgram)
                        glGetProgramInfoLog(shader, sizeof(error), NULL, error);
                else
                        glGetShaderInfoLog(shader, sizeof(error), NULL, error);

                std::cerr << errorMessage << ": '" << error << "'" << std::endl;
        }
}

std::string GeoShader::LoadShader(const std::string& fileName)
{
        std::ifstream file;
        file.open((fileName).c_str());

        std::string output;
        std::string line;

        if(file.is_open()){
                while(file.good()){
                        getline(file, line);
                        output.append(line + "\n");
                }
        }
        else{
                std::cerr << "Unable to load shader: " << fileName << std::endl;
        }

        return output;
}
