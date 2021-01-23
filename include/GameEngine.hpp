//
// Created by daang on 1/19/2021.
//

#ifndef TEENSYTINYCONSOLE_GAMEENGINE_HPP
#define TEENSYTINYCONSOLE_GAMEENGINE_HPP

#include "Drawable.hpp"
#include "GameObject.hpp"

#undef min
#undef max
#include "memory"
#include <type_traits>

template<int itemCount>
class GameEngine {
private://variables
    std::shared_ptr<TTC::GameObject<>>objects[itemCount];
    int count = 0;

public://variables

private://variables

public://variables
    void update() {
        for(int i = 0; i < count; i++){
            objects[i]->update();
        }
    }

//    bool addObject(TTC::GameObject<>* object) {
//        if(count < itemCount){
//            objects[count] = object;
//            return true;
//        }
//        return false;
//    }

    template<typename T, typename... ObjectParameters>
    bool factoryAdd(ObjectParameters... args){
        if(count < itemCount && std::is_base_of<TTC::GameObject<>, T>::value){
            objects[count] = std::make_shared<T>(args...);
            count++;
            return true;
        }
        return false;
    }

    template<typename ...par>
    void applyFunction(std::function<void(TTC::GameObject<par...>&, par...)> function) {
        for(int i = 0; i < count; i++){
            objects[i]->applyFunction(function);
        }
    }

};


#endif //TEENSYTINYCONSOLE_GAMEENGINE_HPP
