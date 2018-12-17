#include <NinjaMouse.h>

/*https://www.usbninja.com/
This is the Code of Using Bluetooth remote control triggers Ninja to go
online, and act as a Mouse, It actually click and move, Please test carefully.

payloadA() {}
When the Bluetooth remote control button A is pressed. 
The program in payloadA() will be executed in a loop. 
Until the button A is released.

payloadB() {}
When the Bluetooth remote control button B is pressed. 
The program in payloadB() will be executed in a loop. 
Until the button B is released.


Mouse common functions:

NinjaMouse.rightClick();      //Right click but not release.
NinjaMouse.leftClick();       //Left click but not release.
NinjaMouse.middleClick();     //Middle click but not release.s LEFT .
NinjaMouse.setButtons(0);     //releas any click 
NinjaMouse.moveX(10);  NinjaMouse.moveX(10) is jumping 10 to the RIGHT .  NinjaMouse.moveX(-10) is jumping 10 to the LEFT.
NinjaMouse.moveY(10);  NinjaMouse.moveY(10) is jumping 10 to the DOWN .   NinjaMouse.moveY(-10) is jumping 10 to the UP .
NinjaMouse.scroll(5);  NinjaMouse.scroll(5) is UP roller. NinjaMouse.scroll(-5) is DOWN roller. 

NinjaMouse.trackX(SingleStepLength,Steps,Speed);     Mouse moves lEFT and RIGHT along the track.
NinjaMouse.trackY(SingleStepLength,Steps,Speed);     Mouse moves UP and DOWN along the track.
NinjaMouse.trackAll(StepLength_X,StepLength_Y,Steps_X,Steps_Y,Speed); Mouse moves slope along the track.

*/

void setup() { NinjaMouse.begin();}   //Initliaze NinjaMouse USB Interface 

void loop() {}

void payloadA()
{
  USBninjaOnline();              // USB DATA switch to Ninja
  /*
  You should call NinjaMouse.begin() after you call 
  NinjaMouse.end()
  Or, the NinjaMouse was disconnected and any action was not usable.
  */
  NinjaMouse.begin();   //Initliaze NinjaMouse USB Interface
  NinjaMouse.delay(500);
  NinjaMouse.leftClick();       //Mouse left click. It actually click things, Please test carefully.
  NinjaMouse.trackX(-5,100,8);  //Mouse moves to the left, the stepLength size of each jump is -5.Loop number is 100 steps.Speed is 5. 
                                 // moving about (5*100=500) pixels to the left takes about (8*200=1600) milliseconds.
  NinjaMouse.trackX(10,20,50);   // moving about (10*20=200) pixels to the left takes about (8*20=160) milliseconds.
  NinjaMouse.trackY(5,100,5);
  NinjaMouse.delay(500);
  NinjaMouse.trackAll(5,-8,50,50,3);////Mouse moves to the RIGHT  and UP , the stepLength size of each jump is 5 and 8.Loop number is 50 steps.Speed is 3.
  NinjaMouse.delay(500);
  /*If not using NinjaMouse.delay(), Please make sure to call
  NinjaMouse.update() function at least every 50 milliseconds*/

  NinjaMouse.setButtons(0);   //releas any click
  NinjaMouse.delay(100);
  /*
  While your cable connect to Some Phone, Only switch USB DATA was 
  not enough. The PC was still think that your phone was Ninja 
  (Your Phone Not send USB ReEmulate command), it may cause 
  non-stoppable input or NinjaMouse Device still Retain in your system.
  */
  NinjaMouse.end();     //Send Disconnect command to
                        //NinjaMouse USB Interface
  USBninjaOffline();    //USB DATA switch to Main Cable
  NinjaMouse.begin();   //Initliaze NinjaMouse USB Interface
}

void payloadB()
{
  USBninjaOnline();              // USB DATA switch to Ninja

  //A quick demo. Remote mouse track
  NinjaMouse.delay(100);
  NinjaMouse.trackX(8,300,1);
  NinjaMouse.trackAll(-6,6,150,150,1);
  NinjaMouse.trackAll(-6,-6,150,150,1);
}