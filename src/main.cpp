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

      case '0':
        ESC.writeMicroseconds(800);
        // Serial.println("0");
        break;
      case '1':
        ESC.writeMicroseconds(890);
        // Serial.println("1");
        break;
      case '2':
        ESC.writeMicroseconds(980);
        // Serial.println("2");
        break;
      case '3':
        ESC.writeMicroseconds(1070);
        // Serial.println("3");
        break;
      case '4':
        ESC.writeMicroseconds(1160);
        // Serial.println("4");
        break;
      case '5':
        ESC.writeMicroseconds(1250);
        // Serial.println("5");
        break;
      case '6':
        ESC.writeMicroseconds(1340);
        // Serial.println("6");
        break;
      case '7':
        ESC.writeMicroseconds(1430);
        // Serial.println("7");
        break;
      case '8':
        ESC.writeMicroseconds(1520);
        // Serial.println("8");
        break;
      case '9':
        ESC.writeMicroseconds(1610);
        // Serial.println("9");
        break;
      case 'q':
        ESC.writeMicroseconds(1700);
        // Serial.println("10");
        break;
    }
    if (cmd != 'S') Serial.println(cmd);
  }

}