//
// Created by daang on 1/19/2021.
//

#ifndef TEENSYTINYCONSOLE_SHAPES_HPP
#define TEENSYTINYCONSOLE_SHAPES_HPP

#include "Drawable.hpp"
#include "Colors.hpp"

namespace TTC {

    class Rectangle : public Drawable {
        int width;
        int height;
        uint8_t color;

    protected:



        void draw(Canvas &canvas) override {
            for (int i = 0; i < canvas.width; i++) {
                for (int j = 0; j < canvas.height; j++) {
                    canvas.setPixel(i + point.x, j + point.y, color);
                }
            }
        }

    public:
        Rectangle(Point point, int width, int height, uint8_t color = 0) : Drawable(point), width(width), height(height), color(color) {}

        Rect getRect() override;
    };




    class Circle : public Drawable {
    public:
        unsigned int radius;
        bool filled = true;
        uint8_t color = 1;






        void draw(Canvas &canvas) override {
            int max_radius = radius * radius;

            for (int i = 0; i < radius * 2; i++) {
                for (int j = 0; j < radius * 2; j++) {

                    if ((((i - radius) * (i - radius)) + ((j - radius) * (j - radius) )) <= (max_radius)) {
                        canvas.setPixel(i + point.x, j + point.y, color);
                    }
                }
            }
        }


        Circle(const Point& point, int radius) : Drawable(point), radius(radius) {}

        Circle(const Point& point, int radius, uint8_t color) : Drawable(point), radius(radius), color(color) {}

        Rect getRect() override {
            return {point, radius*2, radius*2};
        }
    };



}

#endif //TEENSYTINYCONSOLE_SHAPES_HPP
