#include "main.hpp"

int main()
{
        srand(time(NULL));

        Window      main(WINDOW_X, WINDOW_Y, "natures");
	List        L;
	Event       e;

        Transform   transform;
        Camera      camera(glm::vec3(0,0,70), 70.0f, (float)800/(float)600, 0.01f, 1000.0f);
        GeoShader   shader("./inc/opengl/shaders/theshader");
        SpriteBatch _spriteBatch(shader);

        _spriteBatch.init();
        shader.Bind();

        int uniModel = glGetUniformLocation(shader.m_program, "MVP");
        glUniformMatrix4fv(uniModel, 1, false, &transform.GetMVP(camera)[0][0]);

        Timer       fps;
        int         speed = 60;
        bool        pause = false;

        while(e.gRun()){
                fps.Start();
		while(e.Poll()){
			if(e.gEventType() == SDL_QUIT)
				e.off();
			else if(e.gEventType() == SDL_KEYDOWN)
                                switch(e.gEvent().key.keysym.sym){
                                        case SDLK_q:        e.off();                    break;
                                        case SDLK_EQUALS:   speed+=30;                  break;
                                        case SDLK_MINUS:    if(speed >30) speed-=30;    break;
                                        case SDLK_SPACE:    pause=(pause)?(0):(1);      break;
                                }
		}

                if(!pause){
                        main.Clear();
            
                        L.Remove();
                        L.Behavior();
                        L.Place();

                        shader.Bind();
                        _spriteBatch.begin();
                        
                        for(std::list<Creature>::iterator it = L.creatures.begin(); it != L.creatures.end(); it++)
                                _spriteBatch.draw(it->getGFXD());

                        for(std::list<Resource>::iterator it = L.resources.begin(); it != L.resources.end(); it++)
                                _spriteBatch.draw(it->getGFXD());
                        
                        _spriteBatch.end();
                        _spriteBatch.renderBatch();
                        main.swapBuffers();
                }

                if(fps.getTicks() < (1000 / speed))
                        SDL_Delay((1000 / speed) - fps.getTicks());
                
        }
        return 0;
}
