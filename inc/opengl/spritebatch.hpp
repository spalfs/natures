#ifndef spritebatch_h
#define spritebatch_h

#include <iostream>
#include <vector>
#include <GL/glew.h>

#include "graphicsdata.hpp"
#include "geoshader.hpp"

class RenderBatch {
        public:
                RenderBatch(GLuint Offset, GLuint NumVertices) : offset(Offset),
                numVertices(NumVertices){}
                GLuint offset;
                GLuint numVertices;
};

class SpriteBatch
{
        public:
                SpriteBatch(GeoShader theshader);

                void init();
                void begin();
                void end();
                void draw(const GraphicsData& gfxData);
                void renderBatch();

        private:
                void createRenderBatches();
                void createVertexArray();
                
                GLuint _vbo;
                GLuint _vao;

                std::vector<GraphicsData*> _gfxPtr; 
                std::vector<GraphicsData> _gfx; 
                std::vector<RenderBatch> _renderBatches;

                GeoShader shader;
};

#endif
