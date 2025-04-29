#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int boletim(){

int n_cursos;
char curso[MAX_CURSO];
char aluno[MAX_ALUNO];
float n1[n_cursos], n2[n_cursos], n3[n_cursos], media[n_cursos];
char *situacao;

FILE *arquivo = fopen("boletim.csv", "w");

if (arquivo == NULL) {
printf("Erro ao criar o arquivo.\n");
return 1;
}

fprintf(arquivo, "Curso,Aluno,Nota1,Nota2,Nota3,Media,Situacao\n");

for(int i = 0; i < n_cursos; i++){
curso[strcspn(curso, "\n")] = 0;
aluno[strcspn(aluno, "\n")] = 0;
situacao = (media[i] >= 6.0) ? "Aprovado" : "Reprovado";
fprintf(arquivo, "%s,%s,%.2f,%.2f,%.2f,%.2f,%s\n",
curso, aluno, nota1, nota2, nota3, media, situacao);
}
}
