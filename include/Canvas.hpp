//
// Created by daang on 1/19/2021.
//

#ifndef TEENSYTINYCONSOLE_CANVAS_HPP
#define TEENSYTINYCONSOLE_CANVAS_HPP

#include <cstdint>
#include "Drawable.hpp"
#include "../../VGA_t4/header/VGA_t4.h"

template<int width, int height>
class Canvas {
    VGA_T4 &vga_output;


public:
    void draw(Drawable & drawable){
        drawable.draw<width, height>(canvas);
    }


    setPixel(int x, int y, Colors color){
        vga_output.drawPixel(x, y, color);

    }



};


#endif //TEENSYTINYCONSOLE_CANVAS_HPP
