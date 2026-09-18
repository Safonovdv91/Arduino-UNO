#ifdef I2C_SCANNER

#include <Arduino.h>
#include <Wire.h>

void setup()
{
    Serial.begin(115200);
    Wire.begin();

    Serial.println();
    Serial.println("I2C Scanner");
    Serial.println("============");
}

void loop()
{
    byte error;
    byte address;
    int devicesFound = 0;

    Serial.println();
    Serial.println("Scanning I2C bus...");

    for (address = 1; address < 127; address++)
    {
        Wire.beginTransmission(address);
        error = Wire.endTransmission();

        if (error == 0)
        {
            Serial.print("Device found at address 0x");

            if (address < 16)
            {
                Serial.print("0");
            }

            Serial.println(address, HEX);

            devicesFound++;
        }
    }

    if (devicesFound == 0)
    {
        Serial.println("No I2C devices found.");
    }

    Serial.println("----------------------------");

    delay(3000);
}

#endif