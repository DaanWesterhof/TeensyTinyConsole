//
// Created by daang on 1/19/2021.
//

#ifndef TEENSYTINYCONSOLE_SHAPES_HPP
#define TEENSYTINYCONSOLE_SHAPES_HPP

#include "Drawable.hpp"
#include "Colors.hpp"

class Rectangle : public Drawable{
    int width;
    int height;
    Colors color = Colors::BLACK;

protected:


    template<int canvaswidth, int canvasheight>
    void draw(Canvas<canvaswidth, canvasheight> & canvas) {
        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++){
                canvas.setPixel(i+point.x, j+point.y, color);
            }
        }
    }

public:
    Rectangle(Point point, int width, int height) : Drawable(point), width(width), height(height) {}

    Rect getRect() override;
};





class Circle : public Drawable{
    int radius;
    bool filled = true;
    Colors color = Colors::BLACK;


protected:


    template<int canvaswidth, int canvasheight>
    void draw(Canvas<canvaswidth, canvasheight> & canvas) {
        if(filled) {
            for (int i = 0; i < radius * 2; i++) {
                for (int j = 0; j < radius * 2; j++) {
                    if (((i - radius) ^ 2 + (j - radius) ^ 2) <= (radius ^ 2)) {
                        canvas.setPixel(i + point.x, j + point.y, color);
                    }
                }
            }
        }else{
            for (int i = 0; i < radius * 2; i++) {
                for (int j = 0; j < radius * 2; j++) {
                    if (((i - radius) ^ 2 + (j - radius) ^ 2) == (radius ^ 2)) {
                        canvas.setPixel(i + point.x, j + point.y, color);
                    }
                }
            }
        }
    }

public:
    Circle(Point point, int radius) : Drawable(point), radius(radius) {}
};


#endif //TEENSYTINYCONSOLE_SHAPES_HPP
