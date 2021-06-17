//
// Created by daang on 4/11/2021.
//

#ifndef TEENSYTINYCONSOLE_CONTROLLER_HPP
#define TEENSYTINYCONSOLE_CONTROLLER_HPP
#include "Arduino.h"

#include "USBHost_t36.h"

enum class axisname{
    LeftStickXaxis,
    LeftStickYaxis,
    RightStickXaxis,
    RightStickYaxis,
    LeftTrigger,
    RightTrigger
};

class Controller {

    USBHost host;

    JoystickController controller;

    uint8_t getAxisValue(axisname axis){

    }

    Controller() : controller(host) {
        host.begin();
        controller.

    }


public:
    bool IsButtonPressed(uint8_t button){
        if(controller.available()){
            return controller.getButtons() & (1<<button);
        }
        return false;
    }
};

#endif //TEENSYTINYCONSOLE_CONTROLLER_HPP
