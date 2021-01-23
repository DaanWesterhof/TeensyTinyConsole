//
// Created by daang on 1/19/2021.
//

#include "../include/Canvas.hpp"
#include "../include/Drawable.hpp"

TTC::Canvas::Canvas(TTC::Window &window) : window(window), width(window.getWidth()), height(window.getHeight()) {}

TTC::Canvas::Canvas(TTC::Window &window, int width, int height, bool makeArray) : window(window), width(width), height(height) {
    if(makeArray) {
        canvas_array = (Colors *) calloc(width * height, 0);
        hasArray = true;
    }
}

void TTC::Canvas::draw(Drawable &drawable) {
    drawable.draw(*this);
}


void TTC::Canvas::setPixel(const Point& point, Colors color) {
    setPixel(point.x, point.y, color);
}

void TTC::Canvas::setPixel(int x, int y, Colors color) {
    if(x <= width && x >= 0 && y <= height && y >= 0) {
        if (hasArray) {
            canvas_array[y * width + x] = color;
        } else {
            window.drawPixel(x, y, color);
        }
    }
}


void TTC::Canvas::clear(Colors color) {
    if(hasArray){
        window.clear(color);
    }else{
        memset(canvas_array, int(color), (width*height));
    }
}

void TTC::Canvas::clear() {
    clear(Colors::BLACK);
}










