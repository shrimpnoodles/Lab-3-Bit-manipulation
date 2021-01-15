/*	Author: hcier001
 *  Partner(s) Name: nona
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char GetBit(unsigned char x, unsigned char k){
	return ((x & (0x01 << k )) != 0);
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA= 0x00; PORTA =0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char counter = 0x00;
	unsigned char i = 0x00;
	unsigned char TEMP = 0x00;
    /* Insert your solution below */
    while (1) {
	TEMP = PINA;
	while(i < 8){
		counter = GetBit(TEMP, i) + counter;
		i++;
	}
	i = 0x00; //reset i
	TEMP = PINB;
	while(i < 8){
		counter = GetBit(TEMP, i) + counter;
		i++;
	}
	i = 0x00;
	PORTC= counter;
	counter=0x00;
}

	 
    
    return 1;
}
