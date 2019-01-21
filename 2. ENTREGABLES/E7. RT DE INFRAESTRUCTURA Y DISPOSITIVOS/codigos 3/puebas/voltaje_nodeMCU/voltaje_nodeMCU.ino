
void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(A0);
  float vol = val*3.3/1024.0;
  Serial.print("Voltaje: ");
  Serial.println(vol)
  delay(200);
}
