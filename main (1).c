/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{

float Not1;
float Not2;
float Not3;
float Med;
char Nome[100];

printf("Nome do aluno: ");
fgets(Nome, sizeof(Nome), stdin);
printf("Primeira nota (de 0 a 10): ");
scanf("%f", &Not1);
printf("Segunda nota (de 0 a 10): ");
scanf("%f", &Not2);
printf("Terceira nota (de 0 a 10): ");
scanf("%f", &Not3);

if ( Not1 > 10 || Not1 < 0 || Not2 > 10 || Not2 < 0 || Not3 > 10 || Not3 < 0 ){
printf("Alguma(s) nota(s) inserida(s) é(são) inválida(s), tente novamente seguindo as especificações do site.");
return (0);
}

Med = (Not1 + Not2 + Not3) / 3;

printf("O aluno %s ficou com uma média final de %.2f.\n", Nome, Med);
if (Med >= 6) {
printf("Esse aluno foi aprovado!\n");
}
else {
printf("Esse aluno foi reprovado.\n");
}

}