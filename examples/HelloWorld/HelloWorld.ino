// Include the library:
#include <MLX90614.h>

// Instantiate a sensor object:
MLX90614 sensor;

void setup() {
  // Setup the serial console:
  Serial.begin(9600);
  Serial.println("Testing MLX90614 library...");
}

void loop() {
  // Read the temperature in degrees Celsius:
  float celsius = sensor.getC();

  // The library has two other public methods:
  // float fahrenheit = sensor.getF();
  // float kelvin = sensor.getK();

  // Print it out and wait one second before reading again:
  Serial.println(celsius);
  delay(1000);
}
