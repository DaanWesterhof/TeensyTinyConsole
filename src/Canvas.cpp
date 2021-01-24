//
// Created by daang on 1/19/2021.
//

#include "../include/Canvas.hpp"
#include "../include/Drawable.hpp"

TTC::Canvas::Canvas(TTC::Window &window) : window(window), width(window.getWidth()), height(window.getHeight()) {}

TTC::Canvas::Canvas(TTC::Window &window, int width, int height, bool makeArray) : window(window), width(width), height(height) {
    if(makeArray) {
        canvas_array = (uint8_t *) calloc(width * height, sizeof(uint8_t));
        hasArray = true;
    }
}

void TTC::Canvas::draw(Drawable &drawable) {
    drawable.draw(*this);
}


void TTC::Canvas::setPixel(const Point& point, uint8_t color) {
    setPixel(point.x, point.y, color);
}

void TTC::Canvas::setPixel(int x, int y, uint8_t color) {
    if(x < width && x >= 0 && y < height && y >= 0) {
            window.drawPixel(x, y, color);
    }
}


void TTC::Canvas::clear(uint8_t color) {

    window.clear(color);

}

void TTC::Canvas::clear() {
    clear(0);
}










