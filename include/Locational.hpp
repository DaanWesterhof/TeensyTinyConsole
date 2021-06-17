//
// Created by daang on 1/19/2021.
//

#ifndef TEENSYTINYCONSOLE_LOCATIONAL_HPP
#define TEENSYTINYCONSOLE_LOCATIONAL_HPP

struct PointF;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
    Point(Point const &point) : x(point.x), y(point.y) {}
    Point(PointF point);
};


struct PointF {
    float x;
    float y;
    PointF() : x(0), y(0) {}
    PointF(float x, float y) : x(x), y(y) {}
    PointF(PointF const &point) : x(point.x), y(point.y) {}
    PointF(Point point);
};




struct Rect {
    Point location;
    unsigned int width;
    unsigned int height;

    Rect() : location(), width(0), height(0) {}
    Rect(Point point, int w, int h) : location(point), width(w), height(h) {}

    bool contains(Point point) const {
        if((point.x >= location.x) && (point.x <= (width +location.x))) {
            if((point.y >= location.y) && (point.y <= (height + location.y))) {
                return true;
            }
        }
        return false;
    }

    bool intersects(Rect other, Rect & returnRect){
        //above or below
        if(other.location.y >= location.y+height || location.y >= other.location.y + other.height){
            return false;
        }

        //left or right
        if(other.location.x >= location.x+width || location.x >= other.location.x+ other.width){
            return false;
        }


        Point top_left;
        Point top_right;
        Point bottom_left;
        Point bottom_right;

        if(other.width > width){
            //i am on the left side
            if(other.location.x > location.x){
                top_right.x = location.x + width;
                bottom_right.x = location.x + width;
                top_left.x = other.location.x;
                bottom_left.x = other.location.x;

            }//i am on the right
            else if(other.location.x+other.width < location.x+width){
                top_right.x = other.location.x+width;
                bottom_right.x = other.location.x+width;
                top_left.x = location.x;
                bottom_left.x = location.x;
            }// i am in the middle
            else {
                top_right.x = location.x + width;
                bottom_right.x = location.x + width;
                top_left.x = location.x;
                bottom_left.x = location.x;
            }
        }else{
            //he is on my left side
            if(other.location.x < location.x){
                top_right.x = other.location.x+other.width;
                bottom_right.x = other.location.x+other.width;
                top_left.x = location.x;
                bottom_left.x = location.x;
            }//he is on the right
            else if(other.location.x+other.width > location.x+width){
                top_right.x = location.x+width;
                bottom_right.x = location.x+width;
                top_left.x = other.location.x;
                bottom_left.x = other.location.x;
            }// he is in the middle
            else{
                top_right.x = other.location.x+other.width;
                bottom_right.x = other.location.x+other.width;
                top_left.x = other.location.x;
                bottom_left.x = other.location.x;
            }
        }
        if(other.height > height){
            //i am above
            if(location.y < other.location.y){
                top_right.y = other.location.y;
                bottom_right.x = location.y +height;
                top_left.x = other.location.y;
                bottom_left.x = location.y + height;
            }//i am below
            else if(location.y+height > other.location.y+other.height){
                top_right.y = location.y;
                bottom_right.y = other.location.y+other.height;
                top_left.y = location.y;
                bottom_left.y = other.location.y + other.height;
            }// im in the middle
            else{
                top_right.y = location.y;
                bottom_right.y = location.y+height;
                top_left.y = location.y;
                bottom_left.y = location.y + height;
            }
        }else{
            //he is above
            if(other.location.y < location.y){
                top_right.y = location.y;
                bottom_right.x = other.location.y +other.height;
                top_left.x = location.y;
                bottom_left.x = other.location.y + other.height;
            }//he is below
            else if(other.location.y+other.height > location.y+height){
                top_right.y = other.location.y;
                bottom_right.y = location.y+height;
                top_left.y = other.location.y;
                bottom_left.y = location.y + height;
            }// he is in the middle
            else{
                top_right.y = other.location.y;
                bottom_right.y = other.location.y+other.height;
                top_left.y = other.location.y;
                bottom_left.y = other.location.y + other.height;
            }
        }

        returnRect = Rect(top_left, top_right.x - top_left.x, bottom_right.y - top_right.y);

        return true;
    }


};

#endif //TEENSYTINYCONSOLE_LOCATIONAL_HPP
