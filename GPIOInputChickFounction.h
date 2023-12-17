#ifndef GPIOInputChickFounction_H
#define GPIOInputChickFounction_H


void GPIO_init()
{
  for(int i=0; i<= 14 ; i++)
  { pinMode(i , INPUT_PULLUP); }
}

bool GPIO_Chick()
{
  return digitalRead(0)&
         digitalRead(1)&
         digitalRead(2)&
         digitalRead(3)&
         digitalRead(4)&
         digitalRead(5)&
         digitalRead(6)&
         digitalRead(7)&
         digitalRead(8)&
         digitalRead(9)&
         digitalRead(10)&
         digitalRead(11)&
         digitalRead(12)&
         digitalRead(13)&
         digitalRead(14);
}

#endif
