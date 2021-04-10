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
#include <vector>
#include <string>
#include "Canvas.hpp"

class GameEngine {
public://variables
    std::vector<std::shared_ptr<TTC::GameObject<>>*> object_lists;
    std::vector<std::string> object_list_names;
    std::vector<std::pair<int, int>> object_count;
    int count = 0;

    TTC::Canvas & canvas;




public://variables

private://variables

public://variables

    explicit GameEngine(TTC::Canvas & canvas) : canvas(canvas) {}

    void updateAll(){
        for(int i = 0; i < object_lists.size(); i++){
            for(int j = 0; j < object_count[i].first; j++){
                while(object_lists[i][j]->destroy){
                    if(j != object_count[i].first-1) {
                        object_lists[i][j] = object_lists[i][object_count[i].first - 1];
                    }
                    object_count[i].first -= 1;
                }
                object_lists[i][j]->update();
            }
        }
    }

    void update(const std::string& list_name) {
        for(int i = 0; i < object_list_names.size(); i++){
            if(object_list_names[i] == list_name){
                for(int j = 0; j < object_count[i].first; j++){
                    while(object_lists[i][j]->destroy){
                        if(j != object_count[i].first-1) {
                            object_lists[i][j] = object_lists[i][object_count[i].first - 1];
                        }
                        object_count[i].first -= 1;
                    }
                    object_lists[i][j]->update();
                }
            }
        }
    }



    template<typename T, typename... ObjectParameters>
    int factoryAdd(const std::string& list_name, ObjectParameters... args){
        if(std::is_base_of<TTC::GameObject<>, T>::value){
            for(int i = 0; i < object_list_names.size(); i++){
                if(object_list_names[i] == list_name && object_count[i].first < object_count[i].second) {
                    object_lists[i][object_count[i].first] = std::make_shared<T>(args...);
                    object_count[i].first += 1;
                    return object_count[i].first -1;
                }
            }
        }
        return -1;
    }


    template<typename ...par>
    void applyFunctionAll(std::function<void(TTC::GameObject<par...>&, par...)> function){
        for(int i = 0; i < object_lists.size(); i++){
            applyFunction(function, object_list_names[i]);
        }
    }

    template<typename ...par>
    void applyFunction(std::function<void(TTC::GameObject<par...>&, par...)> function, std::string list_names) {
        for(int i = 0; i < object_list_names.size(); i++){
            if(object_list_names[i] == list_names) {
                for (int j = 0; j < object_count[i].first; j++) {
                    object_lists[i][j]->applyFunction(function);
                }
                break;
            }
        }

    }

    void addObjectArray(int size, const std::string& name){
        auto thing = new std::shared_ptr<TTC::GameObject<>>[size];
        object_lists.emplace_back(thing);
        object_count.emplace_back(std::pair<int, int>(0,size));
        object_list_names.emplace_back(name);
    }

    std::shared_ptr<TTC::GameObject<>>* operator[](const std::string& name){
        for(int i = 0; i < object_list_names.size(); i++){
            if(object_list_names[i] == name){
                return object_lists[i];
            }
        }
        return nullptr;
    }
};


#endif //TEENSYTINYCONSOLE_GAMEENGINE_HPP
