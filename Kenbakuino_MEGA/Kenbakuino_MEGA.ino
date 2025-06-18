/* Kenbakuino_MEGA.ino  Ardunaut Jun 18,2025
 * Using the Arduino MEGA pins to remove the use of shift registers.
 * Changes:
 *   - Updated PINS.h to remove the shift registers lines and add the individual led and button pins.
 *   - Replaced LEDs::ShiftOut() by LEDs::DataOut() in LEDS.cpp and LEDS.h
 *   - Updated LEDs::Init() to set al leds defined in PINS.h as OUTPUT
 *   - Replaced Buttons::ShiftIN() by Buttons::Read() in Buttons.cpp and Buttons.h
 *   - Updated Buttons::Init() to set all buttons defined in PINS.h as INPUT_PULLUP
 *   - Configured RTC to support the DS3231 in Clock.h
 *   - NOTES:
 *       Switch sensing logic was inverted (to use internal pull-ups).
 *       Leds driving logic was inverted (resistors from the anodes to VCC). 
 * -----------------------------------------------------
 * Board:"Arduino Mega or Mega 2560"
 * Processor: "ATmega2560(Mega2650)"
 * Port:
 * 
 */

// ==================================================================
// ==================================================================
//      K E N B A K u i n o
//      Mark Wilson 2011
//  Software emulation of a KENBAK-1.
//  Released under Creative Commons Attribution, CC BY
//  (kiwimew at gmail dot com)
//  Sep 2011: Initial version.
//  Jan 2012: Changes to compile under v1.0 if the IDE (Arduino.h, changes to Wire)
//  May 2014: Corrected control switch order in schematic, 
//            typos in documents (no code changes)
//  Jun 2015: Changes to compile under v1.6.4 if the IDE, (#define for deprecated prog_uchar)  
//  Dec 2018: Corrected SDA/SCL pins, clarified that RTC is a DS1307 module/breakout (i.e. with XTAL)
//            GitHub. Serial read/write memory
//  May 2019: Added Auto-run program at start-up
//            Added Clock consts for no RTC or RTC with no SRAM
//  Jun 2019: Added system extensions to read/write EEPROM
//  May 2021: Fixed right-shift sign extension and issues with multi-bit roll instructions (see CPU_LEGACY_SHIFT_ROLL)
//  Sep 2022: Fixed program counter increment to happen after instruction executed (see CPU_LEGACY_PROGRAM_COUNTER)
//  Nov 2024: Turn RUN LED off when HALT encountered or STOP pressed (see MCP_LEGACY_RUN_LED)
// ==================================================================

// WTF.  We need to include these in the "main sketch" if we want to include them in "tabs"?
#include <Arduino.h>
#include <Wire.h>

#include "PINS.h"
#include "Config.h"
#include "Clock.h"
#include "LEDS.h"
#include "Buttons.h"
#include "CPU.h"
#include "MCP.h"
#include "Memory.h"

ExtendedCPU cpu = ExtendedCPU();

void setup() 
{
  Serial.begin(38400);

  clock.Init();
  buttons.Init();
  config.Init();
  leds.Init();
  cpu.Init();
  memory.Init();
  mcp.Init();
}

void loop() 
{
  mcp.Loop();
}
