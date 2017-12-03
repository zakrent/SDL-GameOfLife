#ifndef GOL_WINDOW
#define GOL_WINDOW

#include <SDL.h>
#include <vector>
#include "Renderer.h"

namespace visual{

	class Window;

	class WindowWidget{
    protected:
		int id;
		int x, y;
		bool active;
		Window* window;
    public:
		int getX(){return x;}
		int getY(){return y;}
		int getId(){return id;}
		void setActive(bool _active){active = _active;}
		bool getActive(){return active;}
		virtual	void handleClick(int x, int y) = 0;
		virtual void render(Renderer& renderer) = 0;
	public:
		WindowWidget(int _id, int _x, int _y, Window* _window){id = _id; window = _window; x = _x; y = _y;active=true;}
	};
	
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
