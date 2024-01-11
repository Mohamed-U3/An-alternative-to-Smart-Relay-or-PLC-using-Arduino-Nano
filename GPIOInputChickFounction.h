#ifndef GPIOInputChickFounction_H
#define GPIOInputChickFounction_H

#include "EEPROMLibrary.h"
#include "TempSensor.h"

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
extern String Temp_Alarm_reason1;
extern String Temp_Alarm_reason2;

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

  static bool Last_D1_FlowSW_Alarm               = LOW;
  static bool Last_D2_PhaseSq_Alarm              = LOW;
  static bool Last_temperature_difference_Alarm  = LOW;
  static bool Last_D3_HighPressure1_Alarm        = LOW;
  static bool Last_D4_LowPressure1_Alarm         = LOW;
  static bool Last_D5_OverLoadComperssor1_Alarm  = LOW;
  static bool Last_D6_OverLoadCFM1_Alarm         = LOW;
  static bool Last_D7_MotorProtector1_Alarm      = LOW;
  static bool Last_D8_OilPressure1_Alarm         = LOW;
  static bool Last_D9_HighPressure2_Alarm        = LOW;
  static bool Last_D10_LowPressure2_Alarm        = LOW;
  static bool Last_D11_OverLoadComperssor2_Alarm = LOW;
  static bool Last_D12_OverLoadCFM2_Alarm        = LOW;
  static bool Last_D13_MotorProtector2_Alarm     = LOW;
  static bool Last_D14_OilPressure2_Alarm        = LOW;
  
  if(Last_D1_FlowSW_Alarm != D1_FlowSW_Alarm)
  {
    EEPROM.put(bool_D1_FlowSW_Alarm_ADDRESS,                D1_FlowSW_Alarm);
    Last_D1_FlowSW_Alarm = D1_FlowSW_Alarm;
  }
  if(Last_D2_PhaseSq_Alarm != D2_PhaseSq_Alarm)
  {
    EEPROM.put(bool_D2_PhaseSq_Alarm_ADDRESS,               D2_PhaseSq_Alarm);
    Last_D2_PhaseSq_Alarm = D2_PhaseSq_Alarm;
  }
  if(Last_temperature_difference_Alarm != temperature_difference_Alarm)
  {
    EEPROM.put(bool_temperature_difference_Alarm_ADDRESS,   temperature_difference_Alarm);
    writeStringToEEPROM(String_Temp_Alarm_reason1_ADDRESS,  Temp_Alarm_reason1);
    writeStringToEEPROM(String_Temp_Alarm_reason2_ADDRESS,  Temp_Alarm_reason2);
    Last_temperature_difference_Alarm = temperature_difference_Alarm;
  }

// comp1
  if(Last_D3_HighPressure1_Alarm != D3_HighPressure1_Alarm)
  {
    EEPROM.put(bool_D3_HighPressure1_Alarm_ADDRESS,         D3_HighPressure1_Alarm);
    Last_D3_HighPressure1_Alarm = D3_HighPressure1_Alarm;
  }
  if(Last_D4_LowPressure1_Alarm != D4_LowPressure1_Alarm)
  {
    EEPROM.put(bool_D4_LowPressure1_Alarm_ADDRESS,         D4_LowPressure1_Alarm);
    Last_D4_LowPressure1_Alarm = D4_LowPressure1_Alarm;
  }
  if(Last_D5_OverLoadComperssor1_Alarm != D5_OverLoadComperssor1_Alarm)
  {
    EEPROM.put(bool_D5_OverLoadComperssor1_Alarm_ADDRESS,         D5_OverLoadComperssor1_Alarm);
    Last_D5_OverLoadComperssor1_Alarm = D5_OverLoadComperssor1_Alarm;
  }
  if(Last_D6_OverLoadCFM1_Alarm != D6_OverLoadCFM1_Alarm)
  {
    EEPROM.put(bool_D6_OverLoadCFM1_Alarm_ADDRESS,          D6_OverLoadCFM1_Alarm);
    Last_D6_OverLoadCFM1_Alarm = D6_OverLoadCFM1_Alarm;
  }
  if(Last_D7_MotorProtector1_Alarm != D7_MotorProtector1_Alarm)
  {
    EEPROM.put(bool_D7_MotorProtector1_Alarm_ADDRESS,       D7_MotorProtector1_Alarm);
    Last_D7_MotorProtector1_Alarm = D7_MotorProtector1_Alarm;
  }
  if(Last_D8_OilPressure1_Alarm != D8_OilPressure1_Alarm)
  {
    EEPROM.put(bool_D8_OilPressure1_Alarm_ADDRESS,          D8_OilPressure1_Alarm);
    Last_D8_OilPressure1_Alarm = D8_OilPressure1_Alarm;
  }

  //comp2
  if(Last_D9_HighPressure2_Alarm != D9_HighPressure2_Alarm)
  {
    EEPROM.put(bool_D9_HighPressure2_Alarm_ADDRESS,         D9_HighPressure2_Alarm);
    Last_D9_HighPressure2_Alarm = D9_HighPressure2_Alarm;
  }
  if(Last_D10_LowPressure2_Alarm != D10_LowPressure2_Alarm)
  {
    EEPROM.put(bool_D10_LowPressure2_Alarm_ADDRESS,         D10_LowPressure2_Alarm);
    Last_D10_LowPressure2_Alarm = D10_LowPressure2_Alarm;
  }
  if(Last_D11_OverLoadComperssor2_Alarm != D11_OverLoadComperssor2_Alarm)
  {
    EEPROM.put(bool_D11_OverLoadComperssor2_Alarm_ADDRESS,  D11_OverLoadComperssor2_Alarm);
    Last_D11_OverLoadComperssor2_Alarm = D11_OverLoadComperssor2_Alarm;
  }
  if(Last_D12_OverLoadCFM2_Alarm != D12_OverLoadCFM2_Alarm)
  {
    EEPROM.put(bool_D12_OverLoadCFM2_Alarm_ADDRESS,         D12_OverLoadCFM2_Alarm);
    Last_D12_OverLoadCFM2_Alarm = D12_OverLoadCFM2_Alarm;
  }
  if(Last_D13_MotorProtector2_Alarm != D13_MotorProtector2_Alarm)
  {
    EEPROM.put(bool_D13_MotorProtector2_Alarm_ADDRESS,      D13_MotorProtector2_Alarm);
    Last_D13_MotorProtector2_Alarm = D13_MotorProtector2_Alarm;
  }
  if(Last_D14_OilPressure2_Alarm != D14_OilPressure2_Alarm)
  {
    EEPROM.put(bool_D14_OilPressure2_Alarm_ADDRESS,         D14_OilPressure2_Alarm);
    Last_D14_OilPressure2_Alarm = D14_OilPressure2_Alarm;
  }
}

void Alarms_init()
{
  EEPROM.get(bool_D1_FlowSW_Alarm_ADDRESS,                D1_FlowSW_Alarm);
  EEPROM.get(bool_D2_PhaseSq_Alarm_ADDRESS,               D2_PhaseSq_Alarm);
  EEPROM.get(bool_D3_HighPressure1_Alarm_ADDRESS,         D3_HighPressure1_Alarm);
  EEPROM.get(bool_D4_LowPressure1_Alarm_ADDRESS,          D4_LowPressure1_Alarm);
  EEPROM.get(bool_D5_OverLoadComperssor1_Alarm_ADDRESS,   D5_OverLoadComperssor1_Alarm);
  EEPROM.get(bool_D6_OverLoadCFM1_Alarm_ADDRESS,          D6_OverLoadCFM1_Alarm);
  EEPROM.get(bool_D7_MotorProtector1_Alarm_ADDRESS,       D7_MotorProtector1_Alarm);
  EEPROM.get(bool_D8_OilPressure1_Alarm_ADDRESS,          D8_OilPressure1_Alarm);
  EEPROM.get(bool_D9_HighPressure2_Alarm_ADDRESS,         D9_HighPressure2_Alarm);
  EEPROM.get(bool_D10_LowPressure2_Alarm_ADDRESS,         D10_LowPressure2_Alarm);
  EEPROM.get(bool_D11_OverLoadComperssor2_Alarm_ADDRESS,  D11_OverLoadComperssor2_Alarm);
  EEPROM.get(bool_D12_OverLoadCFM2_Alarm_ADDRESS,         D12_OverLoadCFM2_Alarm);
  EEPROM.get(bool_D13_MotorProtector2_Alarm_ADDRESS,      D13_MotorProtector2_Alarm);
  EEPROM.get(bool_D14_OilPressure2_Alarm_ADDRESS,         D14_OilPressure2_Alarm);
  EEPROM.get(bool_temperature_difference_Alarm_ADDRESS,   temperature_difference_Alarm);

  Temp_Alarm_reason1 = readStringFromEEPROM(String_Temp_Alarm_reason1_ADDRESS);
  Temp_Alarm_reason2 = readStringFromEEPROM(String_Temp_Alarm_reason2_ADDRESS);
}

#endif
