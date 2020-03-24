#include <stdio.h>
#include<stdlib.h>   //header files for code 
 
/*
 Hardware related definition
 */
/*
 *Application related function and definition
 */#include "header_cd.h"
#include "func.h"
int i,j;
void system_init (void);           // This function will initialise the ports.
void full_drive (char direction); // This function will drive the motor in full drive mode

void ms_delay(unsigned int val);  // function for delay 

 


void ms_delay(unsigned int val)      //function defined here for delay..
{
     unsigned int i,j;
        for(i=0;i<val;i++)
            for(j=0;j<1650;j++);
}
void system_init (void)
{
    TRISB = 0x00;     // PORT B as output port
    PORTB = 0x0F;     //port d pins defined for output..
}
void full_drive (char direction)
{
    if (direction == anti_clockwise)  {   //code defined for anti-clockwise rotation  
        PORTB = 0b00000011;
        ms_delay(speed);
        PORTB = 0b00000110;
        ms_delay(speed);
        PORTB = 0b00001100;
        ms_delay(speed);
        PORTB = 0b00001001;
        ms_delay(speed);
        PORTB = 0b00000011;
        ms_delay(speed);
    }
    if (direction == clockwise){        //code defined for clockwise rotation 
        PORTB = 0b00001001;
        ms_delay(speed);
        PORTB = 0b00001100;
        ms_delay(speed);
        PORTB = 0b00000110;
        ms_delay(speed);
        PORTB = 0b00000011;
        ms_delay(speed);
        PORTB = 0b00001001;
        ms_delay(speed);
    }
        
}
 
/* This method will drive the motor in full-drive mode using direction input */
 


void main(void)
{
system_init(); //called defined function 
while(1){
/* Drive the motor in full drive mode clockwise */
for(int i=0;i<steps;i++)
{
            full_drive(clockwise);
}
        
ms_delay(1000);   //delay for 1 sec 
 
/* Drive the motor in wave drive mode anti-clockwise */
for(int i=0;i<steps;i++)
{
            
            full_drive(anti_clockwise);
}
ms_delay(1000);
}
}
