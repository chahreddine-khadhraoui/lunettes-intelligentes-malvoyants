// Définition des broches
const int trigPin = 9;       // Broche TRIG du capteur ultrason
const int echoPin = 10;      // Broche ECHO du capteur ultrason
const int buzzer = 6;        // Broche du buzzer

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(buzzer, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // Mesurer la distance avec le capteur ultrason
    long duration;
    int distance;

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;  // Convertir en cm

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Vérifier si un obstacle est proche
    if (distance > 0 && distance <= 50) {  // Ajuster la distance seuil selon le besoin
        tone(buzzer, 1000);  // Activer le buzzer à 1000 Hz
    } else {
        noTone(buzzer);  // Désactiver le buzzer si aucun obstacle
    }

    delay(200);
}
