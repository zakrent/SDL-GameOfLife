#ifndef GOL_RENDERER
#define GOL_RENDERER

#include <SDL.h>
#include <vector>
#include "TextureWrapper.h"

namespace visual{

	enum textureID{
		ButtonLoad = 0,
		ButtonSave = 1,
		ButtonPause = 2,
	};

	class Renderer{
		SDL_Renderer* sdlRenderer;

		//no time to create texture sheet in gimp
		TextureWrapper loadTexture;
		TextureWrapper saveTexture;
		TextureWrapper pauseTexture;

	public:
		void startRendering();
		void swapBuffers();
		void renderRectangle(int x, int y, int w, int h);
		void renderTexture(textureID textureID ,int x, int y, int w, int h);
	public:
		Renderer(SDL_Renderer* _sdlRenderer);
	};
}

#endif
