#include <Servo.h>
//Déclaration des Pins de sortie
byte servoPin2 = 2;
byte servoPin3 = 3;
byte servoPin4 = 4;
byte servoPin5 = 5;

byte servoPin6 = 6;
byte servoPin7 = 7;
byte servoPin8 = 8;
byte servoPin9 = 9;
//Création des moteurs
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;


void setup() {
  //Attribution des pins à chaque moteur
	servo1.attach(servoPin2);
  servo2.attach(servoPin3);
  servo3.attach(servoPin4);
  servo4.attach(servoPin5);

  servo5.attach(servoPin6);
  servo6.attach(servoPin7);
  servo7.attach(servoPin8);
  servo8.attach(servoPin9);


	servo1.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo2.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo3.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo4.writeMicroseconds(1500); // send "stop" signal to ESC.

  servo5.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo6.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo7.writeMicroseconds(1500); // send "stop" signal to ESC.
  servo8.writeMicroseconds(1500); // send "stop" signal to ESC.


	delay(7000); // delay to allow the ESC to recognize the stopped signal
}

void loop() {
	int signal = 1550; // Set signal value, which should be between 1100 and 1900
	servo1.writeMicroseconds(signal); // Send signal to ESC.
  servo2.writeMicroseconds(signal); // Send signal to ESC.
  servo3.writeMicroseconds(signal); // Send signal to ESC.
  servo4.writeMicroseconds(signal); // Send signal to ESC.

  servo5.writeMicroseconds(signal); // Send signal to ESC.
  servo6.writeMicroseconds(signal); // Send signal to ESC.
  servo7.writeMicroseconds(signal); // Send signal to ESC.
  servo8.writeMicroseconds(signal); // Send signal to ESC.

}
