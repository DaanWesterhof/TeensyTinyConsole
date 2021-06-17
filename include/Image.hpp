//
// Created by daang on 4/10/2021.
//

#ifndef TEENSYTINYCONSOLE_IMAGE_HPP
#define TEENSYTINYCONSOLE_IMAGE_HPP

#include <Arduino.h>

template<int width, int height>
class Image{
public:
    uint8_t data[width][height];
    bool mask[width][height];
};

#endif //TEENSYTINYCONSOLE_IMAGE_HPP
