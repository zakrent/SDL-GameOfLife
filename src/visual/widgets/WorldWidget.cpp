#include "WorldWidget.h"

namespace visual{
	WorldWidget::WorldWidget(int id, int x, int y, Window* window, world::World* _world) : WindowWidget(id, x, y, window), world(_world){}
	
	void WorldWidget::render(Renderer& renderer){
		int cellWidth = width/world->getWidth();
		int cellHeigth = heigth/world->getHeigth();
		for(int x = 0; x < world->getWidth(); x++){
			for(int y = 0; y < world->getHeigth(); y++){
				if(world->getCell(x,y).getAlive())
					renderer.renderRectangle(x*cellWidth+getX(), y*cellHeigth+getY(), cellWidth, cellHeigth);
			}
		}	
	}

	void WorldWidget::handleClick(int _x, int _y) {
		if(_x > x && _x < x+width && _y > y && y < y+heigth){
			int cellWidth = width/world->getWidth();
			int cellHeigth = heigth/world->getHeigth();
			int xCell = (_x-x)/cellWidth;
			int yCell = (_y-y)/cellHeigth;
			world->setCell(xCell, yCell, !world->getCell(xCell,yCell).getAlive());
		}
	}
}
