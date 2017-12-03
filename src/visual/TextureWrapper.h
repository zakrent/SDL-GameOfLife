//
// Created by zakrent on 12/3/17.
//

#ifndef SDL_GOL_TEXTUREWRAPPER_H
#define SDL_GOL_TEXTUREWRAPPER_H

#include <SDL.h>

namespace visual {

    class TextureWrapper {
    private:
        SDL_Texture *texturePointer;
    public:
        SDL_Texture *getTexturePointer();
        void loadFromFile(SDL_Renderer *renderer, char *filePath);
    public:
        TextureWrapper();
        TextureWrapper(SDL_Renderer *renderer, char *filePath);
        ~TextureWrapper();
    };
}


#endif //SDL_GOL_TEXTUREWRAPPER_H
