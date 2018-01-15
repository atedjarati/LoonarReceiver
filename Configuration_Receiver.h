/*
Loonar Technologies Receiver Configuration File
 
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

//const int   GFSK_SDN =          19;
//const int   GFSK_IRQ =          16;
//const int   GFSK_GATE =         22;
//const int   GFSK_GPIO_0 =       21;
//const int   GFSK_GPIO_1 =       20;
//const int   GFSK_GPIO_2 =       17;
//const int   GFSK_GPIO_3 =       18;
//const int   GFSK_CS =           15;


/***********************************************************************************************************************************************************************/

/********** CONSTANTS **********/  
const int      MESSAGE_LENGTH =         100;                           // Message length in bytes. 
const double   FREQ =                   145.0;                        // Center frequency for radio in MHz. 

#endif /* Configuration_h */
