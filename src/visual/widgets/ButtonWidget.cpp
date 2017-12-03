//
// Created by zakrent on 12/3/17.
//

#include "ButtonWidget.h"

#include <utility>

namespace visual {
	void ButtonWidget::render(visual::Renderer &renderer) {
		renderer.renderTexture(texture, x, y, width, heigth);
	}

	void ButtonWidget::handleClick(int _x, int _y) {
		if(_x > x && _x < x+width && _y > y && y < y+heigth) {
			callback();
		}
	}

	ButtonWidget::ButtonWidget(int _id, int _x, int _y, Window *_window, std::function<void()> _callback, textureID texture)
			: WindowWidget(_id, _x, _y, _window), callback(std::move(_callback)), texture(texture) {
	}
}
