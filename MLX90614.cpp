/*
 * MLX90614.cpp - Arduino library for the MLX90614 temperature sensor.
 * Adapted by Fer Uría <fauria@gmail.com>
 * Based on 'Is it hot? Arduino + MLX90614 IR Thermometer'. See http://bildr.org/2011/02/mlx90614-arduino/ http://bildr.org/2011/02/mlx90614-arduino/ 
 * Depends on I2C master library: http://wiki.wiring.co/images/3/31/I2Cmaster.zip 
*/

#include <i2cmaster.h>
#include "Arduino.h"
#include "MLX90614.h"

MLX90614::MLX90614() {	
  i2c_init();
  PORTC = (1 << PORTC4) | (1 << PORTC5); //enable pullups
  _device = 0x5A<<1; //Address must be bit shifted left, library does not automatically do it.
  _tempFactor = 0.02; // 0.02 degrees per LSB (measurement resolution of the MLX90614)
}

void MLX90614::read() {
  int data_low = 0;
  int data_high = 0;

  i2c_start_wait(_device+I2C_WRITE); //send start condition and write bit
  i2c_write(0x07); //send command for device to action
  i2c_rep_start(_device+I2C_READ); //send repeated start condition, device will ack
  data_low = i2c_readAck(); //Read 1 byte and then send ack
  data_high = i2c_readAck(); //Read 1 byte and then send ack
  i2c_readNak(); //Read error check byte and send Nack to tell device no more data to send
  i2c_stop(); //Release bus, end transaction

  // This masks off the error bit of the high byte, then moves it left 8 bits and adds the low byte.
  _tempData = ((double)(((data_high & 0x007F) << 8) + data_low) * _tempFactor)-0.01;
}

float MLX90614::getC() {	
  MLX90614::read();
  return _tempData - 273.15;
}

float MLX90614::getF() {
  MLX90614::read();
  return ((_tempData - 273.15)*1.8) + 32;
}

float MLX90614::getK() {
  MLX90614::read();
  return (float)_tempData;
}
