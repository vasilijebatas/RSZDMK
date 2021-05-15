/**
 * @file main.c
 * @brief v7z1
 * @author Vasilije
 * @date 15.5.2021
 * @version v1
 */

#include <util/delay.h>
#include <stdint.h>
#include <string.h>
#include "../usart/usart.h"
#include <stdlib.h>


int main()
{
	usartInit(9600);
	int8_t ime[] = "Vasilije";
    int8_t sifra[] = "sifra";
	int8_t pokusaj_ime[64];
	int8_t pokusaj_sifra[64];

	int8_t inkrement1  = 0;
	int8_t inkrement2  = 0;

	while(1)
	{

	usartPutString("Unesite korisnicko ime: \r\n");
	while(!usartAvailable())
    ;
	_delay_ms(100);
	usartGetString(pokusaj_ime);

	usartPutString("Unesite lozinku: \r\n");
	while(!usartAvailable())
	;
	_delay_ms(100);
	usartGetString(pokusaj_sifra);

	for (int8_t i = 0; i < strlen(ime); i++)
	{
		if (ime[i] == pokusaj_ime[i])
		{
			inkrement1++;
		}
	}

	for (int8_t i = 0; i < strlen(sifra); i++)
	{
		if (sifra[i] == pokusaj_sifra[i])
		{
			inkrement2++;
		}
	}

	if (inkrement1 == strlen(ime))
	{
		usartPutString("Korisnicko ime je tacno ! \r\n");
	}else
	{
		usartPutString("Korisnicko ime je netacno ! \r\n");
	}

	if (inkrement2 == strlen(sifra))
	{
		usartPutString("Sifra je tacna ! \r\n");
	}else
	{
		usartPutString("sifra je netacna ! \r\n");
	}


	}

	return 0;
}
