//
// Created by daang on 1/22/2021.
//

#ifndef INTOSPACE_BULLETHELL_WINDOWVGA_HPP
#define INTOSPACE_BULLETHELL_WINDOWVGA_HPP

#include "Window.hpp"
#include "VGA_t4.h"
namespace TTC {

    template<int windowHeight, int windowWidth>
    class VGA_Window : public Window {
    private:
        uint8_t data[windowHeight][windowWidth]{};


    public:
        int row =0, col=0;
        int height =0;
        int width =0;
        VGA_T4 handler;

        void drawPixel(int x, int y, uint8_t color) override{
            data[y][x] = color;
        }

        int getWidth() override {
            return width;
        }

        int getHeight() override {
            return height;
        }

        void clear(uint8_t color) override {
            for(int i = 0; i < windowHeight; i++){
                for(int j = 0; j < windowWidth; j++){
                    data[i][j] = color;
                }
            }
        }

        void flush() override{
            for(int i = 0; i < windowHeight; i++){
                for(int j = 0; j < windowWidth; j++){
                    handler.drawPixel(j, i, data[i][j]);
                }
            }
        }

        VGA_Window() {
            int ret = static_cast<int>(handler.begin(vga_mode_t::VGA_MODE_640x480));

            Serial.println(ret);

            if(ret != 0)
            {
                Serial.println("fatal error");
                while(1);
            }
            handler.clear(VGA_RGB(0x00,0x00,0x00));
            handler.get_frame_buffer_size(&width, &height);
        }


    };

}

#endif //INTOSPACE_BULLETHELL_WINDOWVGA_HPP
