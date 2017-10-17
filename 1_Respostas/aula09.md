1. Escreva uma função em C que faz o debounce de botões ligados à porta P1.

```C
#include <msp430g2553.h>
#include <legacymsp430.h>

#define BTN BIT3

int main(void){
	WDTCL = WDTPW | WDTHOLD;
	P1OUT |= BTN;
	P1DIR &= ~BTN;
	P1IES |= BTN;
	P1IE |= BTN;
	_BIS_SR(GIE + LPM4_bits);

}

interrupt(PORT1_VECTOR) debounce(void){
	int count = 100;
	while (count != 0){
		if((P1IN&BTN) == 0){
			count >> 1;
		} else {
			count = 100;
		}
	}
	P1IFG &= ~BTN;
	button_action();
}
```


2. Escreva um código em C que lê 9 botões multiplexados por 6 pinos, e pisca os LEDs da placa Launchpad de acordo com os botões. Por exemplo, se o primeiro botão é pressionado, os LEDs piscam uma vez; se o segundo botão é pressionado, os LEDs piscam duas vezes; e assim por diante. Se mais de um botão é pressionado, os LEDs não piscam.

```C
#include <msp430g2553.h>
#include <legacymsp430.h>

#define BTN BIT6
#define X (BIT0 | BIT1 | BIT2)
#define Y (BIT3 | BIT4 | BIT5)

void invert_in_out(){
	P1OUT &= ~X;
	P1DIR &= ~X;

	P1OUT |= Y;
	P1DIR |= Y;

	if()

}

int main(void) {
	WDTCL = WDTPW | WDTHOLD;
	P1OUT &= ~X;
	P1DIR &= ~X;

	P1OUT &= ~Y;
	P1DIR |= Y;
	P1REN |= Y;

	P1

	while(1){
		if((P1OUT&BIT0) == 0){

		} else if((P1OUT&BIT1) == 0){

		} else if((P1OUT&BIT2) == 0){

		}
	}


}

```
