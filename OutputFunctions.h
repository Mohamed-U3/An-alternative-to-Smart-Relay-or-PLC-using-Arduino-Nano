#ifndef OutputFunctions_H
#define OutputFunctions_H

#define Motor1_pin      A1
#define Motor2_pin      A2
#define Com_1_OperationDelay  30000//300000
#define Com_2_OperationDelay  50000//500000
#define TempDefBetCom1andCom2 2
long PreMillis1 = 0;
long PreMillis2 = 0;

void Motors_init()
{
  pinMode(Motor1_pin, OUTPUT);
  pinMode(Motor2_pin, OUTPUT);
  digitalWrite(Motor1_pin, LOW);
  digitalWrite(Motor2_pin, LOW);
}

void Motor1_on()
{
  Alarm_sum();
  if (anyAlarm == LOW) digitalWrite(Motor1_pin, HIGH);  //check the alarms First
  else                digitalWrite(Motor1_pin, LOW);
}

void Motor1_off()
{
  digitalWrite(Motor1_pin, LOW);
}

void Motor2_on()
{
  Alarm_sum();
  if (anyAlarm == LOW) digitalWrite(Motor2_pin, HIGH);  //check the alarms First
  else                digitalWrite(Motor2_pin, LOW);
}

void Motor2_off()
{
  digitalWrite(Motor2_pin, LOW);
}


void Operation()
{
  check_Input_Output_temp_def();

  if(resetTimerFlag1)
  {
    PreMillis1 = millis(); // reset the time counter.
    resetTimerFlag1 =! resetTimerFlag1;
  }
  if(resetTimerFlag2)
  {
    PreMillis2 = millis(); // reset the time counter.
    resetTimerFlag2 =! resetTimerFlag2;
  }
  
  // comp. 1
  if ((Thermister1() <= SetPoint) || anyAlarm || anyAlarm1)         //if we reached to the set point turn off the comperssor or there are any alarms
  {
    Motor1_off();
    PreMillis1 = millis(); // reset the time counter.
  }
  else if ((millis() - PreMillis1) >= Com_1_OperationDelay)   // check if the OperationDelay time is out.
  {
    if (Thermister1() >= (SetPoint + SetPointDiff)) //if the temperature of the room is higher then the setpoint + diff turn on the comperasor so the room gets colder
    {
      Motor1_on(); //the motor will not work until there is not alarms.
    }
    PreMillis1 = millis(); // reset the time counter.
  }
  
  if (Thermister1() <= (SetPoint + TempDefBetCom1andCom2) || anyAlarm || anyAlarm2)       //if we reached to the set point turn off the comperssor or there are any alarms
  {
    Motor2_off();
    PreMillis2 = millis(); // reset the time counter.
  }
  else if ((millis() - PreMillis2) >= Com_2_OperationDelay)   // check if the OperationDelay time is out.
  {
    // comp. 2
    if (Thermister1() >= (SetPoint + TempDefBetCom1andCom2 + SetPointDiff)) //if the temperature of the room is higher then the setpoint + diff turn on the comperasor so the room gets colder
    {
      Motor2_on();  //the motor will not work until there is not alarms.
    }
    PreMillis2 = millis(); // reset the time counter.
  }
}
#endif
