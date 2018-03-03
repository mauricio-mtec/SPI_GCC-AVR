/*Rotina básica para transmissão de  dados SPI*/
/*Microcontrolador: Atmega328p*/
/*Compilador: gcc-avr*/
/*Autor: Mauricio Martins*/


#include <avr/io.h>

#define DDR_SPI     DDRB  // Port de direcionamento SPI
#define MOSI        PB3   // Pino MOSI
#define SCK         PB5   // Pino SCK
#define SPI_PORT    PORTB // Pino SPI físico



void Spi_init(void)
{
	//Configura SCK e MOSI como saidas
	DDRB |= 0b00101000;   
    	
	/* Inicia SPI, ajusta de frequencia fck/16 */   // >>
	//Frequencia de Clock SPI = 1Mhz
	SPCR = (1<<SPE) | (1<<MSTR) | (1<<SPR0);
}

uint8_t Spi_write(uint8_t data)
{
	//Carrega dados em SPDR e inicia a transmissão
	SPDR = data;  
	//Aguarda termino da transmissão
    	while(!(SPSR & (1<<SPIF))); 
	//Retorna dados MISO
    	return SPDR;  
}
