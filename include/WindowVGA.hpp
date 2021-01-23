//
// Created by daang on 1/22/2021.
//

#ifndef INTOSPACE_BULLETHELL_WINDOWVGA_HPP
#define INTOSPACE_BULLETHELL_WINDOWVGA_HPP

#include "Window.hpp"
#include "../../VGA_t4/include/VGA_t4.h"
namespace TTC {

    class VGA_Window : public Window {
    public:

        void drawPixel(int x, int y, Colors color) override = 0;

        int getWidth() override {}

        int getHeight() override {}

        void clear(Colors color) override {}


    };

}

#endif //INTOSPACE_BULLETHELL_WINDOWVGA_HPP
