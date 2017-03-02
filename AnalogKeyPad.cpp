/*
 * AnalogKeyPad - Interface with joystick type button on an analog pin
 *
 * Copyright (c) 2013 oryshed <oryshed@gmail.com>
 * 
 * 2014-09-10:  compatibility with Arduino IDE 1.5.x
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef AnalogKeyPad_h
#include "AnalogKeyPad.h"
#endif

PROGMEM const uint16_t AnalogKeyPad::keyReadings[] = { 0, 134, 330, 495, 734, 1023 };
//PROGMEM const uint16_t AnalogKeyPad::keyReadings[] = { 0, 144, 330, 509, 745, 1023 };
//PROGMEM const uint16_t AnalogKeyPad::keyReadings[] = { 0, 144, 330, 610, 776, 1023 };

PROGMEM const int8_t AnalogKeyPad::keyCodes[] = 
//{ AnalogKeyPad::DOWN, AnalogKeyPad::RIGHT, AnalogKeyPad::SELECT, AnalogKeyPad::UP, AnalogKeyPad::LEFT};
{ AnalogKeyPad::DOWN, AnalogKeyPad::LEFT, AnalogKeyPad::SELECT, AnalogKeyPad::UP, AnalogKeyPad::RIGHT};
//{ AnalogKeyPad::LEFT, AnalogKeyPad::SELECT, AnalogKeyPad::DOWN, AnalogKeyPad::RIGHT, AnalogKeyPad::UP };

/**********************************************************************************
Constructor takes the analog pin to which the keypad is connected.
**********************************************************************************/
AnalogKeyPad::AnalogKeyPad(int8_t analogPin) :
  pin(analogPin), _keyCode(NO_KEY)
{  pinMode(analogPin, INPUT);
}



/**********************************************************************************
Must be called regularly from the main loop to register key events.

Returns the key code of the released key or NO_KEY if no key was released
**********************************************************************************/
int8_t AnalogKeyPad::keyUpEvent()
{
    if (run() && wasReleased())
        return getCurrentKey();
    else
        return AnalogKeyPad::NO_KEY;
}


/**********************************************************************************
Must be called regularly from the main loop to register key events.

Returns the key code of the pressed key or NO_KEY if no key was released
**********************************************************************************/
int8_t AnalogKeyPad::keyDownEvent()
{
    if (run() && wasPressed())
        return getCurrentKey();
    else
        return AnalogKeyPad::NO_KEY;
}


/**********************************************************************************
Must be called regularly from the main loop to register key events.

Returns true if the key was pressed or released.
**********************************************************************************/
boolean AnalogKeyPad::run()
{   
    int16_t analogReading;
    int8_t reading;
    uint32_t now = millis();

    analogReading = analogRead(pin);
    reading = getKeyCode(analogReading);
    
#ifdef DEBUG_ANALOG_KEYPAD
    if (analogReading != _prevAnalogReading)
    {
        Serial.print("A"); Serial.print(char(pin - A0 + '0')); Serial.print('=');
        Serial.println(analogReading);
        _prevAnalogReading = analogReading;
    }
#endif    

    if ( (_keyCode != NO_KEY) && _keyFlags)  
    {   
        if (_keyFlags & FLAG_RELEASED)
            _keyCode = NO_KEY;
        _keyFlags = 0;
#ifdef DEBUG_ANALOG_KEYPAD
        Serial.println(F("key event cleared"));
#endif
    }        


    if (reading != _prevReading)
    {
        _prevReading= reading;
        _timestamp = now;
    }
    else if (now - _timestamp >= DEBOUNCE_INTERVAL)
    {
        if (_keyCode != reading)                // detect edge - key changed
        {
            if (reading != NO_KEY)
            {   _keyFlags = FLAG_PRESSED;
                _keyCode = reading;
#ifdef DEBUG_ANALOG_KEYPAD
                Serial.print(F("pressed ")); Serial.println(char(_keyCode));
#endif                                
            }                
            else 
            {    _keyFlags = FLAG_RELEASED;
#ifdef DEBUG_ANALOG_KEYPAD
                Serial.print(F("released ")); Serial.println(char(_keyCode));
#endif
            }                
            
        }  // end key changed            
    } // end debounce interval expired
	return true;
}
    

/**********************************************************************************
Returns the key corresponding to the last ADC value.

It must be called during the same update cycle that signaled the key
press/release event (i.e. when the update method returned true).
**********************************************************************************/
int8_t AnalogKeyPad::getCurrentKey()
{
    return _keyCode;
}

/**********************************************************************************
Returns true if a key was pressed during the last update cycle.

It must be called during the same update cycle that signaled the key
press/release event (i.e. when the update method returned true).
**********************************************************************************/
boolean AnalogKeyPad::wasPressed()
{
    return _keyFlags & FLAG_PRESSED;
}

/**********************************************************************************
Returns true if a key was released during the last update cycle.

It must be called during the same update cycle that signaled the key
press/release event (i.e. when the update method returned true).
**********************************************************************************/
boolean AnalogKeyPad::wasReleased()
{
    return _keyFlags & FLAG_RELEASED;
}


/**********************************************************************************
Mapping of ADC values to key codes.
**********************************************************************************/
int8_t AnalogKeyPad::getKeyCode(uint16_t reading)
{ uint16_t keyVal, boundary;

  for (int8_t i=0; i<NUM_KEYS; i++)
  { keyVal = pgm_read_word_near(&keyReadings[i]);
    boundary = keyVal + (pgm_read_word_near(&keyReadings[i+1]) - keyVal) / 2; 
    if (reading <= boundary)
      return pgm_read_byte_near(&keyCodes[i]);
  }
  return NO_KEY;
}

/**********************************************************************************
Waits until a key is pressed and released and returns the key code.
**********************************************************************************/
int8_t AnalogKeyPad::waitForKey()
{ 
  while (1)                          // wait for any key to be pressed
    if ( run() && wasPressed() )
        break;
  while (1)                           // wait for any key to be released
    if ( run() && wasReleased() )
        break;

  // return the released key
  return getCurrentKey();
}


