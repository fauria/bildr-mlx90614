# Bildr-MLX90614

Bildr-MLX90614 is a library used to read temperature from the Melexis MLX90614 temperature sensor. It is adapted from the work done by the [bildr](http://forum.bildr.org/index.php) community.

## Installation
Download the library, unzipit, and place the `Bildr-MLX90614` folder under your `Arduino/libraries` directory.

## Dependencies
The library depends on the I2C master library by Peter Fleury <pfleury@gmx.ch> ([download link](http://wiki.wiring.co/images/3/31/I2Cmaster.zip)). It is included from the `libraries/` folder.

## Usage
First, conenct the sensor to your Arduino. This diagram might be helpful:

![MLX90614 diagram](https://raw.githubusercontent.com/fauria/arduino-mlx90614/master/Fritzing/MLX90614_bb.png)

If you have a Grove Shield, you can build an [MLX90614 Grove Sensor](http://www.seeedstudio.com/recipe/1157-grove-mlx90614.html).

You can try a working example opening `File / Examples / Bildr-MLX90614 / HelloWorld` or pasting the following code on a new sketch:

```
// Include the library:
#include <Bildr-MLX90614.h>

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
```

## Todo
Read ambient temperature.

## See also
Adafruit has published a [detailed guide](https://learn.adafruit.com/using-melexis-mlx90614-non-contact-sensors?view=all) and an [excellent library](https://github.com/adafruit/Adafruit-MLX90614-Library) with tons of features.

## Credits
Work adapted form the code found on [Is it hot? Arduino + MLX90614 IR Thermometer](http://bildr.org/2011/02/mlx90614-arduino/) article by the bildr community.