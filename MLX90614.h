/*
 * MLX90614.cpp - Arduino library for the MLX90614 temperature sensor.
 * Adapted by Fer Uría <fauria@gmail.com>
 * Based on "Is it hot? Arduino + MLX90614 IR Thermometer". See http://bildr.org/2011/02/mlx90614-arduino
 * Depends on I2Cmaster library: http://wiki.wiring.co/images/3/31/I2Cmaster.zip 
*/
 
#ifndef MLX90614_h
#define MLX90614_h

#include "Arduino.h"
#include <i2cmaster.h>

class MLX90614 {
	public:
		MLX90614();		
		float getC();
		float getF();
		float getK();
	private:
		void read();
		int _device;		
		double _tempData;
		double _tempFactor;		
};

#endif