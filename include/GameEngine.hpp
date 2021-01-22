//
// Created by daang on 1/19/2021.
//

#ifndef TEENSYTINYCONSOLE_GAMEENGINE_HPP
#define TEENSYTINYCONSOLE_GAMEENGINE_HPP

#include "Drawable.hpp"

template<int itemCount>
class GameEngine {
private://variables
    Drawable *drawables[itemCount];
    int count;

public://variables

private://variables

public://variables
    void update() {
        for(int i = 0; i < count; i++){
            drawables[i]->update();
        }
    }

    bool addDrawable(Drawable* drawable) {
        if(count < itemCount){
            drawables[count] = drawable;
        }
    }

};


#endif //TEENSYTINYCONSOLE_GAMEENGINE_HPP
