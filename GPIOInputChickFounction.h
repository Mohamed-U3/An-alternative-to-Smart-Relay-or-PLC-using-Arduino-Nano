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
  ====================================================
 */

bool D0_SW_Alarm                    = LOW;
bool D1_FlowSW_Alarm                = LOW;
bool D2_PhaseSq_Alarm               = LOW;
bool D3_HighPressure1_Alarm         = LOW;
bool D4_LowPressure1_Alarm          = LOW;
bool D5_OverLoadComperssor1_Alarm   = LOW;
bool D6_OverLoadCFM1_Alarm          = LOW;
bool D7_MotorProtector1_Alarm       = LOW;
bool D8_OilPressure1_Alarm          = LOW;
bool D9_HighPressure2_Alarm         = LOW;
bool D10_LowPressure2_Alarm         = LOW;
bool D11_OverLoadComperssor2_Alarm  = LOW;
bool D12_OverLoadCFM2_Alarm         = LOW;
bool D13_MotorProtector2_Alarm      = LOW;
bool D14_OilPressure2_Alarm         = LOW;

bool temperature_difference_Alarm   = LOW;

bool anyAlarm                       = LOW;
bool anyAlarm1                      = LOW;
bool anyAlarm2                      = LOW;

void GPIO_init()
{
  for(int i=0; i<= 14 ; i++)
  { pinMode(i , INPUT); }
}

String D0_SW()
{
  if(digitalRead(0) == HIGH)
  {
    D0_SW_Alarm = LOW;
    return "OK ";
  }
  else
  {
    D0_SW_Alarm = HIGH;
    return "Err";
  }
}

String D1_FlowSW()
{
  if(digitalRead(1) == HIGH) return "OK ";
  else
  {
    D1_FlowSW_Alarm = HIGH;
    return "Err";
  }
}

String D2_PhaseSq()
{
  if(digitalRead(2) == HIGH) return "OK ";
  else
  {
    D2_PhaseSq_Alarm = HIGH;
    return "Err";
  }
}

String D3_HighPressure1()
{
  if(digitalRead(3) == HIGH) return "OK ";
  else
  {
    D3_HighPressure1_Alarm = HIGH;
    return "Err";
  }
}

String D4_LowPressure1()
{
  if(digitalRead(4) == HIGH) return "OK ";
  else
  {
    D4_LowPressure1_Alarm = HIGH;
    return "Err";
  }
}

String D5_OverLoadComperssor1()
{
  if(digitalRead(5) == HIGH) return "OK ";
  else
  {
    D5_OverLoadComperssor1_Alarm = HIGH;
    return "Err";
  }
}

String D6_OverLoadCFM1()
{
  if(digitalRead(6) == HIGH) return "OK ";
  else
  {
    D6_OverLoadCFM1_Alarm = HIGH;
    return "Err";
  }
}

String D7_MotorProtector1()
{
  if(digitalRead(7) == HIGH) return "OK ";
  else
  {
    D7_MotorProtector1_Alarm = HIGH;
    return "Err";
  }
}

String D8_OilPressure1()
{
  if(digitalRead(8) == HIGH) return "OK ";
  else
  {
    D8_OilPressure1_Alarm = HIGH;
    return "Err";
  }
}

String D9_HighPressure2()
{
  if(digitalRead(9) == HIGH) return "OK ";
  else
  {
    D9_HighPressure2_Alarm = HIGH;
    return "Err";
  }
}

String D10_LowPressure2()
{
  if(digitalRead(10) == HIGH) return "OK ";
  else
  {
    D10_LowPressure2_Alarm = HIGH;
    return "Err";
  }
}

String D11_OverLoadComperssor2()
{
  if(digitalRead(11) == HIGH) return "OK ";
  else
  {
    D11_OverLoadComperssor2_Alarm = HIGH;
    return "Err";
  }
}

String D12_OverLoadCFM2()
{
  if(digitalRead(12) == HIGH) return "OK ";
  else
  {
    D12_OverLoadCFM2_Alarm = HIGH;
    return "Err";
  }
}

String D13_MotorProtector2()
{
  if(digitalRead(13) == HIGH) return "OK ";
  else
  {
    D13_MotorProtector2_Alarm = HIGH;
    return "Err";
  }
}

String D14_OilPressure2()
{
  if(digitalRead(14) == HIGH) return "OK ";
  else
  {
    D14_OilPressure2_Alarm = HIGH;
    return "Err";
  }
}

void Alarm_sum()
{
  //this is additional Idea I'm trying ( im lettel affread that is idea might make the system slow
   D0_SW();
   D1_FlowSW();
   D2_PhaseSq();

   // = comperasor 1 ==================================
   D3_HighPressure1();
   D4_LowPressure1();
   D5_OverLoadComperssor1();
   D6_OverLoadCFM1();
   D7_MotorProtector1();
   D8_OilPressure1();

   //= comperasor 2 ==================================
   D9_HighPressure2();
   D10_LowPressure2();
   D11_OverLoadComperssor2();
   D12_OverLoadCFM2();
   D13_MotorProtector2();
   D14_OilPressure2();
  
  
  //the original Idea of Aleams is here 
  anyAlarm =  D0_SW_Alarm                   ||
              D1_FlowSW_Alarm               ||
              D2_PhaseSq_Alarm              ||
              temperature_difference_Alarm  ;
              
  anyAlarm1 = D3_HighPressure1_Alarm        ||
              D4_LowPressure1_Alarm         ||
              D5_OverLoadComperssor1_Alarm  ||
              D6_OverLoadCFM1_Alarm         ||
              D7_MotorProtector1_Alarm      ||
              D8_OilPressure1_Alarm         ;
              
  anyAlarm2 = D9_HighPressure2_Alarm        ||
              D10_LowPressure2_Alarm        ||
              D11_OverLoadComperssor2_Alarm ||
              D12_OverLoadCFM2_Alarm        ||
              D13_MotorProtector2_Alarm     ||
              D14_OilPressure2_Alarm        ;
              
}

#endif
