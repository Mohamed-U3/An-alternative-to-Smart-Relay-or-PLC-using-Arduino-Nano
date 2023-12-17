#ifndef SCREENSFOUNCTIONS_H
#define SCREENSFOUNCTIONS_H

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

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

int StepperSteps = 10;

//Screen Nimbers
unsigned int ScreenNumber = 0;

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
  lcd.print(F("Date: 16.05.2018    "));

  previousMillis = millis();

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
  lcd.print(F("--> Time            "));
  lcd.setCursor(0, 2);
  lcd.print(F("    Stepper         "));
  lcd.setCursor(0, 3);
  lcd.print(F("    Item 2          "));

  //For Debug
  Serial.print(F("InternalScreen0 -> "));
  Serial.println(ScreenNumber);
}

void InternalScreen1()
{
  isMainMenu = false;
  ScreenNumber = 11;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("--------Menu--------"));
  lcd.setCursor(0, 1);
  lcd.print(F("    Time            "));
  lcd.setCursor(0, 2);
  lcd.print(F("--> Stepper         "));
  lcd.setCursor(0, 3);
  lcd.print(F("    Item 2          "));

  //For Debug
  Serial.print(F("InternalScreen1 -> "));
  Serial.println(ScreenNumber);
}

void InternalScreen2()
{
  isMainMenu = false;
  ScreenNumber = 12;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("--------Menu--------"));
  lcd.setCursor(0, 1);
  lcd.print(F("    Time            "));
  lcd.setCursor(0, 2);
  lcd.print(F("    Stepper         "));
  lcd.setCursor(0, 3);
  lcd.print(F("--> Item 2          "));

  //For Debug
  Serial.print(F("InternalScreen2 -> "));
  Serial.println(ScreenNumber);
}
void InternalScreen3()
{
  isMainMenu = false;
  ScreenNumber = 13;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("--------Menu--------"));
  lcd.setCursor(0, 1);
  lcd.print(F("    Stepper         "));
  lcd.setCursor(0, 2);
  lcd.print(F("    Item 2          "));
  lcd.setCursor(0, 3);
  lcd.print(F("--> Item 3          "));

  //For Debug
  Serial.print(F("InternalScreen3 -> "));
  Serial.println(ScreenNumber);
}
void InternalScreen4()
{
  isMainMenu = false;
  ScreenNumber = 14;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("--------Menu--------"));
  lcd.setCursor(0, 1);
  lcd.print(F("    Item 2          "));
  lcd.setCursor(0, 2);
  lcd.print(F("    Item 3          "));
  lcd.setCursor(0, 3);
  lcd.print(F("--> Item 4          "));

  //For Debug
  Serial.print(F("InternalScreen4 -> "));
  Serial.println(ScreenNumber);
}
void InternalScreen5()
{
  isMainMenu = false;
  ScreenNumber = 15;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("--------Menu--------"));
  lcd.setCursor(0, 1);
  lcd.print(F("    Item 3          "));
  lcd.setCursor(0, 2);
  lcd.print(F("    Item 4          "));
  lcd.setCursor(0, 3);
  lcd.print(F("--> Exit            "));

  //For Debug
  Serial.print(F("InternalScreen5 -> "));
  Serial.println(ScreenNumber);
}
//Internal Menu end--------------------------


/*************************----------SUB Menu ---------SUB Menu -------------**************************/
//SUB Menu Statics ----------------------------------
void SubScreen0()
{
  isMainMenu = false;
  ScreenNumber = 100;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("--------Time--------"));
  
  //For Debug
  Serial.print(F("SubScreen0 -> "));
  Serial.println(ScreenNumber);
}

void SubScreen1()
{
  isMainMenu = false;
  ScreenNumber = 101;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("--------Stepper-----"));
  lcd.setCursor(4, 2);
  lcd.print(F("                    "));
  lcd.setCursor(4, 2);
  lcd.print(StepperSteps);
  //For Debug
  Serial.print(F("SubScreen1 -> "));
  Serial.println(ScreenNumber);
}

void SubScreen2()
{
  isMainMenu = false;
  ScreenNumber = 101;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("--------Motor1-----"));
  lcd.setCursor(4, 2);
  lcd.print(F("                    "));
  lcd.setCursor(4, 2);
  lcd.print(StepperSteps);
  //For Debug
  Serial.print(F("SubScreen2 -> "));
  Serial.println(ScreenNumber);
}

void SubScreen3()
{
  isMainMenu = false;
  ScreenNumber = 101;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("--------Motor2-----"));
  lcd.setCursor(4, 2);
  lcd.print(F("                    "));
  lcd.setCursor(4, 2);
  lcd.print(StepperSteps);
  //For Debug
  Serial.print(F("SubScreen3 -> "));
  Serial.println(ScreenNumber);
}
//SUB Menu end-------------------------------

//SUB Menu Dynamics ----------------------------------
void SubScreen0_dyn()
{
  lcd.setCursor(0, 2);
  lcd.print(millis() / 1000);
}

void SubScreen1_dyn()
{
  
}

void SubScreen2_dyn()
{
  
}

void SubScreen3_dyn()
{
  
}

#endif
