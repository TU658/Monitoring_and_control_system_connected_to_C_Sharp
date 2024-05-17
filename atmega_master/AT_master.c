/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.0 Professional
Automatic Program Generator
© Copyright 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 4/15/2022
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

#include <stdio.h>
#include <mega16.h>
#include <delay.h>
#include <string.h>
#include <spi.h>




unsigned char chuc,dvi;
unsigned long nhietdo;
#define SPI_PORT PORTB
#define SPI_DDR DDRB
#define SCK_PIN  7
#define MISO_PIN 6
#define MOSI_PIN 5
#define SS_PIN 4
//#define ADC_VREF_TYPE ((0<<REFS1) | (0<<REFS0) | (0<<ADLAR))

//unsigned int read_adc(unsigned char adc_input)
//{
//ADMUX=adc_input | ADC_VREF_TYPE;   
//// Delay needed for the stabilization of the ADC input voltage
//delay_us(10);
//// Start the AD conversion
//ADCSRA |= (1<<ADSC);        
//while((ADCSRA & (1<<ADIF)) == 0);    
//ADCSRA |=(1<<ADIF);
//return ADCW;
//}

void SPI_Init()					/* SPI Initialize function */
{
        SPI_DDR = SPI_DDR |(1 << MOSI_PIN) | (1 << SCK_PIN) | (1 << SS_PIN);
        SPI_DDR = SPI_DDR & ~(1 << MISO_PIN);
        SPI_PORT = SPI_PORT |(1 << SS_PIN);
		SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);	
}
// Declare your global variables here
void SPI_Write(char data)		/* SPI write data function */
{
	SPDR = data;			/* Write data to SPI data register */
	while(!(SPSR & (1<<SPIF)));	/* Wait till transmission complete */
	
}
//
char SPI_tranceiver(char data)		/* SPI write data function */
{
	SPDR = data;			/* Write data to SPI data register */
	while(!(SPSR & (1<<SPIF)));	/* Wait till transmission complete */
    return(SPDR);	
}

void uart_char_send(unsigned char chr){
    while (!(UCSRA & (1<<UDRE))) {}; //cho den khi bit UDRE=1  
            UDR=chr;
}

//Ngat Nhan UART
interrupt [USART_RXC] void usart_rx_isr(void)
{
char data;
data=UDR;
if(data == '1')
{   PORTB.2 = 0;
    SPI_Write('1');
    PORTB.2 = 1;
}
if(data == '2')
{   PORTB.2 = 0;
    SPI_Write('2');
    PORTB.2 = 1;
}
if(data == '3')
{   PORTB.2 = 0;
    SPI_Write('3');
    PORTB.2 = 1;
}
if(data == '4')
{   PORTB.2 = 0;
    SPI_Write('4');
    PORTB.2 = 1;
}
if(data == '5')
{   PORTB.3 = 0;
    SPI_Write('5');
    PORTB.3 = 1;
}
if(data == '6')
{   PORTB.3 = 0;
    SPI_Write('6');
    PORTB.3 = 1;
}
if(data == '7')
{   PORTB.3 = 0;
    SPI_Write('7');
    PORTB.3 = 1;
}
if(data == '8')
{   PORTB.3 = 0;
    SPI_Write('8');
    PORTB.3 = 1;
}
}

//void doc_nhiet_do()
//{
//    ADC_out = read_adc(0);  
//    dienap = ADC_out*5000/1023; 
//    nhietdo = dienap/10;
//    chuc = nhietdo/10;
//    dvi = nhietdo%10;
//    uart_char_send(chuc+0x30);
//    uart_char_send(dvi+0x30);
//}

unsigned long dem;
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
// Place your code here
        TCNT0 = 130;       
        dem++;
}           

void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTA=0x00;
DDRA=0x00;

// Port B initialization
// Func7=Out Func6=In Func5=Out Func4=Out Func3=In Func2=In Func1=In Func0=In 
// State7=0 State6=T State5=0 State4=0 State3=T State2=T State1=T State0=T 
PORTB=0x0C;
DDRB=0xBC;

// Port C initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTC=0x00;
DDRC=0xFF;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTD=0x00;
DDRD=0x00;

// Timer/Counter 0 initialization
TCCR0=0x03;             
TCNT0=130;              
TIMSK |=(1<<TOIE0);      
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0<<AS2;
TCCR2=(0<<PWM2) | (0<<COM21) | (0<<COM20) | (0<<CTC2) | (0<<CS22) | (0<<CS21) | (0<<CS20);
TCNT2=0x00;
OCR2=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);


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

// ADC initialization
// ADC Clock frequency: 1000.000 kHz
// ADC Voltage Reference: AREF pin
// ADC Auto Trigger Source: ADC Stopped
//ADMUX=ADC_VREF_TYPE;    
//ADCSRA=(1<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
//SFIOR=(0<<ADTS2) | (0<<ADTS1) | (0<<ADTS0);

// SPI initialization
// SPI Type: Master
// SPI Clock Rate: 500.000 kHz
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First
SPCR=0xD1;
SPSR=0x00;
SPI_Init();
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
//        if((dem == 500))
//       {
//            doc_nhiet_do();
//            dem = 0;
//       }
        if((dem == 500)){
            PORTB |= 0x08;
            PORTB &= ~0x04;
            nhietdo = SPI_tranceiver(0b00); 
            chuc = nhietdo/10;
            dvi = nhietdo%10;
            uart_char_send(chuc+0x30);
            uart_char_send(dvi+0x30);
            uart_char_send(' ');
            dem = 0;
            }
      }
}
