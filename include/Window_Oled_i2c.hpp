//
// Created by daang on 1/26/2021.
//

#ifndef TEENSYTINYCONSOLE_WINDOW_OLED_I2C_HPP
#define TEENSYTINYCONSOLE_WINDOW_OLED_I2C_HPP

#include "Arduino.h"

#include "Window.hpp"
#include "Adafruit_SSD1306.h"
#include "Wire.h"

namespace TTC{

    template<int width, int height>
    class Oled_Window : public TTC::Window {
        Adafruit_SSD1306 display;
        uint32_t adress;

    public:

        explicit Oled_Window(uint32_t adress) : display(width, height, &Wire, 4), adress(adress) {
            display.begin(SSD1306_SWITCHCAPVCC, adress, false, false);
            display.clearDisplay();
        }

        void flush() override {
            display.display();
        }

        void drawPixel(int x, int y, uint8_t color) override {
            if (color >= 0 && color <= 2) {
                display.drawPixel(x, y, color);
            }
        }

        int getWidth() override { return width; }

        int getHeight() override { return height; }

        void clear(uint8_t color) override {
            display.clearDisplay();
        }
    };

}

#endif //TEENSYTINYCONSOLE_WINDOW_OLED_I2C_HPP
