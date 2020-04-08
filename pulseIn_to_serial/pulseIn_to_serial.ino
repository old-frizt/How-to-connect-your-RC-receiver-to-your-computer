void setup() {
  // put your setup code here, to run once:
  pinMode(10, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = pulseIn(10, HIGH);
  Serial.println(val);
}
