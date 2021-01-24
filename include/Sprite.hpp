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
        Sprite(Point point) : Drawable(point) {}

        Sprite operator=(uint8_t * loadImage) {
            image = loadImage;
            return *this;
        }

        Rect getRect() override{
            return Rect(Point(0, 0), 0, 0);
        }

    protected:

        void draw(Canvas & canvas) {
            for(int i = 0; i < canvas.width; i++){
                for(int j = 0; j < canvas.height; j++){
                    if(image[i + j*canvas.width] != 255) {
                        canvas.setPixel(i + point.x, j + point.y, image[i + j*canvas.width]);
                    }
                }
            }
        }

    };

}


#endif //TEENSYTINYCONSOLE_SPRITE_HPP
