#include "AnalogKeyPad.h"

/*************************************************
* send the pressed key to serial monitor *
**************************************************/
void printKey(int8_t keyCode);

void setup()
{
  Serial.begin(9600);
  Serial.println(F("Analog keypad v1.0"));
  Serial.println(F("press a key..."));
}

AnalogKeyPad keypad(A0);

void loop()
{   
	int8_t keyCode;

	// simple way to read the keys
	// keyUpEvent must be called regularly from your main loop
	// it takes care of reading the analog input and debouncing
	if ( (keyCode = keypad.keyUpEvent()) != AnalogKeyPad::NO_KEY)
	{  Serial.print("event key up: ");
	    printKey(keyCode);
	}     
	  
//    alternative way of reading keys if you need more fine grained control
//       if (keypad.run())                                      // must be called regularly from your main loop
//       { if (keypad.wasPressed()) 
//             Serial.print(F("pressed: "));
//         else if (keypad.wasReleased()) 
//             Serial.print(F("released: "));
// 
//         printKey(keypad.getCurrentKey());
//       }

}

void printKey(int8_t keyCode)
{   String keyName;

    switch (keyCode)
    { case 'U':
           keyName = "UP"; 
           break;	
      case 'D':
           keyName = "DOWN"; 
           break;
      case 'L':
           keyName = "LEFT"; 
           break;
      case 'R':
           keyName = "RIGHT"; 
           break;
      case 'S':
           keyName = "SELECT"; 
           break;
    }
    Serial.println(keyName);
}



