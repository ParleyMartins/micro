1. Quais as diferenças entre os barramentos de dados e de endereços?

Barramentos de endereços são


2. Quais são as diferenças entre as memórias RAM e ROM?

RAM (_Random Access Memory_) - Perde o conteúdo quando é desligada. É uma memória mais rápida para leitura e escrita. Pode ser lida 'randomicamente' e não por blocos, como na ROM.

ROM é uma memória de acesso mais lento, no entanto, permanente.


3. Considere o código abaixo:

```C
#include <stdio.h>
int main(void)
{
	int i;
	printf("Insira um número inteiro: ");
	scanf("%d", &i);
	if(i%2)
		printf("%d eh impar.\n");
	else
		printf("%d eh par.\n");
	return 0;
}
```

Para este código, responda:

(a) A variável 'i' é armazenada na memória RAM ou ROM? Por quê?

Armazenada na memória RAM, pois só é necessária durante a execução do código.

(b) O programa compilado a partir deste código é armazenado na memória RAM ou ROM? Por quê?

O programa é armazenado na memória ROM, que não perde seu estado quando não possui entrada de energia. O usuário pode reutilizar o programa quando religar o computador, logo, não é interessante salvá-lo na memória RAM.

4. Quais são as diferenças, vantagens e desvantagens das arquiteturas Harvard e Von Neumann?

Harvard:
- Possui as memórias fisicamente separadas, ou seja, barramentos que acessam somente a memória de programa e outros que acessam somente a de dados.
- Permite leitura simultanea de dados e do programa, tornando-a mais eficiente.

Von-Neumman:
- Mesmo bloco (físico) de memória, tanto para a RAM, quanto para a ROM, com divisão interna.
- Menos eficiente que o Harvard, pois não pode fazer mais de uma operação ao mesmo tempo (ler uma instrução e acessar a memória).

5. Considere a variável inteira `i`, armazenando o valor `0x8051ABCD`. Se `i` é armazenada na memória a partir do endereço `0x0200`, como ficam este byte e os seguintes, considerando que a memória é: (a) Little-endian; (b) Big-endian.

6. Sabendo que o processador do MSP430 tem registradores de 16 bits, como ele soma duas variáveis de 32 bits?
