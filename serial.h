/*
  serial.h - An embedded CNC Controller with rs274/ngc (g-code) support

  Serial driver for Cypress PSoC 5 (CY8CKIT-059)

  Part of Grbl

  Copyright (c) 2017 Terje Io

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdint.h>
#include <stdbool.h>

#define XON  0x11
#define XOFF 0x13
#define EOF  0x1A
#define BS   0x08
#define LF   0x0A
#define CR   0x0D
#define CAN  0x18
#define DEL  0x7F
#define EOL  "\r\n"

#define XONOK (XON|0x80)
#define XOFFOK (XOFF|0x80)
#define RX_BUFFER_SIZE 1024     // must be a power of 2
#define RX_BUFFER_HWM 900
#define RX_BUFFER_LWM 300

void serialInit(void);
int32_t serialGetC(void);
void serialPutC(const char data);
void serialWriteS(const char *data);
void serialWriteLn(const char *data);
void serialWrite(const char *data, unsigned int length);

uint16_t serialTxCount(void);
uint16_t serialRxCount(void);
uint16_t serialRxFree(void);
void serialRxFlush(void);
void serialRxCancel(void);
