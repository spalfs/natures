#ifndef spritebatch_h
#define spritebatch_h

#include <GL/glew.h>
#include "graphicsdata.hpp"
#include <vector>
#include "geoshader.hpp"
#include <iostream>


class RenderBatch {
public:
    RenderBatch(GLuint Offset, GLuint NumVertices) : offset(Offset),
        numVertices(NumVertices){
    }
    GLuint offset;
    GLuint numVertices;
    //GLuint texture;
};


class SpriteBatch
{
	public:
    SpriteBatch(GeoShader theshader);
    ~SpriteBatch();
    // Initializes the spritebatch
    void init();
    // Begins the spritebatch
    void begin();
    // Ends the spritebatch
    void end();
    // Adds a glyph to the spritebatch
    void draw(const GraphicsData& gfxData);
    // Renders the entire SpriteBatch to the screen
    void renderBatch();

	private:
    // Creates all the needed RenderBatches
    void createRenderBatches();
    // Generates our VAO and VBO
    void createVertexArray();
    // Sorts glyphs according to _sortType
    //void sortGlyphs();
    // Comparators used by sortGlyphs()
    //static bool compareFrontToBack(Glyph* a, Glyph* b);
    //static bool compareBackToFront(Glyph* a, Glyph* b);
    //static bool compareTexture(Glyph* a, Glyph* b);

    GLuint _vbo;
    GLuint _vao;

    //GlyphSortType _sortType;

    std::vector<GraphicsData*> _gfxPtr; ///< This is for sorting
    std::vector<GraphicsData> _gfx; ///< These are the actual glyphs
    std::vector<RenderBatch> _renderBatches;

    GeoShader shader;

};

#endif
