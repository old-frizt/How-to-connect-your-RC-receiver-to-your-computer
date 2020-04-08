#include <PulsePosition.h>  //include PPM library

PulsePositionInput rcInput; //create PPM input object

void setup() {
  rcInput.begin(10)         //start PPM listener on pin 10 (possible pins: 5, 6, 9, 10, 20, 21, 22, 23)
  

}

void loop() {
  int cnt = rcInput.available(); //how many values are availbale?
  if(cnt > 0) {              //are values available?
    for(int i = 1; i <= cnt; i++){
      float val = rcInput.read(i);
      Serial.print(val);
      Serial.print("\t");
    }
    Serial.println();
  }
}
