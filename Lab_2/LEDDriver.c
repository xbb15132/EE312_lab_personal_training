/**************************************************
 * LEDDriver.c
 * Drives LED display
 *
 * Copyright 2015 University of Strathclyde
 *
 *
 **************************************************/

#include "LedDriver.h"

//Current dial value
unsigned char ledValue_ = 0;

/**
Initialise LED Dial, setting GPIO parameters
*/
void initialiseLedDial()
{
  //GPIO 2.7
  GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN7);
    
  //GPIO 5.1, 5.2, 5.3
  //Inserted by student
  GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN1);
  GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN2);
  GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN3);  
  //GPIO 8.0
  //Inserted by student
  GPIO_setAsOutputPin(GPIO_PORT_P8, GPIO_PIN0);
}

/** 
Refresh the display
*/
void refreshLedDial()
{
  //Refresh lower bank (LEDs 1-4)
 //Inserted by student
 P2OUT&=0x7f;   
  P8OUT|=0x01;
  P5OUT&=0xf1;  //light LED1
  __delay_cycles(100000);  //Delay 10ms
  P8OUT&=0xfe;
  P5OUT|=0x02;  //light LED2
  __delay_cycles(100000);
  P5OUT|=0x04;  //light LED3
  __delay_cycles(100000);
  P5OUT|=0x08;  //light LED4
  __delay_cycles(100000);  //Delay 10ms
  //Refresh lower bank (LEDs 5-9)
  //Inserted by student
P2OUT|=0x80;
  P8OUT&=0xfe;
  P5OUT|=0x0e;  //light LED5
  __delay_cycles(100000);  //Delay 10ms
  P8OUT|=0x01;
  P5OUT&=0xfd;  //light LED6
  __delay_cycles(100000);
  P5OUT&=0xfb;  //light LED7
  __delay_cycles(100000);
  P5OUT&=0xf7;  //light LED8
  __delay_cycles(100000);  //Delay 10ms
}

/** 
Set dial value
*/
void setLedDial(unsigned char value)
{
  ledValue_ = value;
}