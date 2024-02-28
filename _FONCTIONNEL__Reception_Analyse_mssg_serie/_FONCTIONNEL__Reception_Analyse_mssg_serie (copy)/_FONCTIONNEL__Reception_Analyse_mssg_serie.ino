#define MAX_MOTORS 4 // Nombre maximum de moteurs
int motorSpeeds[MAX_MOTORS] = {1500, 1500, 1500, 1500}; // Tableau pour stocker les vitesses des moteurs
String ros_mssg = ""; // Chaîne de caractères pour stocker les messages ROS

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0) { // Vérifie si des données sont disponibles sur le port série
    String message = Serial.readStringUntil(','); // Lit la chaîne de caractères jusqu'à la virgule
    parseMessage(message); // Appelle la fonction pour analyser le message
  }
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
      ros_mssg = ""; // Réinitialise la chaîne de caractères avant d'ajouter de nouvelles vitesses
      for (int i = 0; i < 4; i++) {
        ros_mssg += "M" + String(i + 1) + " : " + String(motorSpeeds[i]) + " , "; // Ajoute les vitesses de tous les moteurs à la chaîne ROS
      }
      Serial.println(ros_mssg); // Envoie la chaîne ROS sur le port série
    }
  }
}
