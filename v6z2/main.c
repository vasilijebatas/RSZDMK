/**
 * @file main.c
 * @brief kapitalizacija
 * @author Vasilije
 * @date 13.05.2021.
 * @version v1.0
 */

#include <util/delay.h>
#include "../usart/usart.h"

int main()
{
	int8_t rec[64];
	int8_t novarec[64];
	int8_t slovo;
	int8_t novoslovo;
	usartInit(9600);
	uint8_t duzina;


	while(1)
	{

    usartPutString("unesite recenicu\r\n");
    while(!usartAvailable())
    ;
    _delay_ms(100);


    duzina=usartGetString(rec);

    for(int8_t i = 0; i < duzina; i++)
    	{
    	    if(rec[i] >= 97 && rec[i] <= 122)
    	    {
    	    	novarec[i] = rec[i]-32;

    	    }else
    	    {
    	    	usartPutString("pogresan unos");
    	    }
    	}

    usartPutString(novarec);

	}


	return 0;
}

