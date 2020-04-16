/**
 * This sketch uses the ppm library to readthe signal of a RC receiver
 * and sends the values via USB to a computer as a gamecontroller
 * 
 * If it doesn't complie check you USB Type
 * 
 * IMPORTANT:
 * 
 * !!!Dont forget the logic level shifter!!!
 * RC receivers work with 5V but the teensy can only handle 3.3V
 * 
 * You have to set the right Board Type:
 * Tools -> Board -> Teensy 3.x
 * You have to set the right USB Type:
 *  Tools -> USB Type -> Serial+Keyboard+Mouse+Joystick
 *  
 *  https://github.com/old-frizt/How-to-connect-your-RC-receiver-to-your-computer
 */

#include <PulsePosition.h>        //include PPM lib for reading rc signal

#define CHNUM     8               //How many channles to receive

PulsePositionInput myIn;          //generate ppm input

unsigned int ch[CHNUM];           //place for saving rc values 

void setup() {
  myIn.begin(10);                 //start to litsen on pin ten for ppm signal (possible pins: 5, 6, 9, 10, 20, 21, 22, 23)
  Joystick.useManualSend(true);   //Only send Joysick values when all of them are ready

}

void loop() {
  int num = myIn.available();                             //How many RC channels are available at the moment
  if (num == CHNUM) {                                     //are all channels received
    for(int i = 0; i < CHNUM; i++){                       //cycle trough all received channels
      ch[i] = map(myIn.read(i+1), 1000, 2000, 0, 1023);   //convert input from 1000µs - 2000µs to 0 - 1023, the 10 bit vlaue needed for the joystick ouput
      Serial.print(ch[i]);                                //print value to Serial terminal to check for errors
      Serial.print("\t");                                 //print tab for alingment
    }
    
    Serial.println(";");                                  //print new line for new data
    Joystick.X(ch[0]);                                    //set Joystick X axis to value of channel 0
    Joystick.Y(ch[1]);                                    //set Joystick Y axis to value of channel 1
    Joystick.Z(ch[2]);                                    //set Joystick Z axis to value of channel 2
    Joystick.Zrotate(ch[3]);                              //set Joystick Z rotation axis to value of channel 3
    Joystick.sliderLeft(ch[4]);                           //set Joystick slider left to value of channel 4
    Joystick.sliderRight(ch[5]);                          //set Joystick slider right to value of channel 5

    ch[6] = (ch[6] > 512)? 1 : 0;                         //for the buttons we need a value of 1 (pressed) or 0 (unpressed)
    ch[7] = (ch[7] > 512)? 1 : 0;                         //another way of writing if(ch[7]>512){ch[7]=1}else{ch[7]=0}

    Joystick.button(3, ch[6]);                            //set button 3 on or off depending on channel 6
    Joystick.button(4, ch[7]);                            //set button 4 on or off depending on channel 7
    
    Joystick.send_now();                                  //now send the updated Joystick positions to the computer
  }
}
