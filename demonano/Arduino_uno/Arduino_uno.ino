const int ledA = 2; // LED A
const int ledB = 4; // LED B
const int dip1 = 5; // Dip switch 1
const int dip2 = 6; // Dip switch 2
const int ledSerial = 13; // LED que indica recepción

void setup() {
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(dip1, INPUT_PULLUP);
  pinMode(dip2, INPUT_PULLUP);
  pinMode(ledSerial, OUTPUT);

  Serial.begin(9600); // Inicializa comunicación serial
}

void loop() {
  int dip1State = digitalRead(dip1);
  int dip2State = digitalRead(dip2);

  // Verificar si se ha recibido un mensaje
  if (Serial.available() > 0) {
    String receivedMessage = "";
    while (Serial.available()) {
      receivedMessage += (char)Serial.read();
      delay(10); // Pequeña pausa para asegurar que el mensaje se procese correctamente
    }
    Serial.print("Arduino Uno received: ");
    Serial.println(receivedMessage);

    // Si el mensaje recibido es "encender", enciende el LED de recepción
    if (receivedMessage == "encender") {
      digitalWrite(ledSerial, HIGH);
      delay(1000); // Enciende el LED por 1 segundo
      digitalWrite(ledSerial, LOW);
    }
  }

  // Control de LEDs basado en el estado de los dip switches
  if (dip1State == LOW || dip2State == LOW) {
    digitalWrite(ledB, HIGH);
    digitalWrite(ledA, LOW);
  } else {
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, LOW);
  }

  delay(500);
}
