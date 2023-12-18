#ifndef SCREENSFOUNCTIONS_H
#define SCREENSFOUNCTIONS_H

#include "TempSensor.h"
#include "GPIOInputChickFounction.h"

#define MainInActive_Num     0
#define MainScreen_Num       1
#define InternalScreen0_Num  10
#define InternalScreen1_Num  11
#define InternalScreen2_Num  12
#define InternalScreen3_Num  13
#define InternalScreen4_Num  14
#define InternalScreen5_Num  15
#define SubScreen0_Num       100
#define SubScreen1_Num       101
#define SubScreen2_Num       102
#define SubScreen3_Num       103
#define SubScreen4_Num       104

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

//Screen Nimbers
unsigned int ScreenNumber = 0;
unsigned int PageNumber   = 1;
unsigned int PageLimit    = 1;
char        isPagePrinted = 0;

//For interval, Turn Off Lcd backlight.
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
const long interval = 10000;

bool isMainMenu = false;
bool isBacklightOn = true;

void ScreenInit()
{
  currentMillis = millis();
  lcd.init();                      //initialize the lcd
  // Print a message to the LCD.
  lcd.begin(20, 4);
  lcd.setCursor(0, 0);
  lcd.print(F("------AVR TECH------"));
  lcd.setCursor(0, 1);
  lcd.print(F("Wait..."));
  lcd.setCursor(0, 2);
  lcd.print(F("loading Data..."));
  lcd.setCursor(0, 3);
  lcd.print(F("Tel : 01008580169"));
}

void ScreenActive()
{
  previousMillis = currentMillis;
  isBacklightOn = true;
  lcd.backlight();
}
void ScreenInactive()
{
  previousMillis = currentMillis;
  isBacklightOn = false;
  lcd.noBacklight();
}

//Main Menu Start--------------------------
void MainScreen()
{
  isMainMenu = true;
  ScreenNumber = MainScreen_Num;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("--------Menu--------"));
  lcd.setCursor(0, 2);
  lcd.print(F("Time: 11:11         "));
  lcd.setCursor(0, 3);
  lcd.print(F("Date: 17.12.2023    "));

  previousMillis = millis();
  isPagePrinted = 0;
  
  //For Debug
  Serial.print(F("MainScreen -> "));
  Serial.println(ScreenNumber);
}
//Main Menu End--------------------------



//Internal Menu Start--------------------------
void InternalScreen0()
{
  isMainMenu = false;
  ScreenNumber = InternalScreen0_Num;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("--------Menu--------"));
  lcd.setCursor(0, 1);
  lcd.print(F("--> Status          "));
  lcd.setCursor(0, 2);
  lcd.print(F("    Settings        "));
  lcd.setCursor(0, 3);
  lcd.print(F("    Digital Inputs  "));

  isPagePrinted = 0;
  PageNumber    = 1;

  //For Debug
  Serial.print(F("InternalScreen0 -> "));
  Serial.println(ScreenNumber);
}

void InternalScreen1()
{
  isMainMenu = false;
  ScreenNumber = InternalScreen1_Num;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("--------Menu--------"));
  lcd.setCursor(0, 1);
  lcd.print(F("    Status          "));
  lcd.setCursor(0, 2);
  lcd.print(F("--> Settings        "));
  lcd.setCursor(0, 3);
  lcd.print(F("    Digital Inputs  "));

  isPagePrinted = 0;
  PageNumber    = 1;
  
  //For Debug
  Serial.print(F("InternalScreen1 -> "));
  Serial.println(ScreenNumber);
}

void InternalScreen2()
{
  isMainMenu = false;
  ScreenNumber = InternalScreen2_Num;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("--------Menu--------"));
  lcd.setCursor(0, 1);
  lcd.print(F("    Status          "));
  lcd.setCursor(0, 2);
  lcd.print(F("    Settings        "));
  lcd.setCursor(0, 3);
  lcd.print(F("--> Digital Inputs  "));

  isPagePrinted = 0;
  PageNumber    = 1;
  
  //For Debug
  Serial.print(F("InternalScreen2 -> "));
  Serial.println(ScreenNumber);
}
void InternalScreen3()
{
  isMainMenu = false;
  ScreenNumber = InternalScreen3_Num;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("--------Menu--------"));
  lcd.setCursor(0, 1);
  lcd.print(F("    Settings        "));
  lcd.setCursor(0, 2);
  lcd.print(F("    Digital Inputs  "));
  lcd.setCursor(0, 3);
  lcd.print(F("--> Alarms          "));

  isPagePrinted = 0;
  PageNumber    = 1;
  
  //For Debug
  Serial.print(F("InternalScreen3 -> "));
  Serial.println(ScreenNumber);
}
void InternalScreen4()
{
  isMainMenu = false;
  ScreenNumber = InternalScreen4_Num;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("--------Menu--------"));
  lcd.setCursor(0, 1);
  lcd.print(F("    Digital Inputs  "));
  lcd.setCursor(0, 2);
  lcd.print(F("    Alarms          "));
  lcd.setCursor(0, 3);
  lcd.print(F("--> Alarms Reset    "));

  isPagePrinted = 0;
  PageNumber    = 1;
  
  //For Debug
  Serial.print(F("InternalScreen4 -> "));
  Serial.println(ScreenNumber);
}
void InternalScreen5()
{
  isMainMenu = false;
  ScreenNumber = InternalScreen5_Num;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("--------Menu--------"));
  lcd.setCursor(0, 1);
  lcd.print(F("    Alarms          "));
  lcd.setCursor(0, 2);
  lcd.print(F("    Alarms Reset    "));
  lcd.setCursor(0, 3);
  lcd.print(F("--> Exit            "));

  isPagePrinted = 0;
  PageNumber    = 1;
  
  //For Debug
  Serial.print(F("InternalScreen5 -> "));
  Serial.println(ScreenNumber);
}
//Internal Menu end--------------------------


/*************************----------SUB Menu ------------------------------SUB Menu -------------**************************/
//SUB Menu Statics ----------------------------------
void SubScreen0()
{
  isMainMenu = false;
  ScreenNumber = SubScreen0_Num;
  lcd.setCursor(0, 0);
  lcd.print(F("<<-----Status----->>"));            //-------- ====== Status ====== -------
  
  PageLimit = 2;
  if(PageNumber == 1)
  {
    if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      static int google = 1;
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);
    
      lcd.setCursor(11, 1);
      lcd.print(google++);      //there will be (SW. OFF - SW. ON - Alarm) in here.

      lcd.setCursor(15, 2);
      lcd.print(Thermister1());

      lcd.setCursor(15, 3);
      lcd.print(Thermister2());
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print(F("Unit Mode:"));
      
      lcd.setCursor(0, 2);
      lcd.print(F("In Water Temp:"));

      lcd.setCursor(0, 3);
      lcd.print(F("Out Water Temp:"));
      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 2)
  {
    if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);
    
    
      lcd.setCursor(15, 1);
      lcd.print(SetPoint);
    
    
      lcd.setCursor(11, 2);
      lcd.print(SetPointDiff);
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print(F("setPoint Temp:      "));

      lcd.setCursor(0, 2);
      lcd.print(F("Diff Temp:          "));

      lcd.setCursor(0, 3);
      lcd.print(F("                    "));
      
      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 3)
  {
        if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);
      
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("                    "));
      lcd.setCursor(0, 2);
      lcd.print(F("     Empty          "));
      lcd.setCursor(0, 3);
      lcd.print(F("                    "));
      
      isPagePrinted = PageNumber;
    }
  }
  else
  {
    PageNumber = 1;
  }
  
  //For Debug
  Serial.print(F("SubScreen0 -> "));
  Serial.println(ScreenNumber);
}
//===============================================================================================
void SubScreen1()
{
  isMainMenu = false;
  ScreenNumber = SubScreen1_Num;
  lcd.setCursor(0, 0);
  lcd.print(F("<<----Settings---->>"));            //-------- ====== Settings ====== -------

  PageLimit = 2;
  if(PageNumber == 1)
  {
        if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);

      lcd.setCursor(10, 1);
      lcd.print(SetPoint);
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("Setpoint:       C   "));
      lcd.setCursor(15, 1);
      lcd.print(char(223));
      lcd.setCursor(0, 2);
      lcd.print(F("                    "));
      lcd.setCursor(0, 3);
      lcd.print(F("                    "));
      
      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 2)
  {
        if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);

      lcd.setCursor(10, 2);
      lcd.print(SetPointDiff);
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("                    "));
      lcd.setCursor(0, 2);
      lcd.print(F("Diff:           C   "));
      lcd.setCursor(15, 2);
      lcd.print(char(223));
      lcd.setCursor(0, 3);
      lcd.print(F("                    "));
      
      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 3)
  {
        if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);
      
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("                    "));
      lcd.setCursor(0, 2);
      lcd.print(F("     Empty          "));
      lcd.setCursor(0, 3);
      lcd.print(F("                    "));
      
      isPagePrinted = PageNumber;
    }
  }
  else
  {
    PageNumber = 1;
  }
  
  //For Debug
  Serial.print(F("SubScreen1 -> "));
  Serial.println(ScreenNumber);
}
//===============================================================================================
void SubScreen2()
{
  isMainMenu = false;
  ScreenNumber = SubScreen2_Num;
  lcd.setCursor(0, 0);
  lcd.print(F("<<--Digital Inputs>>"));            //-------- ====== Digital Inputs ====== -------

  PageLimit = 3;
  if(PageNumber == 1)
  {
        if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(2, 0);
      lcd.print(PageNumber);

      lcd.setCursor(5, 1);
      lcd.print(D0_SW());
      
      lcd.setCursor(8, 2);
      lcd.print(D1_FlowSW());

      lcd.setCursor(9, 3);
      lcd.print(D2_PhaseSq());
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("SW1:                "));
      
      lcd.setCursor(0, 2);
      lcd.print(F("FolwSW:             "));
      
      lcd.setCursor(0, 3);
      lcd.print(F("PhaseSq:            "));
      
      
      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 2)
  {
        if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(2, 0);
      lcd.print(PageNumber);

      
      lcd.setCursor(5, 1);
      lcd.print(D3_HighPressure1());
      lcd.setCursor(15, 1);
      lcd.print(D9_HighPressure2());
      
      lcd.setCursor(5, 2);
      lcd.print(D4_LowPressure1());
      lcd.setCursor(15, 2);
      lcd.print(D10_LowPressure2());

      lcd.setCursor(6, 3);
      lcd.print(D5_OverLoadComperssor1());
      lcd.setCursor(16, 3);
      lcd.print(D11_OverLoadComperssor2());
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("HP1:      HP2:      "));
      
      lcd.setCursor(0, 2);
      lcd.print(F("LP1:      LP2:      "));
      
      lcd.setCursor(0, 3);
      lcd.print(F("OLC1:     OLC2:     "));
      
      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 3)
  {
        if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(2, 0);
      lcd.print(PageNumber);

      lcd.setCursor(7, 1);
      lcd.print(D6_OverLoadCFM1());
      lcd.setCursor(17, 1);
      lcd.print(D12_OverLoadCFM2());
      
      lcd.setCursor(5, 2);
      lcd.print(D7_MotorProtector1());
      lcd.setCursor(15, 2);
      lcd.print(D13_MotorProtector2());

      lcd.setCursor(6, 3);
      lcd.print(D8_OilPressure1());
      lcd.setCursor(16, 3);
      lcd.print(D14_OilPressure2());
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("OLCFM1:   OLCFM2:   "));
      
      lcd.setCursor(0, 2);
      lcd.print(F("MP1:      MP2:      "));
      
      lcd.setCursor(0, 3);
      lcd.print(F("OilP1:    OilP2:    "));
      
      isPagePrinted = PageNumber;
    }
  }
  else
  {
    PageNumber = 1;
  }
  
  //For Debug
  Serial.print(F("SubScreen2 -> "));
  Serial.println(ScreenNumber);
}
//===============================================================================================
void SubScreen3()
{
  isMainMenu = false;
  ScreenNumber = SubScreen3_Num;
  lcd.setCursor(0, 0);
  lcd.print(F("<<------Alarms---->>"));            //-------- ====== Alarms ====== -------

  PageLimit = 3;
  if(PageNumber == 1)
  {
        if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);
      
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("                    "));
      lcd.setCursor(0, 2);
      lcd.print(F("     Empty          "));
      lcd.setCursor(0, 3);
      lcd.print(F("                    "));
      
      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 2)
  {
        if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);
      
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("                    "));
      lcd.setCursor(0, 2);
      lcd.print(F("     Empty          "));
      lcd.setCursor(0, 3);
      lcd.print(F("                    "));
      
      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 3)
  {
        if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);
      
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("                    "));
      lcd.setCursor(0, 2);
      lcd.print(F("     Empty          "));
      lcd.setCursor(0, 3);
      lcd.print(F("                    "));
      
      isPagePrinted = PageNumber;
    }
  }
  else
  {
    PageNumber = 1;
  }
  
  //For Debug
  Serial.print(F("SubScreen3 -> "));
  Serial.println(ScreenNumber);
}
//===============================================================================================
void SubScreen4()
{
  isMainMenu = false;
  ScreenNumber = SubScreen4_Num;
  lcd.setCursor(0, 0);
  lcd.print(F("<<---Alarms Reset->>"));            //-------- ====== Alarms Reset ====== -------

  PageLimit = 3;
  if(PageNumber == 1)
  {
        if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);
      
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("                    "));
      lcd.setCursor(0, 2);
      lcd.print(F("     Empty          "));
      lcd.setCursor(0, 3);
      lcd.print(F("                    "));
      
      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 2)
  {
        if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);
      
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("                    "));
      lcd.setCursor(0, 2);
      lcd.print(F("     Empty          "));
      lcd.setCursor(0, 3);
      lcd.print(F("                    "));
      
      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 3)
  {
        if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);
      
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("                    "));
      lcd.setCursor(0, 2);
      lcd.print(F("     Empty          "));
      lcd.setCursor(0, 3);
      lcd.print(F("                    "));
      
      isPagePrinted = PageNumber;
    }
  }
  else
  {
    PageNumber = 1;
  }
  
  //For Debug
  Serial.print(F("SubScreen4 -> "));
  Serial.println(ScreenNumber);
}
//SUB Menu end-------------------------------
#endif