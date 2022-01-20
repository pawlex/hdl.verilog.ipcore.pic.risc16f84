/*cmd.c. implementing a simple command interpreter*/
#include 
#include 
#include 
#include 

int main(){
DDRC= 0xff; //LEDs on PORTC for debugging
sei();
bash_init();
char *tempstr= 0;

	for(;;){
		if(temp==1){//a '/' terminated string received. time to respond!
			temp=0;
			PORTC = 0x01;//the outputs are active HIGH. turns on LED 1.
			if(str[0]=='#'){//first char is a #, so this is a command.
			PORTC |= 0x02;//turns on LED 2
			tempstr= str; //copy the command entered 
			tempstr++;;   //minus the # char
			}
			if(!strcmp(tempstr,"on")){
			PORTC |= 0x04;//turns on LED 3
			tempstr= 0;
			}
			else if(!strcmp(tempstr,"off")){
			PORTC = 0x00; //turns off all LEDs
			tempstr= 0;
			}
		}
	}
}

/*bashcom.h: contains declarations of UART functions and macros*/
#define F_CPU 16000000
#define BAUD_RATE 9600
#define BAUD_PRESCALE ((F_CPU/(BAUD_RATE * 16UL)) - 1)

volatile char str[15];
volatile int temp;

void bash_init();
void putc_to_bash(char char_to_display);
void puts_to_bash(char* string_to_display);

/*bashcom.c. contains USART funtions*/
#include 
#include 
#include 

/*int main(void) //the main function. just in case I need to test it later...
{

bash_init();

sei();
	for(;;){
	if(temp == 1){
	puts_to_bash(str);
	temp= 0;
	}
	}
}*/

void bash_init(){//init the USART
UCSRB |= (1<<RXEN) | (1<<TXEN);
UCSRC= 0x00;
UCSRC |= (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);//8 bit mode.
UBRRH |= (BAUD_PRESCALE >> 8);
UBRRL |= BAUD_PRESCALE; //prescaler set for 9600 baud
UCSRB |= (1<<RXCIE);
temp= 0;
}

ISR(USART_RXC_vect){
static int count;//number of chars received

char RxByte;
RxByte = UDR;
	if(!(RxByte == '/')){
	str[count]= RxByte;//storing characters in str array.
	count++;
	}
	else if((RxByte == '/') || (count==13)){
	str[count]= '\0';
	count= 0;
	temp= 1;//got a '/' terminated string. tell anyone who cares to know
	}
}

void puts_to_bash(char* string){//writes an entire string to bash
	while(!((*string) == '\0')){
	putc_to_bash(*string);
	string++;
	}
	temp= 0;
}

void putc_to_bash(char dispchar){//writes single chars to bash
	while(!(UCSRA & (1<<UDRE)));
UDR= dispchar;
}
