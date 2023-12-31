#ifndef TempSensor_H
#define TempSensor_H

#include<math.h>

#include "ScreensFunctions.h"
#include "GPIOInputChickFounction.h"

#define Thermister_1_pin  A6
#define Thermister_2_pin  A7

float SetPoint      = 22.00;
float SetPointDiff  = 2.00;
String Temp_Alarm_reason1 = "Empty";
String Temp_Alarm_reason2 = "Empty";

void Thermister_init()
{
  pinMode(Thermister_1_pin,INPUT);
  pinMode(Thermister_2_pin,INPUT);
}

double Thermister1()
{
  double temp;
  temp = log(10000.0 * ((1024.0 / analogRead(Thermister_1_pin) - 1)));
  temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp)) * temp);
  temp = temp - 273.15;
  //Serial.print(temp);
  //Serial.println(" Celcius");
  //Fahrenheit formela
  // temp = ((temp * 9.0) / 5.0 + 32.0);
  //Serial.print(analogRead(Thermister_1_pin));
  //Serial.println(" PIN Reading");
  return temp;
}

double Thermister2()
{
  double temp;
  temp = log(10000.0 * ((1024.0 / analogRead(Thermister_2_pin) - 1)));
  temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp)) * temp);
  temp = temp - 273.15;
  //Serial.print(temp);
  //Serial.println(" Celcius");
  //Fahrenheit formela
  // temp = ((temp * 9.0) / 5.0 + 32.0);
  //Serial.print(analogRead(Thermister_2_pin));
  //Serial.println(" PIN Reading");
  return temp;
}

void IncreaseTemp(unsigned int * page_num)
{
  if(*page_num == 1)
  {
    SetPoint++;
  }
  else if(*page_num == 2)
  {
    SetPointDiff++;
  }
}

void DecreaseTemp(unsigned int * page_num)
{
  if(*page_num == 1)
  {
    SetPoint--;
  }
  else if(*page_num == 2)
  {
    SetPointDiff--;
  }
}

void check_Input_Output_temp_def()
{
  if(Thermister1() <= Thermister2()) //if the Temprature that enter the system is colder then the temprature that gets out that means something is wrong.
  {
    temperature_difference_Alarm = HIGH;
    Temp_Alarm_reason1 = "reverse flow or     ";
    Temp_Alarm_reason2 = " sensor failure     ";
  }
  if(Thermister1() < 4 || Thermister2() < 4)
  {
    Temp_Alarm_reason1 = "Low temp or sensor  ";
    Temp_Alarm_reason2 = " failure            ";
    temperature_difference_Alarm = HIGH;
  }
  if (temperature_difference_Alarm == LOW)
  {
    Temp_Alarm_reason1 = "Empty";
    Temp_Alarm_reason2 = "Empty";
    //temperature_difference_Alarm = LOW;
  }
}

#endif
