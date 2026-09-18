#ifdef BME280

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BME280.h>


#define BME280_ADDRESS 0x76

Adafruit_BME280 bme;

void setup()
{
    Serial.begin(115200);

    // Инициализация I2C
    Wire.begin();

    Serial.println();
    Serial.println("BME280 test");
    Serial.println("====================");

    // Инициализация BME280
    if (!bme.begin(BME280_ADDRESS))
    {
        Serial.println("ERROR: BME280 not found!");

        while (true)
        {
            delay(1000);
        }
    }

    Serial.println("BME280 found!");
    Serial.println();
}

void loop()
{
    float temperature = bme.readTemperature();
    float pressure = bme.readPressure() / 100.0F;
    float humidity = bme.readHumidity();

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Pressure:    ");
    Serial.print(pressure);
    Serial.println(" hPa");

    Serial.print("Humidity:    ");
    Serial.print(humidity);
    Serial.println(" %");

    Serial.println("--------------------");

    delay(2000);
}

#endif