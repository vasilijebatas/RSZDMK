/**
 * @file main.c
 * @brief v6z5
 * @author Vasilije
 * @date 13.5.2021
 * @version 1.01
 */

#include <util/delay.h>
#include "../usart/usart.h"
#include <stdint.h>
#include <stdlib.h>

int16_t operacija (int16_t br1, int8_t znak, int16_t br2)
{
	int16_t rezultat = 0;

	switch(znak)
	{
		case '-':
			rezultat = br1 - br2;
			break;
		case '+':
			rezultat = br1 + br2;
		    break;
		case '*':
			rezultat = br1 * br2;
			break;
		case '/':
			rezultat = br1 / br2;
			break;
		default:
			rezultat = 0;
	}

	return rezultat;
}

int main()
{
	usartInit(9600);
	int8_t tekst[64];
	int16_t broj1;
	int16_t broj2;
	int8_t znak;

	while(1)
	{
		usartPutString("Unesite brojni izraz \r\n");

		while(!usartAvailable())
		;
		_delay_ms(100);

		broj1=usartParseInt();
		znak=usartGetChar();
		broj2=usartParseInt();

		sprintf(tekst, "%d %c %d = %d \0", broj1, znak, broj2, operacija(broj1, znak, broj2));

		usartPutString(tekst);
		usartPutString("\r\n");

	}

	return 0;
}
