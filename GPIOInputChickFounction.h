#ifndef GPIOInputChickFounction_H
#define GPIOInputChickFounction_H

/* ==================================================
 *  List of Founction used to chick on each input pin
    = General  ======================================
    D0_SW()
    D1_FlowSW()
    D2_PhaseSq()

    = comperasor 1 ==================================
    D3_HighPressure1()
    D4_LowPressure1()
    D5_OverLoadComperssor1()
    D6_OverLoadCFM1()
    D7_MotorProtector1()
    D8_OilPressure1()

    = comperasor 2 ==================================
    D9_HighPressure2()
    D10_LowPressure2()
    D11_OverLoadComperssor2()
    D12_OverLoadCFM2()
    D13_MotorProtector2()
    D14_OilPressure2()
 */

void GPIO_init()
{
  for(int i=0; i<= 14 ; i++)
  { pinMode(i , INPUT); }
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

String D0_SW()
{
  if(digitalRead(0) == HIGH) return "OK ";
  else return "Err";
}

String D1_FlowSW()
{
  if(digitalRead(1) == HIGH) return "OK ";
  else return "Err";
}

String D2_PhaseSq()
{
  if(digitalRead(2) == HIGH) return "OK ";
  else return "Err";
}

String D3_HighPressure1()
{
  if(digitalRead(3) == HIGH) return "OK ";
  else return "Err";
}

String D4_LowPressure1()
{
  if(digitalRead(4) == HIGH) return "OK ";
  else return "Err";
}

String D5_OverLoadComperssor1()
{
  if(digitalRead(5) == HIGH) return "OK ";
  else return "Err";
}

String D6_OverLoadCFM1()
{
  if(digitalRead(6) == HIGH) return "OK ";
  else return "Err";
}

String D7_MotorProtector1()
{
  if(digitalRead(7) == HIGH) return "OK ";
  else return "Err";
}

String D8_OilPressure1()
{
  if(digitalRead(8) == HIGH) return "OK ";
  else return "Err";
}

String D9_HighPressure2()
{
  if(digitalRead(9) == HIGH) return "OK ";
  else return "Err";
}

String D10_LowPressure2()
{
  if(digitalRead(10) == HIGH) return "OK ";
  else return "Err";
}

String D11_OverLoadComperssor2()
{
  if(digitalRead(11) == HIGH) return "OK ";
  else return "Err";
}

String D12_OverLoadCFM2()
{
  if(digitalRead(12) == HIGH) return "OK ";
  else return "Err";
}

String D13_MotorProtector2()
{
  if(digitalRead(13) == HIGH) return "OK ";
  else return "Err";
}

String D14_OilPressure2()
{
  if(digitalRead(14) == HIGH) return "OK ";
  else return "Err";
}

#endif
