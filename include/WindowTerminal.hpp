//
// Created by daang on 1/24/2021.
//

#ifndef TEENSYTINYCONSOLE_WINDOWTERMINAL_HPP
#define TEENSYTINYCONSOLE_WINDOWTERMINAL_HPP

#include "Window.hpp"
#include "Arduino.h"

namespace TTC {

    template<int windowWidth, int windowheight>
    class Terminal_Window : public Window {
        char data[windowheight][windowWidth]{};
    public:

        void drawPixel(int x, int y, uint8_t color) override{
            if(x < windowWidth && x >= 0 && y < windowheight && y >= 0){
                data[y][x] = (char)color;
            }
        }

        int getWidth() override {
            return windowWidth;
        }

        int getHeight() override {
            return windowheight;
        }

        void clear(uint8_t color) override {
            for(int i = 0; i < windowheight;i++){
                for(int j = 0; j < windowWidth; j++) {
                    data[i][j] = color;
                }
            }
        }

        void flush() override {
            for(int i = 0; i < windowWidth + 2; i++){
                Serial.print("#");
            }
            Serial.print("\n");


            for(int i = 0; i < windowheight; i++){
                Serial.print("#");
                for(int j = 0; j < windowWidth; j++){
                    Serial.print(data[i][j]);
                }
                Serial.print("#\n");
            }


            for(int i = 0; i < windowWidth + 2; i++){
                Serial.print("#");
            }
            Serial.print("\n");
        }


    };




}

#endif //TEENSYTINYCONSOLE_WINDOWTERMINAL_HPP
