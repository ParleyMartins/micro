Para todas as questões abaixo, utilize o modo de comparação do Timer A.

1. Para os itens abaixo, confira a diferença no brilho do LED.
```C
#include <msp430g2553.h>

#define BASE_COUNT 1250

// Blinks led in a given frequency. It should be as small as 100 Hz.
// Duty cycle has to be an integer between 1 and 100.
void blink_led(volatile unsigned int freq, volatile unsigned char duty_cicle){
	TACCTL = OUTMOD_3;
	TACCR0 = BASE_COUNT*(freq/100) - 1;
	TACCR1 = (TACCR0 + 1)*duty_cicle/100;
	TACTL = TASSEL_2 + ID_3 + MC_1;
}

```
(a) Pisque o LED no pino P1.6 numa frequência de 100 Hz e ciclo de trabalho de 25%.

```C
int main(void){
	P1DIR |= BIT6;
	P1SEL |= BIT6;
	P1SEL2 &= ~BIT6;

	blink_led(100, 25);
}

```
(b) Pisque o LED no pino P1.6 numa frequência de 100 Hz e ciclo de trabalho de 50%.
```C
int main(void){
	P1DIR |= BIT6;
	P1SEL |= BIT6;
	P1SEL2 &= ~BIT6;

	blink_led(100, 50);
}

```
(c) Pisque o LED no pino P1.6 numa frequência de 100 Hz e ciclo de trabalho de 75%.
```C
int main(void){
	P1DIR |= BIT6;
	P1SEL |= BIT6;
	P1SEL2 &= ~BIT6;

	blink_led(100, 75);
}

```


```C
// blinks led at 1 Hz
void blink_led(volatile unsigned char duty_cicle){
	TACCR0 = 625*duty_cicle;
	TACCR1 = 62500 - TACCR0 - 1;

	TACTL0 = TASSEL_2 + ID_3 + MC_1;
	TACTL1 = TASSEL_2 + ID_3 + MC_1;

	while(1){
		int i = 0;
		P1OUT |= BIT6;
		TACTL1 |= TACLR;
		for(i = 0; i < 2; i++){
			while((TACTL0 & TAIFG) == 0);
			TACTL0 &= ~TAIFG;
		}
		P1OUT &= ~BIT6;
		TACTL1 |= TACLR;
		for(i = 0; i < 2; i++){
			while((TACTL1 & TAIFG) == 0);
			TACTL1 &= ~TAIFG;
		}
	}

}
```

2. Pisque o LED no pino P1.6 numa frequência de 1 Hz e ciclo de trabalho de 25%.
```C
int main(void){
	P1DIR |= BIT6;

	blink_led(25);
}
```

3. Pisque o LED no pino P1.6 numa frequência de 1 Hz e ciclo de trabalho de 50%.
```C
int main(void){
	P1DIR |= BIT6;

	blink_led(50);
}
```

4. Pisque o LED no pino P1.6 numa frequência de 1 Hz e ciclo de trabalho de 75%.
```C
int main(void){
	P1DIR |= BIT6;

	blink_led(75);
}
```
