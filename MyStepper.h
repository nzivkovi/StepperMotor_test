#ifndef MyStepper_h
#define MyStepper_h

#include "Arduino.h"
#include <math.h>

enum Direction {counterclockwise, clockwise};

struct MyStepper
{
    MyStepper(int pin1, int pin2, int pin3, int pin4, float max_speed);
    
    //move
    void set_angular_velocity(float angular_velocity);
    void set_direction(Direction dir);
    void make_step();
    void drive();
    void increase_step();
    void decrease_step();
    Direction dir;

    //time
    unsigned long last_time;
    unsigned long current_time;
    unsigned long delay_time;        
    
    //info
    int pin1;
    int pin2;
    int pin3;
    int pin4;
    float max_speed;
    unsigned char step_nr;

};

#endif
