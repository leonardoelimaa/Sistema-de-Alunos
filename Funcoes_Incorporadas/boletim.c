#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int boletim(){

int n_cursos, matriclula[MAX_ALUNO];
char curso[MAX_CURSO];
char aluno[MAX_ALUNO];
float n1[n_cursos], n2[n_cursos], n3[n_cursos], media[n_cursos];
char *situacao;

FILE *arquivo = fopen("boletim.csv", "w");

if (arquivo == NULL) {
printf("Erro ao criar o arquivo.\n");
return 1;
}

aluno[strcspn(aluno, "\n")] = 0;
fprintf(arquivo, "Nome:,%s,Matricula:,%i",
 aluno, matriclula);)

fprintf(arquivo, "Curso,Nota1,Nota2,Nota3,Media,Situacao\n");

for(int i = 0; i < n_cursos; i++){
if(curso[i] == 1){
curso[strcspn(curso, "\n")] = 0;
situacao = (media[i] >= 6.0) ? "Aprovado" : "Reprovado";
fprintf(arquivo, "%s,%.2f,%.2f,%.2f,%.2f,%s\n",
 curso, nota1, nota2, nota3, media, situacao);
}
}
}
