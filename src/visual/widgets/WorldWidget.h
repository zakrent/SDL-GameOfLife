#ifndef GOL_WORLD_WIDGET
#define GOL_WORLD_WIDGET

#include "../Window.h"
#include "../../world/World.h"

namespace visual{
	class WorldWidget : public WindowWidget{
		world::World* world;
		const int heigth = 400;
		const int width = 400;	
	public:
		void render(Renderer& renderer) override;
		void handleClick(int x, int y) override;
		WorldWidget(int id, int x, int y, Window* window, world::World* _world);
	};
}

#endif
