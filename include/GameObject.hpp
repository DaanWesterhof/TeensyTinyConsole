//
// Created by daang on 1/22/2021.
//

#ifndef INTOSPACE_BULLETHELL_GAMEOBJECT_HPP
#define INTOSPACE_BULLETHELL_GAMEOBJECT_HPP

#include "Drawable.hpp"

#ifdef min
#undef min
#endif
#ifdef max
#undef max
#endif

#include <functional>


namespace TTC {

    //This class is to be extended, it can be used but wont be very helpfull,
    template<typename... FuncArgTypes>
    class GameObject {

    public:
        std::function<void(GameObject<FuncArgTypes...>&, FuncArgTypes...)> extraFunctions[10];
        int function_count = 0;

        std::function<bool(GameObject<FuncArgTypes...>&, FuncArgTypes...)> condition;

        std::function<void(GameObject<FuncArgTypes...>&, FuncArgTypes...)> condAction;

        std::function<void(GameObject<FuncArgTypes...>&, FuncArgTypes...)> uncondAction;

    public:


        virtual void update() {
            if(condition(*this)){
                condAction(*this);
            }
            uncondAction(*this);

            for(int i = 0; i < function_count; i++){
                extraFunctions[i](*this);
            }
        }

        explicit operator GameObject<>* (){
            return reinterpret_cast<GameObject<> *>(this);
        }

        GameObject<>* getGamePointer(){
            return reinterpret_cast<GameObject<> *>(this);
        }

        void applyFunction(std::function<void(GameObject<FuncArgTypes...>&, FuncArgTypes...)> function) {
            if(function_count < 10){
                extraFunctions[function_count] = function;
                function_count++;
            }
        }
    };


}

#endif //INTOSPACE_BULLETHELL_GAMEOBJECT_HPP
