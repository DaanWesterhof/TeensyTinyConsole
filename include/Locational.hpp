//
// Created by daang on 1/19/2021.
//

#ifndef TEENSYTINYCONSOLE_LOCATIONAL_HPP
#define TEENSYTINYCONSOLE_LOCATIONAL_HPP

struct Point {
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {}
    Point(Point const &point) : x(point.x), y(point.y) {}
};

struct Rect {
    Point location;
    int width;
    int height;

    Rect(Point point, int w, int h) : location(point), width(w), height(h) {}

    bool contains(Point point) const {
        if((point.x >= location.x) && (point.x <= (width +location.x))) {
            if((point.y >= location.y) && (point.y <= (height + location.y))) {
                return true;
            }
        }
        return false;
    }
};

#endif //TEENSYTINYCONSOLE_LOCATIONAL_HPP
