
/********************************************************
Loonar Technologies Configuration Header File
 
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
#ifndef Configuration_h
#define Configuration_h

/********** PINOUT **********/
const int   GFSK_SDN =          6;
const int   GFSK_IRQ =          14;
const int   GFSK_GATE =         5;
const int   GFSK_GPIO_0 =       21;
const int   GFSK_GPIO_1 =       20;
const int   GFSK_GPIO_2 =       7;
const int   GFSK_GPIO_3 =       8;
const int   GFSK_CS =           10;

/***********************************************************************************************************************************************************************/

/********** CONSTANTS **********/  
#define MESSAGE_LENGTH 20
#define NPAR 40
const uint8_t  BUF_SIZE =                                        100;                          // Data array size for telemetry in bytes. 
const double   FREQ =                                            145.0;                        // Center frequency for radio in MHz. 

#endif /* Configuration_h */
