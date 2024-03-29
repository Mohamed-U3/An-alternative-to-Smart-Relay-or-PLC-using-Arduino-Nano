#ifndef KeypadFounctions_H
#define KeypadFounctions_H
#include <Adafruit_PCF8574.h>

Adafruit_PCF8574 pcf;

#define PCF_BUTTON_UP       0  // on the GPIO expander!
#define PCF_BUTTON_LEFT     1  // on the GPIO expander!
#define PCF_BUTTON_DOWN     2  // on the GPIO expander!
#define PCF_BUTTON_RIGHT    3  // on the GPIO expander!
#define PCF_BUTTON_SELECT   4  // on the GPIO expander!

#include "ScreensFunctions.h"
#include "OutputFunctions.h"

//Buttons
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

// define some values used by the panel and buttons
#define ButtonDelay     200
int     ButtonCode   =  0;
int     ButtonsRead  =  0;

/************************************************/
/***************------ Functions ------**********/
/************************************************/
void keypad_init()
{
  if (!pcf.begin(0x20, &Wire))
  {
    Serial.println("Couldn't find PCF8574");
    while (1);
  }
  
  pcf.pinMode(PCF_BUTTON_UP     , INPUT_PULLUP);
  pcf.pinMode(PCF_BUTTON_LEFT   , INPUT_PULLUP);
  pcf.pinMode(PCF_BUTTON_DOWN   , INPUT_PULLUP);
  pcf.pinMode(PCF_BUTTON_RIGHT  , INPUT_PULLUP);
  pcf.pinMode(PCF_BUTTON_SELECT , INPUT_PULLUP);
}

int Read_Buttons()             //reading if button is clicked or not
{
//  ButtonsRead = analogRead(A3);
//  delay(5);
//  lcd.setCursor(0,1);
//  lcd.print(F("                    "));
//  lcd.setCursor(0,1);
//  lcd.print(F("button value: "));      //used for calibraation.
//  lcd.print(ButtonsRead);
//  Serial.println(ButtonsRead);        //used for calibraation.
//  if (ButtonsRead > 800)                          return btnNONE;   //the value should be 1023

  if (pcf.digitalRead(PCF_BUTTON_RIGHT)   == LOW)     return btnRIGHT;  //the value should be 0
  if (pcf.digitalRead(PCF_BUTTON_DOWN)    == LOW)     return btnDOWN;   //the value should be 145
  if (pcf.digitalRead(PCF_BUTTON_UP)      == LOW)     return btnUP;     //the value should be 330
  if (pcf.digitalRead(PCF_BUTTON_LEFT)    == LOW)     return btnLEFT;   //the value should be 506
  if (pcf.digitalRead(PCF_BUTTON_SELECT)  == LOW)     return btnSELECT; //the value should be 933
  return btnNONE;  // when all others fail, return this
}


/***************------ Function ------ RIGHT -------**********/
void btnRIGHTFunction()           //IF right button is clicked
{
  ScreenActive(); //Activating the screen Light and reseting the interval counter
  if(PageNumber >= 1 && PageNumber < PageLimit)
  {
    PageNumber++;
  }
  else if(PageNumber >= PageLimit)
  {
    PageNumber = 1;
  }
  delay(ButtonDelay);
}


/***************------ Function ------ LIFT -------**********/
void btnLIFTFunction()            //IF lift button is clicked
{
  ScreenActive(); //Activating the screen Light and reseting the interval counter
  if(PageNumber <= 1)
  {
    PageNumber = PageLimit;
  }
  else if(PageNumber <= PageLimit)
  {
    PageNumber--;
  }
  delay(ButtonDelay);
}


/***************------ Function ------ UP -------**********/
void btnUPFunction()              //IF up button is clicked
{
  ScreenActive(); //Activating the screen Light and reseting the interval counter
  // switch ScreenNumber
  switch (ScreenNumber)
  {
    case InternalScreen0_Num: InternalScreen5(); break;
    case InternalScreen1_Num: InternalScreen0(); break;
    case InternalScreen2_Num: InternalScreen1(); break;
    case InternalScreen3_Num: InternalScreen2(); break;
    case InternalScreen4_Num: InternalScreen3(); break;
    case InternalScreen5_Num: InternalScreen4(); break;
    //its updates StepperSteps values.
    case SubScreen0_Num:      SubScreen0();      break;
    case SubScreen1_Num:      IncreaseTemp(&PageNumber);    break;
    case SubScreen5_Num:      IncreaseNum(&PageNumber);     break;
    case SubScreen6_Num:      IncreaseOffset(&PageNumber);  break;
  }
  delay(ButtonDelay);
}
/***************------ Function ------ down -------**********/
void btnDOWNFunction()            //IF down button is clicked
{
  ScreenActive();   //Activating the screen Light and reseting the interval counter
  // switch ScreenNumber
  switch (ScreenNumber)
  {
    case InternalScreen0_Num:  InternalScreen1(); break;
    case InternalScreen1_Num:  InternalScreen2(); break;
    case InternalScreen2_Num:  InternalScreen3(); break;
    case InternalScreen3_Num:  InternalScreen4(); break;
    case InternalScreen4_Num:  InternalScreen5(); break;
    case InternalScreen5_Num:  InternalScreen0(); break;
    //its updates StepperSteps values.
    case SubScreen0_Num:       SubScreen0();      break;
    case SubScreen1_Num:       DecreaseTemp(&PageNumber);    break;
    case SubScreen5_Num:       DecreaseNum(&PageNumber);     break;
    case SubScreen6_Num:       DecreaseOffset(&PageNumber);  break;
  }
  delay(ButtonDelay);
}
/***************------ Function ------ select -------**********/
void btnSELECTFunction()          //IF select button is clicked
{
  ScreenActive();   //Activating the screen Light and reseting the interval counter
  // switch ScreenNumber
  switch (ScreenNumber)
  {
    case  MainInActive_Num:     MainScreen();      break;
    case  MainScreen_Num:       InternalScreen0(); break;
    case  InternalScreen0_Num:  SubScreen0();      break;
    case  InternalScreen1_Num:  SubScreen1();      break;
    case  InternalScreen2_Num:  SubScreen2();      break;
    case  InternalScreen3_Num:  SubScreen3();      break;
    case  InternalScreen4_Num:  SubScreen4();      break;
    case  InternalScreen5_Num:  MainScreen();      break;
    case  SubScreen0_Num:       InternalScreen0(); break;
    case  SubScreen1_Num:       if(PageNumber == 3) {isPagePrinted = 0;PageNumber    = 1; SubScreen5();} else InternalScreen1(); break;
    case  SubScreen2_Num:       InternalScreen2(); break;
    case  SubScreen3_Num:       InternalScreen3(); break;
    case  SubScreen4_Num:       ScreenAlarm();     break; //when reset alarm is clicked
    case  SubScreen5_Num:       if(CheckPass()) SubScreen6(); else InternalScreen1(); break;
    case  SubScreen6_Num:       InternalScreen1(); break;
  }
  delay(ButtonDelay);
}
/***************------ Function ------ none -------**********/
void btnNONEFunction()            //IF none button is clicked
{
  if (isMainMenu)       //are we in the main menu now ?
  {
    static long prevMillis = 0;
    if ((millis() - prevMillis >= 50))  // refresh screen
    {
      MainScreen(); //refresh main mainscreen
      prevMillis = millis();
      if(Pass1 != 0 && Pass2 != 0 && Pass3 != 0)        //reset entered password
      {
        Pass1 = 0;
        Pass2 = 0;
        Pass3 = 0;
      }
    }
    
    if (isBacklightOn && (currentMillis - previousMillis >= interval))  // Turn Off LCD Backlight
    {
      ScreenInactive();
      ScreenNumber = MainInActive_Num;
      Serial.println(F("Turn Off LCD Backlight"));
    }
  }
  // -No ?? then 
  else
  { //if the interval time is out, return to the main menu
    if (currentMillis - previousMillis >= interval)   // check if the interval time is out.
    {
      previousMillis = currentMillis; // reset the time counter.
      MainScreen();                   // go to the main screen.
    }
  }
  switch (ScreenNumber) //its updates seconds when not pushing any buttons
  {
    case SubScreen0_Num: SubScreen0(); break;
    case SubScreen1_Num: SubScreen1(); break;
    case SubScreen2_Num: SubScreen2(); break;
    case SubScreen3_Num: SubScreen3(); break;
    case SubScreen4_Num: SubScreen4(); break;
    case SubScreen5_Num: SubScreen5(); break;
    case SubScreen6_Num: SubScreen6(); break;
  }
}

void HMI()
{
  currentMillis = millis();     //initial time counter
  ButtonCode = Read_Buttons();  // read the buttons

  switch (ButtonCode)
  {
    case btnRIGHT:  btnRIGHTFunction();   break;
    case btnLEFT:   btnLIFTFunction();    break;  //Activating the screen Light and reseting the interval counter
    case btnUP:     btnUPFunction();      break;
    case btnDOWN:   btnDOWNFunction();    break;
    case btnSELECT: btnSELECTFunction();  break;
    case btnNONE:   btnNONEFunction();    break;
  }
}

#endif
