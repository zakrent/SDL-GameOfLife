#ifndef GOL_WORLD_UPDATER
#define GOL_WORLD_UPDATER

#include "World.h"

namespace world{
	struct IWorldUpdater{
		virtual void updateWorld(World& world) = 0;
	};

	class ConwayWorldUpdater : public IWorldUpdater {
		void updateWorld(World& world) override;
	};
}

#endif
