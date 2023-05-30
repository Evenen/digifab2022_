
const int pirPin = 2;  // PIR sensor output pin

const int ledPin = 13;  // LED pin

unsigned long motionTimestamp = 0;  // Timestamp to track motion detection time

void setup() {
  pinMode(pirPin, INPUT);   // Set PIR pin as INPUT
  pinMode(ledPin, OUTPUT);  // Set LED pin as OUTPUT
  Serial.begin(9600);       // for debugging
}

void loop() {
  int pirStatus = digitalRead(pirPin);  // Read the PIR sensor output

  if (pirStatus == HIGH) {
    motionTimestamp = millis();  // Update motion timestamp
    digitalWrite(ledPin, HIGH);  // Turn on the LED
    Serial.println("Motion detected");
  } else {
    if (millis() - motionTimestamp >= 10000) {
      digitalWrite(ledPin, LOW);  // Turn off the LED
      Serial.println("No motion the last 10 seconds");
    }
  }
}

