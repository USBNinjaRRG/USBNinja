#include "Arduino.h"
#include "NinjaSoftSerial.h"
#include "BLESettings.h"
void SetBLE(String BLEName,String Password) {
	
	SoftSerial mySerial(2,1);
	mySerial.begin(9600);
	delay(100);
	digitalWrite(5, LOW);
	delay(500);
	mySerial.print("<NAME"+BLEName+">");
	delay(2000);
	mySerial.print("<SECRET="+Password+">");
	delay(1000);
	digitalWrite(5, HIGH);
}