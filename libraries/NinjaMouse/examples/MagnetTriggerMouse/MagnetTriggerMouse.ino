#include <NinjaMouse.h>


/*http://www.usbninja.com/
This is the Code of Using maget triggers Ninja to go online, and act as a Mouse.

/*  Here is an quick version. 
 *  Ninja keeps online.
 *  Once the magnet is near, it triggers immediately.
 
 void loop() 
{
    if (digitalRead(0) == LOW)   
  {
  pinMode(USBDIRECTPIN,OUTPUT); 
  USBninjaOnline();              // USB DATA switch to Ninja
  //A quick demo. Remote mouse track
  NinjaMouse.delay(100);
  NinjaMouse.trackX(8,300,1);
  NinjaMouse.trackAll(-6,6,150,150,1);
  NinjaMouse.trackAll(-6,-6,150,150,1);
  pinMode(USBDIRECTPIN,INPUT);   
  }
  
}
*/

 
void setup() 
{
//  NinjaMouse.begin();                  //Initliaze NinjaMouse USB Interface
  pinMode(USBDIRECTPIN,INPUT);
} 
void loop() 
{
  if (digitalRead(USBDIRECTPIN) == LOW)          //If a magnet is near, Pin 0 will turn to low.
  {
  pinMode(USBDIRECTPIN,OUTPUT);
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
  NinjaMouse.trackX(10,20,50); // moving about (10*20=200) pixels to the left takes about (8*20=160) milliseconds.
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
  pinMode(USBDIRECTPIN,INPUT);
  }
  
}

void payloadA(){}
void payloadB(){}
