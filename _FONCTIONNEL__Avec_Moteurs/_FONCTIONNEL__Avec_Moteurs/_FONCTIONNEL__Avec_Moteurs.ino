#include<Servo.h>
#define MAX_MOTORS 8 // Nombre maximum de moteurs
int motorSpeeds[MAX_MOTORS] = {1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500}; // Tableau pour stocker les vitesses des moteurs
String ros_mssg = ""; // Chaîne de caractères pour stocker les messages ROS

//Déclaration des Pins de sortie
byte servoPin2 =2;
byte servoPin3 =3;
byte servoPin4 =4;
byte servoPin5 =5;

byte servoPin6 =6;
byte servoPin7 =7;
byte servoPin8 =8;
byte servoPin9 =9;
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
  Serial.begin(115200);
  servo1.attach(servoPin2);
  servo2.attach(servoPin3);
  servo3.attach(servoPin4); 
  servo4.attach(servoPin5);
  servo5.attach(servoPin6);
  servo6.attach(servoPin7);
  servo7.attach(servoPin8);
  servo8.attach(servoPin9);
  
  servo1.writeMicroseconds(1500);
  servo2.writeMicroseconds(1500);
  servo3.writeMicroseconds(1500);
  servo4.writeMicroseconds(1500);
  servo5.writeMicroseconds(1500);
  servo6.writeMicroseconds(1500);
  servo7.writeMicroseconds(1500);
  servo8.writeMicroseconds(1500);

delay(7000); // delay to allow the ESC to recognize the stopped signal
}

void loop() {
  if (Serial.available() > 0) { // Vérifie si des données sont disponibles sur le port série
    String message = Serial.readStringUntil(','); // Lit la chaîne de caractères jusqu'à la virgule
    parseMessage(message); // Appelle la fonction pour analyser le message
  }
  //On récupères les valeurs des vitesses des moteurs dans le tableau motorSpeeds
  servo1.writeMicroseconds(motorSpeeds[0]);
  servo2.writeMicroseconds(motorSpeeds[1]);
  servo3.writeMicroseconds(motorSpeeds[2]);
  servo4.writeMicroseconds(motorSpeeds[3]);
  
  servo5.writeMicroseconds(motorSpeeds[4]);
  servo6.writeMicroseconds(motorSpeeds[5]);
  servo7.writeMicroseconds(motorSpeeds[6]);
  servo8.writeMicroseconds(motorSpeeds[7]); 
}

void parseMessage(String message) {
  int pos = message.indexOf('='); // Trouve la position du signe '=' dans la chaîne
  if (pos != -1) { // Vérifie si le signe '=' est trouvé
    String motor = message.substring(0, pos); // Extrait le nom du moteur
    String speedStr = message.substring(pos + 1); // Extrait la vitesse du moteur sous forme de chaîne
    int speed = speedStr.toInt(); // Convertit la vitesse en entier
    
    // Identifie le moteur et enregistre la vitesse dans le tableau approprié
    if (motor.equals("speed1 ")) {
      motorSpeeds[0] = speed;
    } else if (motor.equals("speed2 ")) {
      motorSpeeds[1] = speed;
    } else if (motor.equals("speed3 ")) {
      motorSpeeds[2] = speed;
    } else if (motor.equals("speed4 ")) {
      motorSpeeds[3] = speed;
    } else if (motor.equals("speed5 ")) {
      motorSpeeds[4] = speed;
    } else if (motor.equals("speed6 ")) {
      motorSpeeds[5] = speed;
    } else if (motor.equals("speed7 ")) {
      motorSpeeds[6] = speed;
    }else if (motor.equals("speed8 ")) {
      motorSpeeds[7] = speed;
      ros_mssg = ""; // Réinitialise la chaîne de caractères avant d'ajouter de nouvelles vitesses
      for (int i = 0; i < 8; i++) {
        ros_mssg += "M" + String(i + 1) + " : " + String(motorSpeeds[i]) + " , "; // Ajoute les vitesses de tous les moteurs à la chaîne ROS
      }
      Serial.println(ros_mssg); // Envoie la chaîne ROS sur le port série
    }
  }
}
