/*
Loonar Technologies Receiver Code
 
Copyright 2018 Loonar Technologies, LLC

      THIS SOFTWARE IS PRESENTED WITH THE MIT LICENCE:

* Permission is hereby granted, free of charge, to any person 
* obtaining a copy of this software and associated documentation 
* files (the "Software"), to deal in the Software without 
* restriction, including without limitation the rights to use, 
* copy, modify, merge, publish, distribute, sublicense, and/or 
* sell copies of the Software, and to permit persons to whom the 
* Software is furnished to do so, subject to the following conditions:

* The above copyright notice and this permission notice shall be included 
* in all copies or substantial portions of the Software.

* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES 
* OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR 
* ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF 
* CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION 
* WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

/***********************************************************************************************************************************************************************/

/********* LIBRARIES *********/
#include <SPI.h>                      // Serial Peripheral Interface Library
#include "RHRF24.h"                   // Radio Module Library
#include "Configuration_Receiver.h"   // Loonar Technologies Configuration File


/***********************************************************************************************************************************************************************/

/********** OBJECTS **********/
RH_RF24   rf24(GFSK_CS, GFSK_IRQ, GFSK_SDN);  // Radio module object

/***********************************************************************************************************************************************************************/


/*--------------------------------------------------------------------------------------------------------------
   Function:
     setup
   Parameters:
     None
   Returns:
     Nothing
   Purpose: 
     Configures pinmodes, sets up the serial peripheral interface, turns on and initializes the radio module.  
--------------------------------------------------------------------------------------------------------------*/
void setup()
{
  setPinmodes();            // Initialize all the pinModes for every pin (i.e. input, output, etc).
  RadioOff();               // Shut off power to the radio module. 
  setupSPI();               // Initialize the Serial Peripheral Interface with the Radio.
  RadioOn();                // Deliver power to the radio module.
  initializeRadio();        // Initialize and set up all radio parameters (frequency, data rate, etc). 
}


/*--------------------------------------------------------------------------------------------------------------
   Function:
     loop
   Parameters:
     None
   Returns:
     Nothing
   Purpose: 
     
--------------------------------------------------------------------------------------------------------------*/
void loop() 
{
  uint8_t data[MESSAGE_LENGTH] = {0};
  uint8_t leng = MESSAGE_LENGTH;
  if (rf24.recv(data, &leng))
  {
    uint8_t lastRssi = (uint8_t)rf24.lastRssi();
    Serial.print("Got stuff at RSSI ");
    Serial.println(lastRssi);
    for (int i = 0; i < MESSAGE_LENGTH; i++)
    { 
      Serial.print((char)data[i]); 
    }
    Serial.println();
  }
}

/*--------------------------------------------------------------------------------------------------------------
   Function:
     setPinmodes
   Parameters:
     None
   Returns:
     Nothing
   Purpose: 
     Sets up the pinmodes for all of the control pins.
--------------------------------------------------------------------------------------------------------------*/
void setPinmodes()
{
  pinMode(GFSK_GATE, OUTPUT);
  pinMode(GFSK_SDN,OUTPUT);
}


/*--------------------------------------------------------------------------------------------------------------
   Function:
     RadioOff
   Parameters:
     None
   Returns:
     Nothing
   Purpose: 
     Shuts off power to the radio.
--------------------------------------------------------------------------------------------------------------*/
void RadioOff()
{
  digitalWrite(GFSK_GATE, HIGH);
}


/*--------------------------------------------------------------------------------------------------------------
   Function:
     RadioOn
   Parameters:
     None
   Returns:
     Nothing
   Purpose: 
     Delivers power to the radio. 
--------------------------------------------------------------------------------------------------------------*/
void RadioOn()
{
  digitalWrite(GFSK_GATE, LOW);
  delay(1000);
}


/*--------------------------------------------------------------------------------------------------------------
   Function:
     setupSPI
   Parameters:
     None
   Returns:
     Nothing
   Purpose: 
     Configures the serial peripheral interface to the radio module. 
--------------------------------------------------------------------------------------------------------------*/
void setupSPI()
{
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV2);  // Setting clock speed to 8 MHz, as 10 MHz is the max for the radio module. 
  SPI.begin();
  delay(3000); 
}


/*--------------------------------------------------------------------------------------------------------------
   Function:
     initializeRadio
   Parameters:
     None
   Returns:
     Nothing
   Purpose: 
     Initializes the radio, sets its frequency, data rate, and transmit power level. 
--------------------------------------------------------------------------------------------------------------*/
void initializeRadio()
{
  boolean ok = rf24.init(MESSAGE_LENGTH);                                    // Initialize the RF module.
  if (!ok) Serial.println("Unplug and replug the Loonar Receiver Board");    // Check to see if initialization was successful.
  rf24.setFrequency(FREQ);                                                   // Set the center RF frequency.
//rf24.setTxPower(0x7f);                                                     // Set the transmit power to +20 dBm (100mW). 
}





