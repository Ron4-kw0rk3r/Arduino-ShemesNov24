void setup() {
  pinMode(13, OUTPUT); // LED de comunicación serial
  Serial.begin(9600); // Inicializa comunicación serial
}

void loop() {
  // Verificar si se ha ingresado un mensaje desde el Monitor Serial
  if (Serial.available() > 0) {
    String inputMessage = "";
    while (Serial.available()) {
      inputMessage += (char)Serial.read();
      delay(10); // Pequeña pausa para asegurar que el mensaje se procese correctamente
    }
    Serial.print("Arduino Nano sending: ");
    Serial.println(inputMessage);

    // Enviar el mensaje al Arduino Uno
    Serial.println(inputMessage);
  }

  // Parpadeo del LED para indicar la actividad serial
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
}
