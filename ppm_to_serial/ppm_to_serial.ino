#include <PulsePosition.h>            //include PPM library

PulsePositionInput rcInput;           //create PPM input object

void setup() {
  rcInput.begin(10)                   //start PPM listener on pin 10 (possible pins: 5, 6, 9, 10, 20, 21, 22, 23)
  

}

void loop() {
  int cnt = rcInput.available();      //how many values are availbale?
  if(cnt > 0) {                       //are values available?
    for(int i = 1; i <= cnt; i++){    //cycle trough all input channels
      float val = rcInput.read(i);    //set val to the value of the current input channel
      Serial.print(val);              //Srite the value to the Serial Terminal
      Serial.print("\t");             //add a tab for even spacing
    }
    Serial.println();                 //write a new line when all values are read.
  }
}
