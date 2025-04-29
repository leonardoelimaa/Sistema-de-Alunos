#include <stdio.h>

int relatorio() {

	char usuario_professor[40], nome_aluno[100][NUMERO_ALUNOS];
	int NUMERO_ALUNOS, i;
	float media[NUMERO_ALUNOS], n1[NUMERO_ALUNOS], n2[NUMERO_ALUNOS], n3[NUMERO_ALUNOS];

	printf("\n----------Relatório do professor %s----------\n", usuario_professor);
	printf("\nNome do aluno\t Nota 1\t Nota 2\t Nota 3\t Média\t Aprovação\n");
	printf("----------------------------------------------------------\n");

	for(i=0; i < NUMERO_ALUNOS; i++) {
		if(media[i] >= 6) {
			printf("%s\t %.2f\t %.2f\t %.2f\t %.2f\t APROVADO\n",nome_aluno[i], n1[i], n2[i], n3[i], media[i]);
		}
		else {
			printf("%s\t %.2f\t %.2f\t %.2f\t %.2f\t REPROVADO\n",nome_aluno[i], n1[i], n2[i], n3[i], media[i]);
		}
	}

}
