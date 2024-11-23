void setup() {
  Serial.begin(9600); 
  pinMode(13, OUTPUT); // Configurar el pin 2 como salida para el LED
}

void loop() {
  if (Serial.available()) { 
    String message = Serial.readStringUntil('\n');
    
    if (message == "ON") {
      digitalWrite(13, HIGH); // Encender el LED conectado al pin 2
    } else if (message == "OFF") {
      digitalWrite(13, LOW); // Apagar el LED conectado al pin 2
    }
  }
}
