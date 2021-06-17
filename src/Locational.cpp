//
// Created by daang on 4/10/2021.
//
#include  "Locational.hpp"

Point::Point(PointF point) {
    x = int(point.x);
    y = int(point.y);
}

PointF::PointF(Point point){
    x = float(point.x);
    y = float(point.y);
}