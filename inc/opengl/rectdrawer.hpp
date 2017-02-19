#ifndef rectdrawer_h
#define rectdrawer_h


#include <GL/glew.h>
#include <vector>
#include <iostream>
#include "geoshader.hpp"
#include "graphicsdata.hpp"
#include "spritebatch.hpp"


//merge this with spritebatch
class Rectdrawer
{
public:
	Rectdrawer(GeoShader theshader);
	~Rectdrawer();


	//void init();
	void begin();
	void end();
	void draw(const GraphicsData& gfxData);
	void renderBatch();

private:
	// Creates all the needed RenderBatches
	void createRenderBatches();


	GLuint _vbo;
	GLuint _vao;


	std::vector<GraphicsData*> _gfxPtr; ///< This is for sorting
	std::vector<GraphicsData> _gfx; ///< These are the actual glyphs
	std::vector<RenderBatch> _renderBatches;

	GeoShader shader;


};


#endif

