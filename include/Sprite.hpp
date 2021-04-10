//
// Created by daang on 1/19/2021.
//

#ifndef TEENSYTINYCONSOLE_SPRITE_HPP
#define TEENSYTINYCONSOLE_SPRITE_HPP

#include "Drawable.hpp"
#include "Colors.hpp"
#include "Canvas.hpp"

namespace TTC {

    class Sprite : public Drawable {

        uint8_t *image;


    public:
        int width, height;

        Sprite(Point point, uint8_t * image, int width, int height) : Drawable(point), image(image), width(width), height(height) {}


        Rect getRect() override{
            return Rect(point, width, height);
        }

        void draw(Canvas & canvas) override {
            for(int i = 0; i < width; i++){
                for(int j = 0; j < height; j++){
                    canvas.setPixel(i + point.x, j + point.y, image[i +j * width]);
                }
            }
        }
    };

}


#endif //TEENSYTINYCONSOLE_SPRITE_HPP
