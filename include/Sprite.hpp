//
// Created by daang on 1/19/2021.
//

#ifndef TEENSYTINYCONSOLE_SPRITE_HPP
#define TEENSYTINYCONSOLE_SPRITE_HPP

#include <memory>
#include "Drawable.hpp"
#include "Colors.hpp"
#include "Canvas.hpp"
#include "Image.hpp"

namespace TTC {

    class Sprite : public Drawable {

        std::unique_ptr<uint8_t[]> data;
        std::unique_ptr<bool[]>mask;
        int size_multiplier;


    public:
        int width, height;

        Sprite(Point point, uint8_t * image, int width, int height) : Drawable(point), data(image), width(width), height(height) {}

        template<int imageWidth, int ImageHeight>
        Sprite(Point point, Image<imageWidth, ImageHeight> & image, Point SpriteStart, Point SpriteEnd, int size_multiplier = 1) :
            Drawable(point),
            data(std::make_unique<uint8_t[]>(imageWidth * ImageHeight)),
            mask(std::make_unique<bool[]>(imageWidth * ImageHeight)),
            size_multiplier(size_multiplier),
            width((SpriteEnd.x - SpriteStart.x) * size_multiplier),
            height((SpriteEnd.y - SpriteStart.y) * size_multiplier)
        {
            for( int i = 0; i < SpriteEnd.x - SpriteStart.x; i++){
                for( int j = 0; j < SpriteEnd.y -SpriteStart.y; j++){
                    data[i + j * (SpriteEnd.x - SpriteStart.x)] = image.data[i + SpriteStart.x][j + SpriteStart.y];
                    mask[i + j * (SpriteEnd.x - SpriteStart.x)] = image.mask[i + SpriteStart.x][j + SpriteStart.y];
                }
            }

        }


        Rect getRect() override{
            return Rect(point, width, height);
        }

        void draw(Canvas & canvas) override {
            for(int i = 0; i < width * size_multiplier; i++){
                for(int j = 0; j < height *size_multiplier; j++){
                    if(mask[(i/size_multiplier) + (j/size_multiplier) * width]) {
                        canvas.setPixel(i + point.x, j + point.y, data[(i/size_multiplier) + (j/size_multiplier) * width]);
                    }
                }
            }
        }
    };

    template<int SpriteAmount>
    class SpriteBox {
    public:
        int activeSprite= 0;

        Sprite sprites[SpriteAmount];
        int sprite_count = 0;

        template<int imageWidth, int ImageHeight>
        void LoadSpriteMap(Image<imageWidth, ImageHeight> * image, int amount, int width, int height, int size_multiplier = 1){
            int x_start = 0;
            int y_start = 0;
            for(int i = 0; i < amount; i++){
                sprites[sprite_count] = Sprite(image, Point(x_start, y_start), Point(x_start + width, y_start+height), size_multiplier);
                x_start += width;
                if(x_start > imageWidth - width){
                    x_start = 0;
                    y_start += height;
                }
            }
        }
    };

}


#endif //TEENSYTINYCONSOLE_SPRITE_HPP
