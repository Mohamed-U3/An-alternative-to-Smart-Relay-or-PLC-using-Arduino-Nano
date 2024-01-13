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
#define InternalScrPass_Num  16
#define SubScreen0_Num       100
#define SubScreen1_Num       101
#define SubScreen2_Num       102
#define SubScreen3_Num       103
#define SubScreen4_Num       104
#define SubScreen5_Num       105
#define SubScreen6_Num       106

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

//Screen Nimbers
unsigned int ScreenNumber = 0;
unsigned int PageNumber   = 1;
unsigned int PageLimit    = 1;
char        isPagePrinted = 0;

//Password Variables
signed char Pass1    = 0;
signed char Pass2    = 0;
signed char Pass3    = 0;
//Password
#define AcPass1          4
#define AcPass2          5
#define AcPass3          1

//For interval, Turn Off Lcd backlight.
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
const long interval = 30000;
bool resetTimerFlag1 = 0;
bool resetTimerFlag2 = 0;

bool isMainMenu = false;
bool isBacklightOn = true;

//Decliration of Variables in other file.
extern unsigned long Com_1_OperationDelay;
extern unsigned long Com_2_OperationDelay;
extern bool compressor1delay;
extern bool compressor2delay;

//Decliration of the Founction Because ScreenAlarm() is using it
void InternalScreen4();
void MainScreen();

//declaration of Functions
String GetMotor1_status();
String GetMotor2_status();

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

void ScreenAlarm()   //function that called when user resets alarms
{
  if(PageNumber == 1) InternalScreen4();  // Do nothing
  else if (PageNumber == 2)               // reset Alarms
  {
    if(D0_SW_Alarm || D1_FlowSW_Alarm || D2_PhaseSq_Alarm || temperature_difference_Alarm)
    {
      resetTimerFlag1                 = HIGH;
      resetTimerFlag2                 = HIGH;
    }
    if(D3_HighPressure1_Alarm || D4_LowPressure1_Alarm || D5_OverLoadComperssor1_Alarm || D6_OverLoadCFM1_Alarm || D7_MotorProtector1_Alarm || D8_OilPressure1_Alarm)
    {
      resetTimerFlag1               = HIGH;
    }
    if(D9_HighPressure2_Alarm || D10_LowPressure2_Alarm || D11_OverLoadComperssor2_Alarm || D12_OverLoadCFM2_Alarm || D13_MotorProtector2_Alarm || D14_OilPressure2_Alarm)
    {
      resetTimerFlag2               = HIGH;
    }

    temperature_difference_Alarm    = LOW;
    D0_SW_Alarm                     = LOW;
    D1_FlowSW_Alarm                 = LOW;
    D2_PhaseSq_Alarm                = LOW;
    
    D3_HighPressure1_Alarm          = LOW;
    D4_LowPressure1_Alarm           = LOW;
    D5_OverLoadComperssor1_Alarm    = LOW;
    D6_OverLoadCFM1_Alarm           = LOW;
    D7_MotorProtector1_Alarm        = LOW;
    D8_OilPressure1_Alarm           = LOW;
    
    D9_HighPressure2_Alarm          = LOW;
    D10_LowPressure2_Alarm          = LOW;
    D11_OverLoadComperssor2_Alarm   = LOW;
    D12_OverLoadCFM2_Alarm          = LOW;
    D13_MotorProtector2_Alarm       = LOW;
    D14_OilPressure2_Alarm          = LOW;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(F("<<---Alarms Reset->>"));
    lcd.setCursor(0, 1);
    lcd.print(F("                    "));
    lcd.setCursor(0, 2);
    lcd.print(F("All Alarms Have been"));
    lcd.setCursor(0, 3);
    lcd.print(F("       reset        "));

    delay(1000);

    MainScreen();
  }
  else PageNumber = 1;
}

//Main Menu Start--------------------------
void MainScreen()
{  
  if(ScreenNumber == MainScreen_Num) //dynamics words to be printed
  {
    lcd.setCursor(11, 0);
    if(digitalRead(0) == HIGH)
    lcd.print("ON ");      //there will be (SW. OFF - SW. ON - Alarm) in here.
    else
    lcd.print("OFF");      //there will be (SW. OFF - SW. ON - Alarm) in here.
    lcd.setCursor(14, 1);
    lcd.print(Thermister1());
    lcd.setCursor(14, 2);
    lcd.print(Thermister2());
    lcd.setCursor(14, 3);
    lcd.print(SetPoint);
  }
  else //Static Words to be printed once
  {
    lcd.setCursor(0, 0);
    lcd.print(F("Unit Mode:          "));      
    lcd.setCursor(0, 1);
    lcd.print(F("In Water Temp:     C"));
    lcd.setCursor(0, 2);
    lcd.print(F("Out Wter Temp:     C"));
    lcd.setCursor(0, 3);
    lcd.print(F("setPoint Temp:     C"));
  }  
  
  if(anyAlarm || anyAlarm1 || anyAlarm2) //Alram Case
  {
    static long prevMillis = 0;
    static bool togleVal = HIGH;
    
    if ((millis() - prevMillis >= 500))  // Toggle the value every 700ms
    {
      togleVal = !togleVal;
      prevMillis = millis();
    }
    
    if(togleVal) //the Alarm word toggles every 500ms as the last if statement sets.
    {
      lcd.setCursor(15, 0);
      lcd.print(F("Alarm"));
    }
    else
    {
      lcd.setCursor(15, 0);
      lcd.print(F("     "));
    }    
  }
  else
  {
    lcd.setCursor(15, 0);
    lcd.print(F("     "));
  }

  isMainMenu = true;
  ScreenNumber = MainScreen_Num;

//  previousMillis = millis();
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
  lcd.print(F("    Digital I/O     "));

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
  lcd.print(F("    Digital I/O     "));

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
  lcd.print(F("--> Digital I/O     "));

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
  lcd.print(F("    Digital I/O     "));
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
  lcd.print(F("    Digital I/O     "));
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
  
  PageLimit = 3;
  if(PageNumber == 1)
  {
    if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);

      
      lcd.setCursor(11, 1);
      if(digitalRead(0) == HIGH)
      lcd.print("ON ");      //there will be (SW. OFF - SW. ON - Alarm) in here.
      else
      lcd.print("OFF");      //there will be (SW. OFF - SW. ON - Alarm) in here.

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
      lcd.setCursor(2, 0);
      lcd.print(PageNumber);

      lcd.setCursor(12, 1);
      lcd.print(GetMotor1_status());
     
      lcd.setCursor(12, 2);
      lcd.print(GetMotor2_status());

//      lcd.setCursor(6, 3);
//      lcd.print();
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("Compresor1:         "));
      
      lcd.setCursor(0, 2);
      lcd.print(F("Compresor2:         "));
      
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

  PageLimit = 3;
  if(PageNumber == 1)
  {
    if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);

      lcd.setCursor(12, 1);
      lcd.print(SetPoint);

      lcd.setCursor(12, 2);
      lcd.print(SetPointDiff);
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("->Setpoint:       C "));
      lcd.setCursor(17, 1);
      lcd.print(char(223));
      lcd.setCursor(0, 2);
      lcd.print(F("  Diff:           C "));
      lcd.setCursor(17, 2);
      lcd.print(char(223));
      lcd.setCursor(0, 3);
      lcd.print(F("  Admin Settings    "));
      
      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 2)
  {
        if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);

      lcd.setCursor(12, 1);
      lcd.print(SetPoint);

      lcd.setCursor(12, 2);
      lcd.print(SetPointDiff);
    }
    else                           //for the statics in the page
    {
      lcd.clear();

      lcd.setCursor(0, 1);
      lcd.print(F("  Setpoint:       C "));
      lcd.setCursor(17, 1);
      lcd.print(char(223));
      lcd.setCursor(0, 2);
      lcd.print(F("->Diff:           C "));
      lcd.setCursor(17, 2);
      lcd.print(char(223));
      lcd.setCursor(0, 3);
      lcd.print(F("  Admin Settings    "));

      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 3)
  {
        if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);

      lcd.setCursor(12, 1);
      lcd.print(SetPoint);

      lcd.setCursor(12, 2);
      lcd.print(SetPointDiff);
    }
    else                           //for the statics in the page
    {
      lcd.clear();

      lcd.setCursor(0, 1);
      lcd.print(F("  Setpoint:       C "));
      lcd.setCursor(17, 1);
      lcd.print(char(223));
      lcd.setCursor(0, 2);
      lcd.print(F("  Diff:           C "));
      lcd.setCursor(17, 2);
      lcd.print(char(223));
      lcd.setCursor(0, 3);
      lcd.print(F("->Admin Settings    "));

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
  lcd.print(F("<<--Digital I/O   >>"));            //-------- ====== Digital Inputs ====== -------

  PageLimit = 6;
  if(PageNumber == 1)
  {
    if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(2, 0);
      lcd.print(PageNumber);

      lcd.setCursor(15, 1);
      lcd.print(D0_SW());
      
      lcd.setCursor(15, 2);
      lcd.print(D1_FlowSW());

      lcd.setCursor(15, 3);
      lcd.print(D2_PhaseSq());
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("ID1 SW on/off:      "));
      
      lcd.setCursor(0, 2);
      lcd.print(F("ID2 FlowSW:         "));
      
      lcd.setCursor(0, 3);
      lcd.print(F("ID3 Ph.Seq:         "));
      
      
      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 2)
  {
    if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(2, 0);
      lcd.print(PageNumber);

      
      lcd.setCursor(15, 1);
      lcd.print(D3_HighPressure1());
      
      lcd.setCursor(15, 2);
      lcd.print(D4_LowPressure1());
      
      lcd.setCursor(15, 3);
      lcd.print(D5_OverLoadComperssor1());
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("ID4 HP1:            "));
      
      lcd.setCursor(0, 2);
      lcd.print(F("ID5 LP1:            "));
      
      lcd.setCursor(0, 3);
      lcd.print(F("ID6 OLC1:           "));
      
      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 3)
  {
    if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(2, 0);
      lcd.print(PageNumber);

      lcd.setCursor(15, 1);
      lcd.print(D9_HighPressure2());
      
      lcd.setCursor(15, 2);
      lcd.print(D10_LowPressure2());

      lcd.setCursor(15, 3);
      lcd.print(D11_OverLoadComperssor2());
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("ID10 HP2:           "));
      
      lcd.setCursor(0, 2);
      lcd.print(F("ID11 LP2:           "));
      
      lcd.setCursor(0, 3);
      lcd.print(F("ID12 OLC2:          "));
      
      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 4)
  {
    if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(2, 0);
      lcd.print(PageNumber);

      lcd.setCursor(15, 1);
      lcd.print(D6_OverLoadCFM1());
      
      lcd.setCursor(15, 2);
      lcd.print(D7_MotorProtector1());

      lcd.setCursor(15, 3);
      lcd.print(D8_OilPressure1());
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("ID7 OLCFM1:         "));
      
      lcd.setCursor(0, 2);
      lcd.print(F("ID8 MP1:            "));
      
      lcd.setCursor(0, 3);
      lcd.print(F("ID9 Oil.P1:         "));
      
      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 5)
  {
    if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(2, 0);
      lcd.print(PageNumber);

      lcd.setCursor(15, 1);
      lcd.print(D12_OverLoadCFM2());
      
      lcd.setCursor(15, 2);
      lcd.print(D13_MotorProtector2());

      lcd.setCursor(15, 3);
      lcd.print(D14_OilPressure2());
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("ID13 OLCFM2:        "));
      
      lcd.setCursor(0, 2);
      lcd.print(F("ID14 MP2:           "));
      
      lcd.setCursor(0, 3);
      lcd.print(F("ID15 OilP2:         "));
      
      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 6)
  {
    if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(2, 0);
      lcd.print(PageNumber);

      lcd.setCursor(11, 1);
      lcd.print(GetMotor1_status());
      lcd.setCursor(15, 1);
      if(anyAlarm ||anyAlarm1) lcd.print("Alarm");
      else if(compressor1delay) lcd.print("Delay");
      else lcd.print("     ");
      
     
      lcd.setCursor(11, 2);
      lcd.print(GetMotor2_status());
      
      lcd.setCursor(15, 2);
      if(anyAlarm ||anyAlarm2) lcd.print("Alarm");
      else if(compressor2delay) lcd.print("Delay");
      else lcd.print("     ");
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("Compresor1:         "));
      
      lcd.setCursor(0, 2);
      lcd.print(F("Compresor2:         "));
      
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

  PageLimit = 4;
  if(PageNumber == 1)
  {
    if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);

      lcd.setCursor(9, 1);
      lcd.print(D0_SW_Alarm);
      
      lcd.setCursor(9, 2);
      lcd.print(D1_FlowSW_Alarm);

      lcd.setCursor(9, 3);
      lcd.print(D2_PhaseSq_Alarm);
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
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);

      
      lcd.setCursor(8, 1);
      lcd.print(D3_HighPressure1_Alarm);
      lcd.setCursor(18, 1);
      lcd.print(D9_HighPressure2_Alarm);
      
      lcd.setCursor(8, 2);
      lcd.print(D4_LowPressure1_Alarm);
      lcd.setCursor(18, 2);
      lcd.print(D10_LowPressure2_Alarm);

      lcd.setCursor(8, 3);
      lcd.print(D5_OverLoadComperssor1_Alarm);
      lcd.setCursor(18, 3);
      lcd.print(D11_OverLoadComperssor2_Alarm);
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
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);

      lcd.setCursor(8, 1);
      lcd.print(D6_OverLoadCFM1_Alarm);
      lcd.setCursor(18, 1);
      lcd.print(D12_OverLoadCFM2_Alarm);
      
      lcd.setCursor(8, 2);
      lcd.print(D7_MotorProtector1_Alarm);
      lcd.setCursor(18, 2);
      lcd.print(D13_MotorProtector2_Alarm);

      lcd.setCursor(8, 3);
      lcd.print(D8_OilPressure1_Alarm);
      lcd.setCursor(18, 3);
      lcd.print(D14_OilPressure2_Alarm);
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
  else if(PageNumber == 4)
  {
    if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);

      lcd.setCursor(12, 1);
      lcd.print(temperature_difference_Alarm);
      
      lcd.setCursor(0, 2);
      lcd.print(Temp_Alarm_reason1);

      lcd.setCursor(0, 3);
      lcd.print(Temp_Alarm_reason2);
      Serial.println(Temp_Alarm_reason1);
      Serial.println(Temp_Alarm_reason2);
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("temp. alarm:        "));
      
      lcd.setCursor(0, 2);
      lcd.print(F("                    "));
      
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

  PageLimit = 2;
  if(PageNumber == 1)
  {
    if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(3, 0);
      lcd.print(PageNumber);
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F(" Reset all Alarms ? "));
      lcd.setCursor(0, 2);
      lcd.print(F("                    "));
      lcd.setCursor(0, 3);
      lcd.print(F(">> No <<    Yes     "));
      
      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 2)
  {
    if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(3, 0);
      lcd.print(PageNumber);
      
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F(" Reset all Alarms ? "));
      lcd.setCursor(0, 2);
      lcd.print(F("                    "));
      lcd.setCursor(0, 3);
      lcd.print(F("   No    >> Yes <<  "));
      
      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 3)
  {
        if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(3, 0);
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
//===============================================================================================
void SubScreen5()
{
  isMainMenu = false;
  ScreenNumber = SubScreen5_Num;
  lcd.setCursor(0, 0);
  lcd.print(F("---Enter Password---"));            //-------- ====== Password ====== -------

  PageLimit = 3;
  if(PageNumber == 1)
  {
    if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(1, 0);
      lcd.print(PageNumber);

      lcd.setCursor(5, 2);
      lcd.print(Pass1);

      lcd.setCursor(10, 2);
      lcd.print(Pass2);

      lcd.setCursor(15, 2);
      lcd.print(Pass3);
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("     #              "));
      lcd.setCursor(0, 2);
      lcd.print(F("----   --   --   ---"));
      lcd.setCursor(0, 3);
      lcd.print(F("                    "));
      
      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 2)
  {
    if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(1, 0);
      lcd.print(PageNumber);

      lcd.setCursor(5, 2);
      lcd.print(Pass1);

      lcd.setCursor(10, 2);
      lcd.print(Pass2);

      lcd.setCursor(15, 2);
      lcd.print(Pass3);
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("          #         "));
      lcd.setCursor(0, 2);
      lcd.print(F("----   --   --   ---"));
      lcd.setCursor(0, 3);
      lcd.print(F("                    "));
      
      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 3)
  {
    if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(1, 0);
      lcd.print(PageNumber);

      lcd.setCursor(5, 2);
      lcd.print(Pass1);

      lcd.setCursor(10, 2);
      lcd.print(Pass2);

      lcd.setCursor(15, 2);
      lcd.print(Pass3);
    }
    else                           //for the statics in the page
    {
      lcd.clear();
      
      lcd.setCursor(0, 1);
      lcd.print(F("               #    "));
      lcd.setCursor(0, 2);
      lcd.print(F("----   --   --   ---"));
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
//===============================================================================================
void SubScreen6()
{
  isMainMenu = false;
  ScreenNumber = SubScreen6_Num;
  lcd.setCursor(0, 0);
  lcd.print(F("<<-admin settings->>"));            //-------- ====== Admin Settings ====== -------

  PageLimit = 4;
  if(PageNumber == 1)
  {
    if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);

      lcd.setCursor(17, 1);
      lcd.print(sensorOffset1);
      if (sensorOffset1 >= 0)
      {
        lcd.setCursor(18, 1);
        lcd.print("  ");
      }
      
      lcd.setCursor(17, 2);
      lcd.print(sensorOffset2);
      if (sensorOffset2 >= 0)
      {
        lcd.setCursor(18, 2);
        lcd.print("  ");
      }

      lcd.setCursor(15, 3);
      lcd.print(Com_1_OperationDelay);
    }
    else                           //for the statics in the page
    {
      lcd.clear();

      lcd.setCursor(0, 1);
      lcd.print(F("->SensorOffset1:    "));
      lcd.setCursor(0, 2);
      lcd.print(F("  SensorOffset2:    "));
      lcd.setCursor(0, 3);
      lcd.print(F("  Timer1Delay:     s"));

      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 2)
  {
    if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);

      lcd.setCursor(17, 1);
      lcd.print(sensorOffset1);
      if (sensorOffset1 >= 0)
      {
        lcd.setCursor(18, 1);
        lcd.print("  ");
      }
      
      lcd.setCursor(17, 2);
      lcd.print(sensorOffset2);
      if (sensorOffset2 >= 0)
      {
        lcd.setCursor(18, 2);
        lcd.print("  ");
      }
      
      lcd.setCursor(15, 3);
      lcd.print(Com_1_OperationDelay);
    }
    else                           //for the statics in the page
    {
      lcd.clear();

      lcd.setCursor(0, 1);
      lcd.print(F("  SensorOffset1:    "));
      lcd.setCursor(0, 2);
      lcd.print(F("->SensorOffset2:    "));
      lcd.setCursor(0, 3);
      lcd.print(F("  Timer1Delay:     s"));

      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 3)
  {
    if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);

      lcd.setCursor(17, 1);
      lcd.print(sensorOffset1);
      if (sensorOffset1 >= 0)
      {
        lcd.setCursor(18, 1);
        lcd.print("  ");
      }
      
      lcd.setCursor(17, 2);
      lcd.print(sensorOffset2);
      if (sensorOffset2 >= 0)
      {
        lcd.setCursor(18, 2);
        lcd.print("  ");
      }

      lcd.setCursor(15, 3);
      lcd.print(Com_1_OperationDelay);
    }
    else                           //for the statics in the page
    {
      lcd.clear();

      lcd.setCursor(0, 1);
      lcd.print(F("  SensorOffset1:    "));
      lcd.setCursor(0, 2);
      lcd.print(F("  SensorOffset2:    "));
      lcd.setCursor(0, 3);
      lcd.print(F("->Timer1Delay:     s"));

      isPagePrinted = PageNumber;
    }
  }
  else if(PageNumber == 4)
  {
    if(isPagePrinted == PageNumber) //For the Dynamics in the page
    {
      lcd.setCursor(4, 0);
      lcd.print(PageNumber);
      
      lcd.setCursor(17, 1);
      lcd.print(sensorOffset2);
      if (sensorOffset2 >= 0)
      {
        lcd.setCursor(18, 1);
        lcd.print("  ");
      }

      lcd.setCursor(15, 2);
      lcd.print(Com_1_OperationDelay);

      lcd.setCursor(15, 3);
      lcd.print(Com_2_OperationDelay);
      
    }
    else                           //for the statics in the page
    {
      lcd.clear();

      lcd.setCursor(0, 1);
      lcd.print(F("  SensorOffset2:    "));
      lcd.setCursor(0, 2);
      lcd.print(F("  Timer1Delay:     s"));
      lcd.setCursor(0, 3);
      lcd.print(F("->Timer2Delay:     s"));

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
//SUB Menu end-------------------------------

//  Password Functions
void IncreaseNum(unsigned int * page_num)
{
  if(*page_num == 1)      {Pass1++;  if(Pass1>9) Pass1=9;  }
  else if(*page_num == 2) {Pass2++;  if(Pass2>9) Pass2=9;  }
  else if(*page_num == 3) {Pass3++;  if(Pass3>9) Pass3=9;  }
}

void DecreaseNum(unsigned int * page_num)
{
  if(*page_num == 1)      {Pass1--;  if(Pass1<0) Pass1=0; }
  else if(*page_num == 2) {Pass2--;  if(Pass2<0) Pass2=0; }
  else if(*page_num == 3) {Pass3--;  if(Pass3<0) Pass3=0; }
}

bool CheckPass()
{
  isPagePrinted = 0;
  PageNumber    = 1;
  if(Pass1 == AcPass1 && Pass2 == AcPass2 && Pass3 == AcPass3) return true;
  else return false;
}
#endif
