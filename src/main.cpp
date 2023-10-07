#include <main.h>

BluetoothSerial BT;
esp32_motor leftMotor(LF, LB, 1, 2, freq, res);
esp32_motor rightMotor(RF, RB, 3, 4, freq, res);
Servo ESC;
char cmd;
void setup() {
  Serial.begin(9600);
  BT.begin("SGT Alpha");
  ESC.attach(BLDC_pin);
}

void loop() {
  if (BT.available()) {
    cmd = BT.read();
    switch(cmd){
      case 'F':  
        leftMotor.Run(250);
        rightMotor.Run(250);
        break;
      case 'B':  
        leftMotor.Run(-230);
        rightMotor.Run(-230);
        break;
      case 'R':  
        leftMotor.Run(230);
        rightMotor.Run(-230);
        break;
      case 'L':
        leftMotor.Run(-230);
        rightMotor.Run(230);
        break;
      case 'I':
        leftMotor.Run(230);
        rightMotor.Run(140);
        break;
      case 'G':
        leftMotor.Run(140);
        rightMotor.Run(230);
        break;
      case 'J':
        leftMotor.Run(-230);
        rightMotor.Run(-100);
        break;
      case 'H':
        leftMotor.Run(-100);
        rightMotor.Run(-230);
        break;
      case 'S':
        leftMotor.Run(0);
        rightMotor.Run(0);
        break;
    }
    Serial.println(cmd);
  }

}