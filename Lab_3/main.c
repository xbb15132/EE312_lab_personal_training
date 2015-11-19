#include <msp430.h>
#include <driverlib.h>
#include "LEDDriver.h"

unsigned int k=1;
int main(void)
{
  //Default MCLK = 1MHz
  
  unsigned int i = 0;
  unsigned char dialValue = 0x01;
  WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
  
  initialiseLedDial();
  _enable_interrupt();
  // Disable the GPIO power-on default high-impedance mode
  // to activate previously configured port settings
  PMM_unlockLPM5();
  
  unsigned int j;
  //S=1;
  while(1)
  {
      dialValue = dialValue * 0x02;
      if(0x00 == dialValue)
         dialValue = 0x01;
    
    //Set value
      if(k==1)
      {  
        for(j=0;j<8;j++)
        { 
          if(0x00 == dialValue)
            dialValue = 0x01;
          setLedDial(dialValue);
          dialValue=dialValue<<1;
        //Refresh display (10 times for each position)
        for(i = 0; i < 10; i++)
          refreshLedDial();
        }
       
      }
      else
      {
        if(0x00 == dialValue)
          dialValue=0x80;
        for(j=0;j<8;j++)
        {
          setLedDial(dialValue);
          dialValue=dialValue>>1;
        //Refresh display (10 times for each position)
        for(i = 0; i < 10; i++)
          refreshLedDial();
       }
      }
  }
 
}
#pragma vector=PORT1_VECTOR
  __interrupt void P1_ISR(void)
  {
    //SW_interruptFlag_=1; //set flag
    k=-k;
    GPIO_clearInterrupt(GPIO_PORT_P1,GPIO_PIN3);
  }