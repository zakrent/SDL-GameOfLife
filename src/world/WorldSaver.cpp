//
// Created by zakrent on 12/3/17.
//

#include "WorldSaver.h"
#include <fstream>
#include <cstdlib>

namespace world {
    void world::TextWorldSaver::saveWorld(world::World world) {
        std::ofstream file;
        file.open("worldsave.txt", std::ofstream::out | std::ofstream::trunc);
        file<<world.getHeigth()<<"\n";
        file<<world.getWidth()<<"\n";
        for(int y = 0; y < world.getHeigth(); y++){
            for(int x = 0; x < world.getWidth(); x++){
                file<<(world.getCell(x,y).getAlive() ? "A\n" : "D\n");
            }
        }
        file.close();
    }

    World TextWorldSaver::loadWorld(){
        std::ifstream file("worldsave.txt");
        if (!file.is_open()){
            return World(20,20);
        }
        std::string line;
        std::getline(file, line);
        int heigth = atoi(line.c_str());
        std::getline(file, line);
        int width =  atoi(line.c_str());
        World newWorld(heigth,width);
        for(int y = 0; y < heigth; y++){
            for(int x = 0; x < width; x++){
                std::getline(file, line);
                newWorld.setCell(x,y, line == "A");
            }
        }
        file.close();
        return newWorld;
    }
}
