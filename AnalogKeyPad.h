/*
 * AnalogKeyPad - Interface with joystick type button on an analog pin
 *
 * Copyright (c) 2013 oryshed <oryshed@gmail.com>
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
#define AnalogKeyPad_h

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

#include <avr/pgmspace.h>

//#define DEBUG_ANALOG_KEYPAD

class AnalogKeyPad
{
  public:
  
  // key names
  static const int8_t NO_KEY='-', UP='U', RIGHT = 'R', DOWN = 'D', LEFT = 'L', SELECT = 'S';
  
  // public methods
  AnalogKeyPad(int8_t analogPin);

  int8_t keyUpEvent();                                  // does debouncing and if the key was released returns the key code
  int8_t keyDownEvent();                                // does debouncing and if the key was pressed returns the key code
  boolean run();                                        // true if the key was pressed or released
  boolean wasPressed();                                 // true if the key was pressed during the last update cycle
  boolean wasReleased();                                // true if the key was released during the last update cycle
  int8_t getCurrentKey();                               // return the current key

  int8_t waitForKey();                                  // waits until a key is pressed and released
  
  private:
  uint8_t pin;
  uint32_t _timestamp;
  int8_t _prevReading;
  int8_t _keyCode;
  uint8_t _keyFlags;
  
#ifdef DEBUG_ANALOG_KEYPAD
  int16_t _prevAnalogReading;
#endif
  
  // ADC value/keycode arrays
  static const int8_t NUM_KEYS = 5;
  PROGMEM static const uint16_t keyReadings[NUM_KEYS+1];
  PROGMEM static const int8_t keyCodes[NUM_KEYS+1];
  
  static const uint8_t DEBOUNCE_INTERVAL = 5;                  // in milliseconds
  static const uint8_t FLAG_PRESSED = 1, FLAG_RELEASED = 2;    // values for the keyFlags 

  //private functions
    static int8_t getKeyCode(uint16_t reading);
} ;

#endif


