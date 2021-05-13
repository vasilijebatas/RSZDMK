/**
 * @file main.c
 * @brief imeprezime zadatak
 * @author Vasilije
 * @date 13.05.2021.
 * @version 1.0
 */

#include <util/delay.h>
#include "../usart/usart.h"

int main()
{
   int8_t ispis[40] = "Unesite ime i prezime \r\n";
   int8_t ime[20];

   usartInit(9600);

   while(1)
   {
	   usartPutString(ispis);

	   while(!usartAvailable())
	   ;
	   _delay_ms(100);

	   usartGetString(ime);
	   usartPutString("Zdravo, ");
	   usartPutString(ime);
	   usartPutString(". :) \r\n");
	   //while(1);
	}

	return 0;
}
