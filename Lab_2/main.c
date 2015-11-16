/**************************************************
 * EE312 Lab 2
 *
 * Copyright 2015 University of Strathclyde
 *
 *
 **************************************************/
#include <msp430.h>
#include <driverlib.h>
#include "LEDDriver.h"

int main(void)
{
  //Default MCLK = 1MHz
  
  unsigned int i = 0;
  unsigned char dialValue = 0x01;
  WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

  initialiseLedDial();
  
  // Disable the GPIO power-on default high-impedance mode
  // to activate previously configured port settings
  PMM_unlockLPM5();

  while(1)
  {
    
      dialValue = dialValue * 0x02;
      
      if(0x00 == dialValue)
         dialValue = 0x01;
    
    //Set value
    setLedDial(dialValue);
    
    //Refresh display (10 times for each position)
    for(i = 0; i < 10; i++)
      refreshLedDial();

  }
}
