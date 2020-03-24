/* 
 * File:   main.c
 * Author: SURINDER  MEHTOT
 *
 * Created on March 4, 2020, 3:29 PM
 */
// main source file containing main code 
#include <stdio.h>
#include <stdlib.h> // c code libraries
#include"led.h"     //included header file 


int main()
{
  TRISD0 = 0;                  //RD0 as Output PIN
  PORTD=0x00;                  //port d as output
  while(1)
  {
    RD0 = 1;           // LED ON
    __delay_ms(1000); // 1 Second Delay
    RD0 = 0;          // LED OFF
    __delay_ms(1000); // 1 Second Delay
  }
  return 0;
}
