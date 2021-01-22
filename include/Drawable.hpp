//
// Created by daang on 1/19/2021.
//

#ifndef TEENSYTINYCONSOLE_DRAWABLE_HPP
#define TEENSYTINYCONSOLE_DRAWABLE_HPP

#include "Canvas.hpp"
#include "Locational.hpp"


class Drawable {
public:
    Point point;


protected:
    template<int width, int height>
    virtual int draw(Canvas<width, height> & canvas) = 0;

    virtual Rect getRect() = 0;
public:
    Drawable(Point point) : point(point) {}

};


#endif //TEENSYTINYCONSOLE_DRAWABLE_HPP
