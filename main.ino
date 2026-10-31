long duration;
int distance;
int safetyDistance;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(4, LOW);
  delay(100);

  digitalWrite(2, LOW);
  delayMicroseconds(2);
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);

  duration = pulseIn(3, HIGH);
  distance = duration * 0.034 / 2;

  safetyDistance = distance;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Vérifier si un obstacle est proche
  if (safetyDistance <= 50) { // Ajuster la distance seuil selon le besoin
    digitalWrite(5, HIGH);    // Activer le buzzer à 1000 Hz
  } 
  else {
    digitalWrite(5, LOW);     // Désactiver le buzzer si aucun obstacle
  }
}
