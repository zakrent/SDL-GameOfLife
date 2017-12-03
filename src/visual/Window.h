#ifndef GOL_WINDOW
#define GOL_WINDOW

#include <SDL.h>
#include <vector>
#include "renderer/Renderer.h"
#include "widgets/BaseWindowWidget.h"

namespace visual{

	class Window{
		SDL_Window *window;
		Renderer* renderer;
		std::vector<WindowWidget*> windowWidgets;
	public:
		void addWidget(WindowWidget*);
		void render();
		void handleClick(int x, int y);		
	public:
		Window();
		~Window();
	};
}

#endif
