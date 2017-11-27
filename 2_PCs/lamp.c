#include <msp430g2553.h>
#include <legacymsp430.h>

#define RX BIT1
#define TX BIT2
#define LAMP BIT6

void send_data(unsigned char c);
void init_uart();

int main(void)
{
	WDTCTL = WDTPW + WDTHOLD;

	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;

	P1OUT &= ~LAMP;
	P1DIR |= LAMP;

	init_uart();
	_BIS_SR(GIE);
	return 0;
}

void send_data(unsigned char c)
{
	while((IFG2&UCA0TXIFG)==0);
	UCA0TXBUF = c;
}


void init_uart()
{
	P1SEL2 = P1SEL = RX + TX;
	UCA0CTL0 = 0; //UART, 8bits, no parity,
	UCA0CTL1 = UCSSEL_2; // SMCLK
	UCA0BR0 = 104; //Baud rate: 9600
	UCA0BR1 = 0;
	UCA0MCTL = UCBRF_0 + UCBRS_1; //Baud rate: 9600
	IE2 |= UCA0RXIE; // Set interrruption by UART data arrival
}

void send_state(char state[]){
	int i = 0;

	for(i = 0; state[i] != '\0'; i++){
		send_data(state[i]);
	}
	send_data('\n');
}

interrupt(USCIAB0RX_VECTOR) set_lamp_state(void){
	unsigned char state = UCA0RXBUF;
	if(state == 'n'){ // turn the light on
		P1OUT |= LAMP;
	} else if(state == 'f') { // turn the light off
		P1OUT &= ~LAMP;
	} else if(state == 's') { // check light state
		if((P1OUT&LAMP)==0){
			send_state("off");
		} else{
			send_state("on");
		}
	}
}
