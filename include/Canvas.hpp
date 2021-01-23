//
// Created by daang on 1/19/2021.
//

#ifndef TEENSYTINYCONSOLE_CANVAS_HPP
#define TEENSYTINYCONSOLE_CANVAS_HPP


#include "Window.hpp"
#include "Arduino.h"
#include "Locational.hpp"


namespace TTC {

    class Drawable;

    class Canvas {

    public:
        Window &window;
        int width;
        int height;

    private:
        bool hasArray = false;
        Colors *canvas_array{};


    public:

        //when window can store data;
        Canvas(Window &window);

        //when window cant store data
        Canvas(Window &window, int width, int height, bool makeArray = false);


        void draw(Drawable &drawable);

        void setPixel(const Point& point, Colors color);

        void setPixel(int x, int y, Colors color);

        void clear();

        void clear(Colors color);

        void flush() {
            window.flush();
        }

    private:


    };

}

#endif //TEENSYTINYCONSOLE_CANVAS_HPP
