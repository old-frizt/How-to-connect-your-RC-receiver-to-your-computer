#include <PulsePosition.h>

PulsePositionInput myIn;

unsigned int ch[8];

void setup() {
  // put your setup code here, to run once:
  myIn.begin(10);
  Joystick.useManualSend(true);

}

void loop() {
  // put your main code here, to run repeatedly:
  int num = myIn.available();
  if (num == 8) {
    for(int i = 0; i < 8; i++){
     ch[i] = map(myIn.read(i+1), 1000, 2000, 0, 1024); 
     Serial.print(ch[i]);
     Serial.print(", ");
    }
    
    Serial.println(";");
    Joystick.X(ch[0]);
    Joystick.Y(ch[1]);
    Joystick.Z(ch[2]);
    Joystick.Zrotate(ch[3]);
    Joystick.sliderLeft(ch[4]);
    Joystick.sliderRight(ch[5]);

    ch[6] = (ch[6] > 512)? 1 : 0;
    ch[7] = (ch[7] > 512)? 1 : 0;

    Joystick.button(3, ch[6]);
    Joystick.button(4, ch[7]);
    
    Joystick.send_now();
  }
}
