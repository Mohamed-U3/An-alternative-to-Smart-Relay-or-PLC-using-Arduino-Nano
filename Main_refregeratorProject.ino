#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#include "KeypadFounctions.h"
#include "OutputFunctions.h"
#include "ScreensFunctions.h"
#include "TempSensor.h"
#include "GPIOInputChickFounction.h"
#include "ISR_Founctions.h"

void setup()
{
  //Serial.begin(9600);
  ISR_init();
  Motors_init();
  ScreenInit();
  Thermister_init();
  //GPIO_init();
  
  delay(1000);
  MainScreen();
}

void loop()
{
  //EEPROM.get(eeAddress, f);
  //EEPROM.update(address, val);
  Alarm_sum();

  Operation();
  
  HMI();
}
