//
// Created by zakrent on 12/3/17.
//

#ifndef SDL_GOL_BASEWINDOWWIDGET_H
#define SDL_GOL_BASEWINDOWWIDGET_H

#include "../renderer/Renderer.h"

namespace visual {
	class Window;

	class WindowWidget {
	protected:
		int id;
		int x, y;
		bool active;
		Window *window;
	public:
		int getX() { return x; }
		int getY() { return y; }
		int getId() { return id; }
		void setActive(bool _active) { active = _active; }
		bool getActive() { return active; }
		virtual void handleClick(int x, int y) = 0;
		virtual void render(Renderer &renderer) = 0;
	public:
		WindowWidget(int _id, int _x, int _y, Window *_window) {
			id = _id;
			window = _window;
			x = _x;
			y = _y;
			active = true;
		}
	};
}



#endif //SDL_GOL_BASEWINDOWWIDGET_H
