//
// Created by daang on 1/19/2021.
//

#ifndef TEENSYTINYCONSOLE_SPRITE_HPP
#define TEENSYTINYCONSOLE_SPRITE_HPP

#include "Drawable.hpp"
#include "Colors.hpp"
#include "Canvas.hpp"


template<int width, int height>
class Sprite : public Drawable {

    Colors image[width][height];

public:
    Sprite operator=(Colors loadImage[width][height]) {
        image = loadImage;
    }

protected:
    template<int canvaswidth, int canvasheight>
    void draw(Canvas<canvaswidth, canvasheight> & canvas) {
        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++){
                if(image[i][j] != Colors::_notacollor) {
                    canvas.setPixel(i + x, j + y, image[i][j]);
                }
            }
        }
    }
};



};


#endif //TEENSYTINYCONSOLE_SPRITE_HPP
