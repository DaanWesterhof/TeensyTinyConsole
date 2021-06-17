//
// Created by daang on 4/11/2021.
//

#include "Arduino.h"
#include "Time.h"
#include "TimeLib.h"
#ifndef TEENSYTINYCONSOLE_CLOCK_HPP
#define TEENSYTINYCONSOLE_CLOCK_HPP

namespace TTC{

    struct TimeObject{
        unsigned long time_value;

        unsigned long asMilliseconds() const{
            return time_value;
        }

        unsigned long asSeconds() const{
            return time_value / 1000;
        }

        unsigned long asMinutes() const{
            return (time_value/1000)/60;
        }

        unsigned long asHours() const{
            return asMinutes()/60;
        }

        explicit TimeObject(unsigned long thetime) : time_value(thetime) {}
    };

    class Clock {
        unsigned long start_time = 0;
    public:

        void reset(){
            start_time = millis();
        }

        TimeObject getElapsedTime() const{
            return TimeObject(millis() - start_time);
        }
    };

}


#endif //TEENSYTINYCONSOLE_CLOCK_HPP
