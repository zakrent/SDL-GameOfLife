#include "Renderer.h"

namespace visual{
	Renderer::Renderer(SDL_Renderer* renderer){
		sdlRenderer = renderer;
		loadTexture.loadFromFile(renderer, (char *) "textures/load.bmp");
		saveTexture.loadFromFile(renderer, (char *) "textures/save.bmp");
		pauseTexture.loadFromFile(renderer, (char *) "textures/pause.bmp");
    }

	void Renderer::startRendering() {
		SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
		SDL_RenderClear(sdlRenderer);
	}

	void Renderer::swapBuffers() {
		SDL_RenderPresent(sdlRenderer);
	}

	void Renderer::renderRectangle(int x, int y, int w, int h){
		SDL_SetRenderDrawColor(sdlRenderer, 255, 255, 255, 255);
		SDL_Rect rectangle{x,y,w,h};
		SDL_RenderFillRect(sdlRenderer, &rectangle);
	}

	void Renderer::renderTexture(textureID textureID, int x, int y, int w, int h) {
		SDL_Rect srcrect = SDL_Rect{0,0,w,h};
		SDL_Rect dstrect = SDL_Rect{x,y,w,h};
        TextureWrapper* texture;
        switch(textureID){
            case ButtonLoad:
                texture = &loadTexture;
                break;
            case ButtonSave:
                texture = &saveTexture;
                break;
            case ButtonPause:
                texture = &pauseTexture;
                break;
            default:
                std::abort();
        }
		SDL_RenderCopyEx(sdlRenderer,texture->getTexturePointer(), &srcrect, &dstrect, 0, nullptr, SDL_FLIP_NONE);
	}

}
