#ifndef GOL_PROGRAM
#define GOL_PROGRAM

#include "visual/Window.h"
#include "world/World.h"
#include "world/WorldUpdater.h"
#include "visual/WorldWidget.h"
#include "world/WorldSaver.h"
#include <SDL.h>
#include <functional>

class Program{
	const int MIN_UPDATE_TIME = 100;
	bool paused;
	visual::Window window;
	world::World world;
	world::IWorldUpdater* worldUpdater;
	world::IWorldSaver* worldSaver;
public:
	void startMainLoop();
	void togglePause();
public:
	Program();
	~Program();
};

#endif
