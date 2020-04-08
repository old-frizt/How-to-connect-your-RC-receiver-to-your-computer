void setup() {
  Serial.begin(9600);             //Starts the Serial communication at a baud rate of 9600 bps. Ignored by Teensy (https://www.pjrc.com/teensy/td_serial.html)
  pinMode(10, INPUT);             //initiate pin 10 as input
}

void loop() {
  int val = pulseIn(10, HIGH);    //wait for a HIGH pulse on pin 10 and set "val" to the pulse duration in Microseconds
  Serial.println(val);            //print the pulse duration to the Serial monitor
}
