#include <BLESettings.h>


/*https://www.usbninja.com/
This is the Code of Setup the BLE Module.
You can use SetBLE(String BLEName,String Password)
function to configure it.

parameter 1 BLEName:
The Device Name of the BLE Module,Maximum character length is 16 bytes.
parameter 2 Password:
The Connect Password of the BLE Module.Supports only 4-bit pure numbers.

It need 6 seconds to configure itself.

After 6 seconds, you can pull it out and use it as usual.. 

!!!DO NOT TURN OFF THE POWER DURING OPERATION !!!
  
*/
void setup()  
{

  SetBLE("Ninja","8888");//Set the name to Ninja, Set the password to 8888.
  //Example:  SetBLE("Bluetoothspeaker","1234");
 

}

void loop()
{
	//DO NOT WRITE HERE
}

void payloadA()
{
	//DO NOT WRITE HERE
}

void payloadB()
{
	//DO NOT WRITE HERE
}