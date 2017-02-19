#include "rectdrawer.hpp"

Rectdrawer::Rectdrawer(GeoShader theshader) : _vbo(0), _vao(0), shader(theshader){
    // Generate the VAO if it isn't already generated
    if (_vao == 0) {
      glGenVertexArrays(1, &_vao);
    }

    // Bind the VAO. All subsequent opengl calls will modify it's state.
    glBindVertexArray(_vao);

    //G enerate the VBO if it isn't already generated
    if (_vbo == 0) {
      glGenBuffers(1, &_vbo);
    }
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);

    //Tell opengl what attribute arrays we need
    GLint posAttrib = glGetAttribLocation(shader.m_program, "pos");
  	glEnableVertexAttribArray(posAttrib);

    GLint colAttrib = glGetAttribLocation(shader.m_program, "color");
  	glEnableVertexAttribArray(colAttrib);

    GLint sidesAttrib = glGetAttribLocation(shader.m_program, "sides");
  	glEnableVertexAttribArray(sidesAttrib);

    //    glEnableVertexAttribArray(2);

    //This is the position attribute pointer
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE,
  												 6 * sizeof(float), 0);    //This is the color attribute pointer
    glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE,
  												 6 * sizeof(float), (void*) (2 * sizeof(float)));    //This is the UV attribute pointer
    glVertexAttribPointer(sidesAttrib, 1, GL_FLOAT, GL_FALSE,
  												 6 * sizeof(float), (void*) (5 * sizeof(float)));
    glBindVertexArray(0);

    
}

Rectdrawer::~Rectdrawer()
{
}

void Rectdrawer::draw(const GraphicsData& gfxData) {
    _gfx.emplace_back(gfxData);
}



void Rectdrawer::begin() {
    _renderBatches.clear();
    _gfx.clear();
}

void Rectdrawer::end() {
    // Set up all pointers for fast sorting
    _gfxPtr.resize(_gfx.size());
    for (int i = 0; i < _gfx.size(); i++) {
        _gfxPtr[i] = &_gfx[i];
    }

    //sortGlyphs();
    createRenderBatches();
}

void Rectdrawer::renderBatch() {

    // Bind our VAO. This sets up the opengl state we need, including the
    // vertex attribute pointers and it binds the VBO
    glBindVertexArray(_vao);

    for (int i = 0; i < _renderBatches.size(); i++) {
        glDrawArrays(GL_POINTS, _renderBatches[i].offset, _renderBatches[i].numVertices);
    }
    glBindVertexArray(0);
}


// needs edit here for rectangle instead of other geometry
void Rectdrawer::createRenderBatches() {
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
    vertices[cv++] = _gfxPtr[0]->x;
    vertices[cv++] = _gfxPtr[0]->y;
    vertices[cv++] = _gfxPtr[0]->r;
    vertices[cv++] = _gfxPtr[0]->g;
    vertices[cv++] = _gfxPtr[0]->b;
    vertices[cv++] = _gfxPtr[0]->sides;

    offset += 6;

    //Add all the rest of the glyphs
    //std::cout << "ptr size = " <<  _gfxPtr.size() << std::endl;
    for (int cg = 1; cg < _gfxPtr.size(); cg++) {

        _renderBatches.back().numVertices += 6;
   
        vertices[cv++] = _gfxPtr[cg]->x;
        vertices[cv++] = _gfxPtr[cg]->y;
        vertices[cv++] = _gfxPtr[cg]->r;
        vertices[cv++] = _gfxPtr[cg]->g;
        vertices[cv++] = _gfxPtr[cg]->b;
        vertices[cv++] = _gfxPtr[cg]->sides;

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
