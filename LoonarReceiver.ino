
/********************************************************
Loonar Technologies Receiver Code
 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

********************************************************/

/***********************************************************************************************************************************************************************/

/********* LIBRARIES *********/
#include <SPI.h>
#include <RH_RF24.h>
#include "Configuration.h"


/***********************************************************************************************************************************************************************/

/********** OBJECTS **********/
RH_RF24                  rf24(GFSK_CS, GFSK_IRQ, GFSK_SDN);

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
  setPinmodes();                  // Initialize all the pinModes for every pin (i.e. input, output, etc).
  RadioOff();                     // Shut off power to the radio module. 
  setupSPI();                     // Initialize the Serial Peripheral Interface with the Radio.
  RadioOn();                      // Deliver power to the radio module.
  initializeRadio();              // Initialize and set up all radio parameters (frequency, data rate, etc). 
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
  uint8_t data[60] = {0};
  uint8_t leng = MESSAGE_LENGTH + NPAR;
  boolean tru = rf24.recv(data, &leng);
  if (tru) 
  {
    uint8_t lastRssi = (uint8_t)rf24.lastRssi();
    Serial.print("Got stuff at RSSI ");
    Serial.println(lastRssi);
    for (int i = 0; i < 60; i++)
    { 
      Serial.print((char)data[i]); 
    }
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
  SPI.setClockDivider(SPI_CLOCK_DIV2);  // Setting clock speed to 8mhz, as 10 is the max for the rfm22
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
  rf24.init(MESSAGE_LENGTH + NPAR);
  uint8_t buf[8];
  rf24.command(RH_RF24_CMD_PART_INFO, 0, 0, buf, sizeof(buf));
  rf24.setFrequency(FREQ);
  rf24.setModemConfig(rf24.GFSK_Rb0_5Fd1);   // GFSK 500 bps
  rf24.setTxPower(0x7f);  
}
