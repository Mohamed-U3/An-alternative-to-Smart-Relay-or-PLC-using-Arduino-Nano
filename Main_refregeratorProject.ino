#include <Wire.h>
#include <LiquidCrystal_I2C.h>
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
  Alarm_sum();

  Operation();
  
  HMI();
}
