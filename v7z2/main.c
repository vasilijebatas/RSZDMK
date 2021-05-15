/**
 * @file main.c
 * @brief samoglasnici
 * @author Vasilije
 * @date 15.5.2021
 * @version v1
 */

#include <util/delay.h>
#include <stdint.h>
#include <stdlib.h>
#include "../usart/usart.h"

int8_t BrojSamoglasnika(int8_t string[64])
{
	int8_t broj = 0;

	for (int8_t i = 0; i < strlen(string); i ++)
	{
		switch(string[i])
		{
		    case 'a':
		    	broj++;
		    	break;
		    case 'e':
		    	broj++;
		    	break;
		    case 'i':
		    	broj++;
		    	break;
		    case 'o':
		    	broj++;
		    	break;
		    case 'u':
		    	broj++;
		    	break;
		    default:
		    	break;
		}
	}

	return broj;
}

int main()
{
	usartInit(9600);
	int8_t recenica[64];
	int8_t recenica2[64];

	while(1)
	{
		usartPutString("unesite recenicu");
		while(!usartAvailable())
		;
		usartGetString(recenica);

		sprintf(recenica2, "%d \0", BrojSamoglasnika(recenica));
		usartPutString(recenica2);
		usartPutString("\r\n");

	}

	return 0;
}
