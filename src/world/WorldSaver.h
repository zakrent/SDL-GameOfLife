//
// Created by zakrent on 12/3/17.
//

#ifndef SDL_GOL_WORLDSAVER_H
#define SDL_GOL_WORLDSAVER_H

#include "World.h"

namespace world{
    struct IWorldSaver{
        virtual void saveWorld(World world) = 0;
        virtual World loadWorld() = 0;
    };

    class TextWorldSaver : public  IWorldSaver{
        void saveWorld(World world) override;
        World loadWorld() override;
    };
}


#endif //SDL_GOL_WORLDSAVER_H
