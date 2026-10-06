const int MIC_PIN = 32;

const int N_MUESTRAS = 1000;

void setup() {
  Serial.begin(115200);

  analogReadResolution(12);  // 0 a 4095

  delay(1000);

  Serial.println("Inicio del ensayo de piso de ruido");
  Serial.println("Mantener el ambiente en silencio...");
  delay(3000);
}

void loop() {

  int minimo = 4095;
  int maximo = 0;

  long suma = 0;

  for (int i = 0; i < N_MUESTRAS; i++) {

    int muestra = analogRead(MIC_PIN);

    suma += muestra;

    if (muestra < minimo)
      minimo = muestra;

    if (muestra > maximo)
      maximo = muestra;

    Serial.println(muestra);

    delayMicroseconds(1000); // aprox. 1 kHz
  }

  float promedio = (float)suma / N_MUESTRAS;

  int fluctuacion = maximo - minimo;

  Serial.println();
  Serial.print("PROMEDIO: ");
  Serial.println(promedio);

  Serial.print("MINIMO: ");
  Serial.println(minimo);

  Serial.print("MAXIMO: ");
  Serial.println(maximo);

  Serial.print("FLUCTUACION: ");
  Serial.print(fluctuacion);
  Serial.println(" LSB");

  Serial.println("--------------------------------");

  delay(2000);
}