#include <Arduino.h>
#include <BluetoothSerial.h>
#include <esp32_motor.h>
#include <ESP32Servo.h>

#define LF 25 // -> D3
#define LB 26 // -> D2
#define RF 27 // -> D1
#define RB 14 // -> D0
#define BLDC_pin 13

#define freq 5000
#define res 8
