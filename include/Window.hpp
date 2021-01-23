//
// Created by daang on 1/22/2021.
//

#ifndef INTOSPACE_BULLETHELL_WINDOW_HPP
#define INTOSPACE_BULLETHELL_WINDOW_HPP

#include "Colors.hpp"

namespace TTC {

    class Window {
    public:
        virtual void flush() {}

        virtual void drawPixel(int x, int y, Colors color) = 0;

        virtual int getWidth() {return 0;}

        virtual int getHeight() {return 0;}

        virtual void clear(Colors color) {}


    };

}

#endif //INTOSPACE_BULLETHELL_WINDOW_HPP
