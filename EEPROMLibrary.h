#ifndef EEPROMLibrary_H
#define EEPROMLibrary_H

//addresses for EEPROM
#define float_SetPoint_ADDRESS                            0
#define float_SetPointDiff_ADDRESS                        (float_SetPoint_ADDRESS                     + sizeof(float))
#define signed_char_sensorOffset1_ADDRESS                 (float_SetPointDiff_ADDRESS                 + sizeof(float))
#define signed_char_sensorOffset2_ADDRESS                 (signed_char_sensorOffset1_ADDRESS          + sizeof(signed char))

#define unsigned_long_Com_1_OperationDelay_ADDRESS        (signed_char_sensorOffset2_ADDRESS          + sizeof(signed char))
#define unsigned_long_Com_2_OperationDelay_ADDRESS        (unsigned_long_Com_1_OperationDelay_ADDRESS + sizeof(unsigned long))


/*
#define bool_D1_FlowSW_Alarm_ADDRESS                      (signed_char_sensorOffset2_ADDRESS          + sizeof(signed char))
#define bool_D2_PhaseSq_Alarm_ADDRESS                     (bool_D1_FlowSW_Alarm_ADDRESS               + sizeof(bool))
#define bool_D3_HighPressure1_Alarm_ADDRESS               (bool_D2_PhaseSq_Alarm_ADDRESS              + sizeof(bool))
#define bool_D4_LowPressure1_Alarm_ADDRESS                (bool_D3_HighPressure1_Alarm_ADDRESS        + sizeof(bool))
#define bool_D5_OverLoadComperssor1_Alarm_ADDRESS         (bool_D4_LowPressure1_Alarm_ADDRESS         + sizeof(bool))
#define bool_D6_OverLoadCFM1_Alarm_ADDRESS                (bool_D5_OverLoadComperssor1_Alarm_ADDRESS  + sizeof(bool))
#define bool_D7_MotorProtector1_Alarm_ADDRESS             (bool_D6_OverLoadCFM1_Alarm_ADDRESS         + sizeof(bool))
#define bool_D8_OilPressure1_Alarm_ADDRESS                (bool_D7_MotorProtector1_Alarm_ADDRESS      + sizeof(bool))
#define bool_D9_HighPressure2_Alarm_ADDRESS               (bool_D8_OilPressure1_Alarm_ADDRESS         + sizeof(bool))
#define bool_D10_LowPressure2_Alarm_ADDRESS               (bool_D9_HighPressure2_Alarm_ADDRESS        + sizeof(bool))
#define bool_D11_OverLoadComperssor2_Alarm_ADDRESS        (bool_D10_LowPressure2_Alarm_ADDRESS        + sizeof(bool))
#define bool_D12_OverLoadCFM2_Alarm_ADDRESS               (bool_D11_OverLoadComperssor2_Alarm_ADDRESS + sizeof(bool))
#define bool_D13_MotorProtector2_Alarm_ADDRESS            (bool_D12_OverLoadCFM2_Alarm_ADDRESS        + sizeof(bool))
#define bool_D14_OilPressure2_Alarm_ADDRESS               (bool_D13_MotorProtector2_Alarm_ADDRESS     + sizeof(bool))

#define bool_temperature_difference_Alarm_ADDRESS         (bool_D14_OilPressure2_Alarm_ADDRESS        + sizeof(bool))

#define String_Temp_Alarm_reason1_ADDRESS                 (bool_temperature_difference_Alarm_ADDRESS  + sizeof(bool))
#define String_Temp_Alarm_reason2_ADDRESS                 (String_Temp_Alarm_reason1_ADDRESS          + 21)


// Function to write a string to EEPROM
void writeStringToEEPROM(int address, const String& data)
{
    for (size_t i = 0; i < data.length(); i++)
    {
        EEPROM.write(address + i, data[i]);
    }
    // Null-terminate the string
    EEPROM.write(address + data.length(), '\0');
}

// Function to read a string from EEPROM
String readStringFromEEPROM(int address)
{
    String result;
    char character = EEPROM.read(address);
    while (character != '\0')
    {
        result += character;
        address++;
        character = EEPROM.read(address);
    }
    return result;
}
*/

#endif
