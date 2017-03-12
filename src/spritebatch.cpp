#include "opengl/spritebatch.hpp"

SpriteBatch::SpriteBatch(GeoShader theshader) : _vbo(0), _vao(0), shader(theshader){}

void SpriteBatch::init() 
{
        createVertexArray();
}

void SpriteBatch::begin() 
{
        _renderBatches.clear();
        // Makes _glpyhs.size() == 0, however it does not free internal memory.
        // So when we later call emplace_back it doesn't need to internally call new.
        _gfx.clear();
}

void SpriteBatch::end() 
{
        // Set up all pointers for fast sorting
        _gfxPtr.resize(_gfx.size());
        for (int i = 0; i < _gfx.size(); i++) 
                _gfxPtr[i] = &_gfx[i];
        
        //sortGlyphs();
        createRenderBatches();
}

void SpriteBatch::draw(Rectangle r, DNA::Visuals v) 
{
        _gfx.emplace_back(std::make_pair(r,v));
}

void SpriteBatch::renderBatch() 
{
        // Bind our VAO. This sets up the opengl state we need, including the
        // vertex attribute pointers and it binds the VBO
        glBindVertexArray(_vao);

        //glBindTexture(GL_TEXTURE_2D, _renderBatches[i].texture);
        for (int i = 0; i < _renderBatches.size(); i++) 
                glDrawArrays(GL_POINTS, _renderBatches[i].offset, _renderBatches[i].numVertices);

        glBindVertexArray(0);
}

void SpriteBatch::createRenderBatches() 
{
        // This will store all the vertices that we need to upload
        std::vector <float> vertices;
        // Resize the buffer to the exact size we need so we can treat
        // it like an array
        vertices.resize(_gfxPtr.size() * 6);

        if (_gfxPtr.empty()) {
                return;
        }

        int offset = 0; // current offset
        int cv = 0; // current vertex

        //Add the first batch
        _renderBatches.emplace_back(offset, 6);
        vertices[cv++] = _gfxPtr[0]->first.x;
        vertices[cv++] = _gfxPtr[0]->first.y;
        vertices[cv++] = _gfxPtr[0]->second.red;
        vertices[cv++] = _gfxPtr[0]->second.green;
        vertices[cv++] = _gfxPtr[0]->second.blue;
        vertices[cv++] = SIDES;

        offset += 6;

        //Add all the rest of the glyphs
        //std::cout << "ptr size = " <<  _gfxPtr.size() << std::endl;
        for (int cg = 1; cg < _gfxPtr.size(); cg++) {
                // Check if this glyph can be part of the current batch
                //if (_gfxPtr[cg]->texture != _gfxPtr[cg - 1]->texture) {
                // Make a new batch
                //    _renderBatches.emplace_back(offset, 6);
                //} else {
                // If its part of the current batch, just increase numVertices
                _renderBatches.back().numVertices += 6;
                //}
                vertices[cv++] = _gfxPtr[cg]->first.x;
                vertices[cv++] = _gfxPtr[cg]->first.y;
                vertices[cv++] = _gfxPtr[cg]->second.red;
                vertices[cv++] = _gfxPtr[cg]->second.green;
                vertices[cv++] = _gfxPtr[cg]->second.blue;
                vertices[cv++] = SIDES;

                offset += 6;
        }

        // Bind our VBO
        glBindBuffer(GL_ARRAY_BUFFER, _vbo);
        // Orphan the buffer (for speed)
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), nullptr, GL_DYNAMIC_DRAW);
        // Upload the data
        glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(float), vertices.data());
        // Unbind the VBO
        glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void SpriteBatch::createVertexArray() 
{
        // Generate the VAO if it isn't already generated
        if (_vao == 0)
                glGenVertexArrays(1, &_vao);

        // Bind the VAO. All subsequent opengl calls will modify it's state.
        glBindVertexArray(_vao);

        //G enerate the VBO if it isn't already generated
        if (_vbo == 0)
                glGenBuffers(1, &_vbo);

        glBindBuffer(GL_ARRAY_BUFFER, _vbo);

        //Tell opengl what attribute arrays we need
        GLint posAttrib = glGetAttribLocation(shader.m_program, "pos");
        glEnableVertexAttribArray(posAttrib);

        GLint colAttrib = glGetAttribLocation(shader.m_program, "color");
        glEnableVertexAttribArray(colAttrib);

        GLint sidesAttrib = glGetAttribLocation(shader.m_program, "sides");
        glEnableVertexAttribArray(sidesAttrib);

        //glEnableVertexAttribArray(2);

        //This is the position attribute pointer
        glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 6*sizeof(float), 0);                            
        //This is the color attribute pointer
        glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*) (2 * sizeof(float)));  
        //This is the UV attribute pointer
        glVertexAttribPointer(sidesAttrib, 1, GL_FLOAT, GL_FALSE,6*sizeof(float), (void*) (5 * sizeof(float)));
        glBindVertexArray(0);
}

