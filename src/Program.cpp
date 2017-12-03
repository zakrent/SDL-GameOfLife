#include "Program.h"
#include "visual/widgets/ButtonWidget.h"
#include "visual/renderer/Renderer.h"

Program::Program() : world(80,80){
	paused = false;
	worldUpdater = new world::ConwayWorldUpdater();
	worldSaver = new world::TextWorldSaver();

	window.addWidget(new visual::WorldWidget(0, 0, 0, &window, &world));
	window.addWidget(new visual::ButtonWidget(1, 0, 400, &window, [this]()->void{this->togglePause();}, visual::textureID::ButtonPause));
	window.addWidget(new visual::ButtonWidget(2, 134, 400, &window, [this]()->void{worldSaver->saveWorld(world);}, visual::textureID::ButtonSave));
	window.addWidget(new visual::ButtonWidget(3, 268, 400, &window, [this]()->void{world = worldSaver->loadWorld();}, visual::textureID::ButtonLoad));
}

Program::~Program(){
	delete worldUpdater;
	delete worldSaver;
	SDL_Quit();
}

void Program::startMainLoop(){
	bool running = true;
	while(running){
		int updateStart = SDL_GetTicks();

		SDL_Event event{};
		while(SDL_PollEvent(&event) != 0 ) {
			switch(event.type){
				case SDL_QUIT:
					running = false;
					break;
				case SDL_MOUSEBUTTONDOWN:
					window.handleClick(event.button.x, event.button.y);
				default:
					break;
			}
		}

		window.render();
		if(!paused)
			worldUpdater->updateWorld(world);

		if (SDL_GetTicks() < updateStart + MIN_UPDATE_TIME) {
			SDL_Delay((updateStart + MIN_UPDATE_TIME) - SDL_GetTicks());
		}
	}
}

void Program::togglePause() {
	paused = !paused;
}
