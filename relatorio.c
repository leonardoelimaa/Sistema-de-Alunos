#include <stdio.h>

int relatorio(){

char usuario_professor[40], nome_aluno[100][100];
int quant_de_provas, quant_de_alunos, i;
float media[100], n1[100], n2[100], n3[100];

printf("Número de alunos: ");
scanf("%d", &quant_de_alunos);

for (i=0; i < quant_de_alunos; i++){
printf("\n\nNome do %dº aluno:\n", i+1);
scanf("%s", nome_aluno[i]);
printf("Nota da prova 1 do %dº aluno:\n", i+1);
scanf("%f", &n1[i]);
printf("Nota da prova 2 do %dº aluno:\n", i+1);
scanf("%f", &n2[i]);
printf("Nota da prova 3 do %dº aluno:\n", i+1);
scanf("%f", &n3[i]);
media[i] = (n1[i] + n2[i] + n3[i]) / 3;
}

printf("\n----------Relatório do prfessor %s----------\n", usuario_professor);
printf("\nNome do aluno\t Nota 1\t Nota 2\t Nota 3\t Média\t Aprovação\n");

for(i=0; i < quant_de_alunos; i++){
if(media[i] >= 6){
printf("%s\t %.2f\t %.2f\t %.2f\t %.2f\t APROVADO\n",nome_aluno[i], n1[i], n2[i], n3[i], media[i]);
}
else{
printf("%s\t %.2f\t %.2f\t %.2f\t %.2f\t REPROVADO\n",nome_aluno[i], n1[i], n2[i], n3[i], media[i]);
}
}

}
