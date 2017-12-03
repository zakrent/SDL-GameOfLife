#include "World.h"

namespace world{
	World::World(int _heigth, int _width){
		heigth = _heigth;
		width = _width;
		for(int i = 0; i < heigth*width; i++){
			cells.emplace_back(false);
		}
	}
	
	int World::getCellIndex(int x, int y){
		return y*width+x;
	}	

	Cell World::getCell(int x, int y){
		return cells[getCellIndex(x,y)];
	}

	void World::setCell(int x, int y, Cell cell){
		cells[getCellIndex(x,y)] = cell;
	}

	std::vector<Cell> World::getNeighbourCells(int x, int y){
		std::vector<Cell> neighbours;
		for(int i = -1; i < 2; i++){
			for(int j = -1; j < 2; j++){
				if((i != 0 || j != 0) && x+i < width && y+j < heigth && x+i > 0 && y+j > 0){
					neighbours.push_back(getCell((x+i), (y+j)));
				}
			}
		}
		return neighbours;
	}
}
