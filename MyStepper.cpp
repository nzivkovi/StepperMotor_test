#include "Arduino.h"
#include "MyStepper.h"


MyStepper::MyStepper(int pin1, int pin2, int pin3, int pin4, float max_speed)
{
  this->pin1 = pin1;
  this->pin2 = pin2;
  this->pin3 = pin3;
  this->pin4 = pin4;
  pinMode(this->pin1, OUTPUT); 
  pinMode(this->pin2, OUTPUT); 
  pinMode(this->pin3, OUTPUT); 
  pinMode(this->pin4, OUTPUT);   
  this->max_speed = max_speed;
  this->dir = counterclockwise;
  this->step_nr = 0;
  this->current_time = micros();
  this->last_time = this->current_time;

}


void MyStepper::set_angular_velocity(float angular_velocity)
{
  if(angular_velocity == 0.0)
  {
     this->delay_time = 4294967295;
  } else {
    this->delay_time = (unsigned long)(this->max_speed / angular_velocity * 1000);  
  }
  
  
}

void MyStepper::set_direction(Direction dir)
{
  this->dir = dir;
}

void MyStepper::increase_step()
{
  if(this->step_nr == 7){
    this->step_nr = 0;
  } else {
    step_nr++;
  }
}

void MyStepper::decrease_step()
{
  if(this->step_nr == 0){
    this->step_nr = 7;
  } else {
    step_nr--;
  }
}

void MyStepper::make_step()
{
  /*Serial.print("(");
  Serial.print(this->current_time - this->last_time);
  Serial.print(",");
  Serial.print(this->delay_time);
  Serial.println(")");*/
  switch(this->step_nr){
    case 0:
      digitalWrite(this->pin1, LOW); 
      digitalWrite(this->pin2, LOW);
      digitalWrite(this->pin3, LOW);
      digitalWrite(this->pin4, HIGH);
    break;
    case 1:
      digitalWrite(this->pin1, LOW); 
      digitalWrite(this->pin2, LOW);
      digitalWrite(this->pin3, HIGH);
      digitalWrite(this->pin4, HIGH);
    break;     
    case 2:
      digitalWrite(this->pin1, LOW); 
      digitalWrite(this->pin2, LOW);
      digitalWrite(this->pin3, HIGH);
      digitalWrite(this->pin4, LOW);
    break;     
    case 3:
      digitalWrite(this->pin1, LOW); 
      digitalWrite(this->pin2, HIGH);
      digitalWrite(this->pin3, HIGH);
      digitalWrite(this->pin4, LOW);
    break;     
    case 4:
      digitalWrite(this->pin1, LOW); 
      digitalWrite(this->pin2, HIGH);
      digitalWrite(this->pin3, LOW);
      digitalWrite(this->pin4, LOW);
    break;     
    case 5:
      digitalWrite(this->pin1, HIGH); 
      digitalWrite(this->pin2, HIGH);
      digitalWrite(this->pin3, LOW);
      digitalWrite(this->pin4, LOW);
    break;     
    case 6:
      digitalWrite(this->pin1, HIGH); 
      digitalWrite(this->pin2, LOW);
      digitalWrite(this->pin3, LOW);
      digitalWrite(this->pin4, LOW);
    break;     
    case 7:
      digitalWrite(this->pin1, HIGH); 
      digitalWrite(this->pin2, LOW);
      digitalWrite(this->pin3, LOW);
      digitalWrite(this->pin4, HIGH);
    break;     
    default:
      digitalWrite(this->pin1, LOW); 
      digitalWrite(this->pin2, LOW);
      digitalWrite(this->pin3, LOW);
      digitalWrite(this->pin4, LOW);
    break;        
  }
  if(this->dir == counterclockwise)
  {
    this->increase_step();  
  } else {
    this->decrease_step();
  }
}

void MyStepper::drive()
{
  this->current_time = micros();
  if(this->current_time - this->last_time >= this->delay_time)
  {
    this->make_step();
    this->last_time = this->current_time;
  }
}
