#ifndef GOL_World
#define GOL_World

#include "Cell.h"
#include <vector>

namespace world{
	class World{
		std::vector<Cell> cells;
		int width;
		int heigth;
		int getCellIndex(int x, int y);
	public:
		int getWidth(){return width;}
		int getHeigth(){return heigth;}
		Cell getCell(int x, int y);
		std::vector<Cell> getNeighbourCells(int x, int y);
		void setCell(int x, int y, Cell cell);
		World(int _heigth, int _width);
	};
	
}

#endif
