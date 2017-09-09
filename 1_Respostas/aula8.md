Para todas as questões, utilize os LEDs e/ou os botões da placa Launchpad do MSP430.

1. Escreva um código em C que pisca os LEDs ininterruptamente.

```C
#include <msp430g2553.h>
#define LED1 BIT0
#define LED2 BIT6
#define LEDS (LED1|LED2)

int main(void){
	WDTCTL = WDTPW | WDTHOLD;
	P1OUT |= LEDS;
	P1DIR |= LEDS;

	while(1){
		P1OUT ^= LEDS;
		int i = 0xFFFF; // delay pra facilitar a visualizacao
		while(i--);
	}
}
```

2. Escreva um código em C que pisca os LEDs ininterruptamente. No ciclo que pisca os LEDs, o tempo que os LEDs ficam ligados deve ser duas vezes maior do que o tempo que eles ficam desligados.

```C
#include <msp430g2553.h>
#define LED1 BIT0
#define LED2 BIT6
#define LEDS (LED1|LED2)

void delay(volatile unsigned int i){
	while(i--);
}

int main(void){
	WDTCTL = WDTPW | WDTHOLD;
	P1OUT |= ~LEDS;
	P1DIR |= LEDS;

	while(1){
		P1OUT ^= LEDS;
		int i = 0xFFFF; // delay pra facilitar a visualizacao
		delay(i); // Sera que eu consigo fazer um delay(2*i)? Testar no msp
		delay(i);
		P1OUT ^= LEDS;
		delay(i);
	}
}
```

3. Escreva um código em C que acende os LEDs quando o botão é pressionado.

```C
#include <msp430g2553.h>

#define LED1 BIT0
#define LED2 BIT6
#define LEDS (LED1|LED2)

#define BTN BIT3

int main(void){
	WDTCTL = WDTPW | WDTHOLD;
	P1OUT |= ~LEDS;
	P1DIR |= LEDS;

	P1DIR &= ~BTN;
	P1OUT |= BTN;
	P1REN |= BTN;

	while(1){
		if((P1IN&BTN) == 0){
			P1OUT |= LEDS;
		} else {
			P1OUT &= ~LEDS;
		}
	}
	return 0;
}
```

4. Escreva um código em C que pisca os LEDs ininterruptamente somente se o botão for pressionado.

5. Escreva um código em C que acende os LEDs quando o botão é pressionado. Deixe o MSP430 em modo de baixo consumo, e habilite a interrupção do botão.
