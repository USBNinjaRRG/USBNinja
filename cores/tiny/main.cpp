#include <WProgram.h>
extern void payloadA(void);
extern void payloadB(void);
bool payloadA_runonce = false;
bool payloadB_runonce = false;
bool payloadA_run = false;
bool payloadB_run = false;
int main(void)
{
	init();
    pinMode(BUTTONBPIN, INPUT);
	pinMode(BUTTONAPIN, INPUT);
	pinMode(USBDIRECTPIN, OUTPUT);
	pinMode(BLECTLPIN, OUTPUT);
	digitalWrite(USBDIRECTPIN, HIGH);
	digitalWrite(BLECTLPIN, HIGH);
	delay(2000);
	setup();
	for(;;)
	{
		if(digitalRead(BUTTONAPIN)==LOW)
		{
			if(payloadA_runonce)
			{
				if(!payloadA_run)
				{
					payloadA();
					payloadA_run=true;
				}
			}
			else
			{
				payloadA();
				payloadA_run=false;
			}
		}
		if(digitalRead(BUTTONBPIN)==LOW)
		{
			if(payloadB_runonce)
			{
				if(!payloadB_run)
				{
					payloadB();
					payloadB_run=true;
				}
			}
			else
			{
				payloadB();
				payloadB_run=false;
			}
		}
		loop();
	}
	return 0;
}
int USBninjaOnline(void)
{
	digitalWrite(USBDIRECTPIN, LOW);
}
int USBninjaOffline(void)
{
	digitalWrite(USBDIRECTPIN, HIGH);  
}
void SetRunOnce(int payloadID,bool isRunOnce)
{
	if(payloadID==PAYLOADA)
	{
		payloadA_run=false;
		payloadA_runonce = isRunOnce;
	}
	else
	{
		payloadB_run=false;
		payloadB_runonce = isRunOnce;
	}
}