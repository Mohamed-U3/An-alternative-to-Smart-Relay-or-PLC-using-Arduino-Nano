#ifndef ISR_Founctions_H
#define ISR_Founctions_H

volatile uint16_t pinValues = 0; // Variable to store pin states for pins 0 to 13 and A0

void ISR_init()
{
  sei();
  // Enable pin change interrupt for pins 0 to 7 (PCINT16-23)
  PCMSK2 |= 0xFF; // Enable interrupts for pins D0-D7 (PCINT16-23)
  PCICR |= (1 << PCIE2); // Enable Pin Change Interrupt for PCINT16-23

  // Enable pin change interrupt for pins 8 to 13 (PCINT0-5)
  PCMSK0 |= 0x3F; // Enable interrupts for pins D8-D13 (PCINT0-5)
  PCICR |= (1 << PCIE0); // Enable Pin Change Interrupt for PCINT0-5

  // Enable pin change interrupt for A0 (PCINT14)
  PCMSK1 |= (1 << PCINT8); // Enable interrupt for A0 (PCINT14)
  PCICR |= (1 << PCIE1); // Enable Pin Change Interrupt for PCINT8-14

  // Set pins 0 to 14 as inputs
  for (int i = 0; i <= 14; i++)
  {
    pinMode(i, INPUT); // Set pins as input
  }
}

/************** interrupt for pins 0 to 7 ***************************/
// Interrupt service routine for pin change interrupt group PCINT16-23
ISR(PCINT2_vect)
{
  //Stop the motors
  Motor1_off();
  Motor2_off();
  
  if(digitalRead(0))  D0_SW_Alarm                   = HIGH;
  if(digitalRead(1))  D1_FlowSW_Alarm               = HIGH;
  if(digitalRead(2))  D2_PhaseSq_Alarm              = HIGH;
  if(digitalRead(3))  D3_HighPressure1_Alarm        = HIGH;
  if(digitalRead(4))  D4_LowPressure1_Alarm         = HIGH;
  if(digitalRead(5))  D5_OverLoadComperssor1_Alarm  = HIGH;
  if(digitalRead(6))  D6_OverLoadCFM1_Alarm         = HIGH;
  if(digitalRead(7))  D7_MotorProtector1_Alarm      = HIGH;

  /*
  pinValues = (PIND & 0xFF); // Read pins D0-D7
  // Perform actions based on pinValues for pins D0-D7
  // Example:
  if (pinValues & (1 << 3))
  {
    // D3 changed to HIGH
  }
  else
  {
    // D3 changed to LOW
  }
  */
  // Add conditions for other pins if needed
}

/************** interrupt for pins 8 to 13 *************************/
// Interrupt service routine for pin change interrupt group PCINT0-5
ISR(PCINT0_vect)
{
  //Stop the motors
  Motor1_off();
  Motor2_off();

  if(digitalRead(8))  D8_OilPressure1_Alarm         = HIGH;
  if(digitalRead(9))  D9_HighPressure2_Alarm        = HIGH;
  if(digitalRead(10)) D10_LowPressure2_Alarm        = HIGH;
  if(digitalRead(11)) D11_OverLoadComperssor2_Alarm = HIGH;
  if(digitalRead(12)) D12_OverLoadCFM2_Alarm        = HIGH;
  if(digitalRead(13)) D13_MotorProtector2_Alarm     = HIGH;
  /*
  pinValues = (PINB & 0x3F); // Read pins D8-D13
  // Perform actions based on pinValues for pins D8-D13
  // Example:
  if (pinValues & (1 << 11))
  {
    // D11 changed to HIGH
  }
  else
  {
    // D11 changed to LOW
  }
  */
  
  // Add conditions for other pins if needed
}

/**********************       interrupt for A0  *************************/
// Interrupt service routine for pin change interrupt group PCINT8-14 (A0)
ISR(PCINT1_vect)
{
  //Stop the motors
  Motor1_off();
  Motor2_off();

  pinValues = (PINC & 0x01); // Read pin A0 (PCINT14)
  // Perform actions based on pinValues for A0
  // Example:
  if (pinValues & 0x01)
  {
    // A0 changed to HIGH
    D14_OilPressure2_Alarm = HIGH;
  } else
  {
    // A0 changed to LOW
  }
  
  // Add conditions for other pins if needed
}

#endif
