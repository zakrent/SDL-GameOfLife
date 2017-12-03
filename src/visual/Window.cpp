#include "Window.h"

namespace visual{
	
	void Window::render(){
		renderer->startRendering();

		for(auto widget : windowWidgets){
			widget->render(*renderer);
		}

		renderer->swapBuffers();
	}	

	void Window::handleClick(int x, int y){
		for(auto widget : windowWidgets){
			widget->handleClick(x,y);
		}	
	}

	void Window::addWidget(WindowWidget* widget){
		windowWidgets.push_back(widget);
	}
	
	Window::Window(){
		SDL_Renderer* sdlRenderer;
		SDL_CreateWindowAndRenderer(400,500, 0, &window, &sdlRenderer);
		renderer = new Renderer(sdlRenderer);
	}

	Window::~Window(){
		for(auto widget : windowWidgets){
			delete widget;
		}
		delete renderer;
	}
}
