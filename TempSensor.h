#ifndef TempSensor_H
#define TempSensor_H

#include<math.h>

#define Thermister_1_pin  A6
#define Thermister_2_pin  A7

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
#endif
