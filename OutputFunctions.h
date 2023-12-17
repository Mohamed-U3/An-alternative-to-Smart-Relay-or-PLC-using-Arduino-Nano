#ifndef OutputFunctions_H
#define OutputFunctions_H

#define Motor1_pin A1
#define Motor2_pin A2

void Motors_init()
{
  pinMode(Motor1_pin,OUTPUT);
  pinMode(Motor2_pin,OUTPUT);
  digitalWrite(Motor1_pin,LOW);
  digitalWrite(Motor2_pin,LOW);
}

void Motor1_on()
{ digitalWrite(Motor1_pin,HIGH); }

void Motor1_off()
{digitalWrite(Motor1_pin,LOW); }

void Motor2_on()
{ digitalWrite(Motor2_pin,HIGH); }

void Motor2_off()
{digitalWrite(Motor2_pin,LOW); }

#endif
