//
// Created by zakrent on 12/3/17.
//

#ifndef SDL_GOL_BUTTONWIDGET_H
#define SDL_GOL_BUTTONWIDGET_H

#include <functional>
#include "TextureWrapper.h"
#include "Window.h"

namespace visual {
	class ButtonWidget : public WindowWidget{
		textureID texture;
		const int heigth = 100;
		const int width = 133;
		std::function<void()> callback; //function to call on click
	public:
		void render(Renderer& renderer) override;
		void handleClick(int x, int y) override;

		ButtonWidget(int _id, int _x, int _y, Window* _window, std::function<void()> callback, textureID texture);
	};
}


#endif //SDL_GOL_BUTTONWIDGET_H
