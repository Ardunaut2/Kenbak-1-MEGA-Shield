#ifndef pins_h
#define pins_h
 
// Pin assignments
// DS1307 - RTC (wire library)
#define PIN_RTC_SDA	A4
#define PIN_RTC_SCL	A5

/*
// 74HC595 - LED driver pins "NOT USED"
#define PIN_LEDS_DS	8
#define PIN_LEDS_ST	9
#define PIN_LEDS_SH	10

// 74HC165 - Switch driver  "NOT USED"
#define PIN_BTN_Q7	A0
#define PIN_BTN_CP	13
#define PIN_BTN_PL	12

// LEDS - direct connection  "REASSIGNED"
#define PIN_LED_INP	A1
#define PIN_LED_ADDR	A2
#define	PIN_LED_MEM	A3
#define PIN_LED_RUN_PWM	11
*/

// Arduino Mega pin assignment:
// LEDS - direct connection
#define PIN_LED_INP     14
#define PIN_LED_ADDR    15
#define PIN_LED_MEM     16
#define PIN_LED_RUN_PWM  2

// Data leds (same order as shift register outputs):
const int DataOutPins[] = {
  11,  // Bit_7
  10,  // Bit_6
  9,   // Bit_5
  8,   // Bit_4
  7,   // Bit_3
  6,   // Bit_2
  5,   // Bit_1
  4    // Bit_0
  };

// Switches (same order as shift registers inputs):  
const int ButtonPins[] = {
  A7,   // Inp_0
  A6,   // Inp_1
  A1,   // Inp_6
  A0,   // Inp_7
  A3,   // Inp_4
  A2,   // Inp_5
  A5,   // Inp_2
  A4,   // Inp_3
  A14,  // STOP
  A13,  // START
  A13,  // -Not Used-
  A8,   // CLR
  A9,   // DISP
  A10,  // SET
  A11,  // READ
  A12   // STOR
  };

/*********************************************************
Kenbak-1 MEGA Part List:
 1.- Resistor 1/4W 4.7k 5% (R1-R8) .....................................  8
 2.- Resistor 1/4W 560 5% (R9-R12) .....................................  4
 3.- 3mm Warm White Diffused led (D1-D8) ...............................  8
 4.- 3mm Yellow Diffused led (D9-D12) ..................................  4
 5.- Same Sky TS02-66-43-BK-100-LCR-D Tactile Switch 6x6mm 4.3mm Height 
     100gr actuation force, Black (SW1-SW4, SW9, SW11, SW13, SW15)......  8
 6.- OMRON B3F-1000 Tactile Switch 6x6mm 4.3mm Height
     100gr actuation force, White (SW5-SW8, SW10, SW12, SW14) ..........  7
 7.- 5-pin header ......................................................  1
 8.- 8-pin header ......................................................  5
 9.- 10-pin header .....................................................  1
10.- DS3231 Real Time Clock Module (J1) ................................  1
11.- Arduino Mega 2560 Rev3 or compatible ..............................  1
                                                                Ardunaut Jun 9,2025
*********************************************************/                                                               
#endif
