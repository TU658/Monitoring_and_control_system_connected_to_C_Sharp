/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.0 Professional
Automatic Program Generator
© Copyright 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 4/18/2022
Author  : 
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/

#include <mega16.h>
#include <delay.h>
#include <string.h>


#define SPI_PORT PORTB
#define SPI_DDR DDRB
#define SCK_PIN  7
#define MISO_PIN 6
#define MOSI_PIN 5
#define SS_PIN 4



char SPI_Read()               
{

    while(!(SPSR & (1<<SPIF)));    
    return(SPDR);            
}

// SPI interrupt service routine
interrupt [SPI_STC] void spi_isr(void)
{
unsigned char data;
data = SPI_Read();
if(data == '5')
{   PORTC.0 = 1;
}
else if(data == '6')
{   PORTC.0 = 0;
}
else if(data == '7')
{   PORTC.1 = 1;
}
else if(data == '8')
{   PORTC.1 = 0;
}
}

            
void main(void)
{
// Declare your local variables here

// Port B initialization
// Func7=In Func6=Out Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=0 State5=T State4=T State3=T State2=T State1=T State0=T 
PORTB=0x04;
DDRB=0x40;

// Port C initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTC=0x00;
DDRC=0xFF;


 // USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: On
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud Rate: 9600
UCSRA=0x00;
UCSRB=0x98;
UCSRC=0x86;
UBRRH=0x00;
UBRRL=0x33;

// SPI initialization
// SPI Type: Slave
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First
SPCR=0xC0;
SPSR=0x00;
SPI_DDR = SPI_DDR & ~((1 << MOSI_PIN) | (1 << SCK_PIN) | (1 << SS_PIN));
SPI_DDR = SPI_DDR | (1 << MISO_PIN);
SPI_PORT = SPI_PORT |(1 << SS_PIN);

// Clear the SPI interrupt flag
#asm
    in   r30,spsr
    in   r30,spdr
#endasm

// TWI initialization
// TWI disabled
TWCR=0x00;


// Global enable interrupts
#asm("sei")
while (1)
      {
      }
}
