//
// Created by daang on 1/19/2021.
//

#ifndef TEENSYTINYCONSOLE_DRAWABLE_HPP
#define TEENSYTINYCONSOLE_DRAWABLE_HPP

#include "Canvas.hpp"
#include "Locational.hpp"


namespace TTC {

    class Drawable {
    public:
        Point point;


    protected:
        virtual void draw(Canvas &canvas) = 0;

        virtual Rect getRect() = 0;

    public:
        Drawable(Point point) : point(point) {}

        friend class Canvas;

    };



}


#endif //TEENSYTINYCONSOLE_DRAWABLE_HPP
