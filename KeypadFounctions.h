#ifndef KeypadFounctions_H
#define KeypadFounctions_H

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
int Read_Buttons()             //reading if button is clicked or not
{
  ButtonsRead = analogRead(A3);
  delay(5);
  //Serial.print(F("button value: "));      //used for calibraation.
  //Serial.println(ButtonsRead);
  if (ButtonsRead > 950)  return btnNONE;   //the value should be 1023
  if (ButtonsRead < 100)  return btnRIGHT;  //the value should be 0
  if (ButtonsRead < 250)  return btnDOWN;   //the value should be 145
  if (ButtonsRead < 450)  return btnUP;     //the value should be 330
  if (ButtonsRead < 900)  return btnLEFT;   //the value should be 506
  if (ButtonsRead < 950)  return btnSELECT; //the value should be 933
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
    case  SubScreen1_Num:       InternalScreen1(); break;
    case  SubScreen2_Num:       InternalScreen2(); break;
    case  SubScreen3_Num:       InternalScreen3(); break;
    case  SubScreen4_Num:       ScreenAlarm();     break;
  }
  delay(ButtonDelay);
}
/***************------ Function ------ none -------**********/
void btnNONEFunction()            //IF none button is clicked
{
  if (isMainMenu)       //are we in the main menu now ? 
  {
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
      MainScreen();                   // go to the main menu
    }
  }
  switch (ScreenNumber) //its updates seconds when not pushing any buttons
  {
    case SubScreen0_Num: SubScreen0(); break;
    case SubScreen1_Num: SubScreen1(); break;
    case SubScreen2_Num: SubScreen2(); break;
    case SubScreen3_Num: SubScreen3(); break;
    case SubScreen4_Num: SubScreen4(); break;
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
