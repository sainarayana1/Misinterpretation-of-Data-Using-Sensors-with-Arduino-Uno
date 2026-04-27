#define TEMP_PIN A0
#define LDR_PIN A1
#define NOISE_PIN A2
#define TRIG_PIN 9
#define ECHO_PIN 10

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.println("=== Dramatically Incorrect Sensor System ===");
  Serial.println("Actual Value vs Manipulated Interpretation");
  Serial.println();
}

void loop() {
  temperatureModule();
  ultrasonicModule();
  ldrModule();
  noisePanicModule();
  Serial.println("--------------------------------------");
  delay(3000);
}

void temperatureModule() {
  int rawTemp = analogRead(TEMP_PIN);
  float voltage = rawTemp * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100;

  Serial.println("[TEMPERATURE SENSOR]");
  Serial.print("Actual Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  Serial.print("Manipulated Output: ");
  if (temperatureC < 22)
    Serial.println("Emotionally Cold");
  else if (temperatureC < 28)
    Serial.println("Stable but Judging");
  else if (temperatureC < 32)
    Serial.println("Irritated for No Reason");
  else
    Serial.println("EMOTIONAL MELTDOWN");

  Serial.println();
}

void ultrasonicModule() {
  long duration;
  float distance;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  Serial.println("[ULTRASONIC SENSOR]");
  Serial.print("Actual Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.print("Manipulated Output: ");
  if (distance < 10)
    Serial.println("Wow. Personal space is optional now?");
  else if (distance < 30)
    Serial.println("Yes, this is uncomfortably close.");
  else if (distance < 50)
    Serial.println("Okay. You remembered me.");
  else
    Serial.println("Nice. Abandoned again.");

  Serial.println();
}

void ldrModule() {
  int lightValue = analogRead(LDR_PIN);

  Serial.println("[LDR SENSOR]");
  Serial.print("Actual Light Level: ");
  Serial.println(lightValue);

  Serial.print("Manipulated Output: ");
  if (lightValue > 700)
    Serial.println("Too bright. I refuse to work");
  else if (lightValue > 400)
    Serial.println("Acceptable lighting. Bare minimum.");
  else
    Serial.println("Finally dark. Now I perform");

  Serial.println();
}

void noisePanicModule() {
  int noiseLevel = analogRead(NOISE_PIN);

  Serial.println("[NOISE SENSOR - SIMULATED]");
  Serial.print("Actual Sound Level: ");
  Serial.println(noiseLevel);

  Serial.print("Manipulated Output: ");
  if (noiseLevel < 200)
    Serial.println("SUSPICIOUS SILENCE - DANGER");
  else if (noiseLevel < 600)
    Serial.println("UNAUTHORIZED ACTIVITY DETECTED");
  else
    Serial.println("EVACUATE IMMEDIATELY");

  Serial.println();
}
