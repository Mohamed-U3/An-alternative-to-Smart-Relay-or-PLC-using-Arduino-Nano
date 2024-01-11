#ifndef TempSensor_H
#define TempSensor_H

#include<math.h>

#include "ScreensFunctions.h"
#include "GPIOInputChickFounction.h"
#include "EEPROMLibrary.h"

#define Thermister_1_pin  A6
#define Thermister_2_pin  A7

float SetPoint      = 22.00;
float SetPointDiff  = 2.00;
signed char sensorOffset1 = 0;
signed char sensorOffset2 = 0;
extern String Temp_Alarm_reason1 = "Empty";
extern String Temp_Alarm_reason2 = "Empty";


void Thermister_init()
{
//  SetPoint      = 20.00;
//  EEPROM.put(0, SetPoint);
  pinMode(Thermister_1_pin,INPUT);
  pinMode(Thermister_2_pin,INPUT);
  EEPROM.get(float_SetPoint_ADDRESS, SetPoint);
  EEPROM.get(float_SetPointDiff_ADDRESS, SetPointDiff);
  EEPROM.get(signed_char_sensorOffset1_ADDRESS, sensorOffset1);
  EEPROM.get(signed_char_sensorOffset2_ADDRESS, sensorOffset2);
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
  return (temp + sensorOffset1);
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
  return (temp + sensorOffset2);
}

void IncreaseTemp(unsigned int * page_num)
{
  if(*page_num == 1)
  {
    SetPoint++;
    if(SetPoint>30) SetPoint=30;
    EEPROM.put(float_SetPoint_ADDRESS, SetPoint);
  }
  else if(*page_num == 2)
  {
    SetPointDiff++;
    if(SetPointDiff>10) SetPointDiff=10;
    EEPROM.put(float_SetPointDiff_ADDRESS, SetPointDiff);
  }
  else if(*page_num == 3)
  {
    sensorOffset1++;
    EEPROM.put(signed_char_sensorOffset1_ADDRESS, sensorOffset1);
  }
  else if(*page_num == 4)
  {
    sensorOffset2++;
    EEPROM.put(signed_char_sensorOffset2_ADDRESS, sensorOffset2);
  }
}

void DecreaseTemp(unsigned int * page_num)
{
  if(*page_num == 1)
  {
    SetPoint--;
    if(SetPoint<6) SetPoint=6;
    EEPROM.put(float_SetPoint_ADDRESS, SetPoint);
  }
  else if(*page_num == 2)
  {
    SetPointDiff--;
    if(SetPointDiff<1) SetPointDiff=1;
    EEPROM.put(float_SetPointDiff_ADDRESS, SetPointDiff);
  }
  else if(*page_num == 3)
  {
    sensorOffset1--;
    EEPROM.put(signed_char_sensorOffset1_ADDRESS, sensorOffset1);
  }
  else if(*page_num == 4)
  {
    sensorOffset2--;
    EEPROM.put(signed_char_sensorOffset2_ADDRESS, sensorOffset2);
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
