#include "WorldUpdater.h"

namespace world{
	void ConwayWorldUpdater::updateWorld(World& world){
		World oldWorld = world;
		for(int x = 0; x < oldWorld.getWidth(); x++){
			for(int y = 0; y < oldWorld.getHeigth(); y++){
				int aliveNeighbours = 0;
				std::vector<Cell> neighbours = oldWorld.getNeighbourCells(x,y);
				for(auto neighbour : neighbours){
					if(neighbour.getAlive()){
						aliveNeighbours++;
					}
				}			
				Cell currentCell = oldWorld.getCell(x,y);
				if(currentCell.getAlive()){
					world.setCell(x,y,Cell(aliveNeighbours == 2 || aliveNeighbours == 3));
				}
				else{
					world.setCell(x,y,Cell(aliveNeighbours == 3));
				}
			}
		}
	}
}
