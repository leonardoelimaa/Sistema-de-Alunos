
#include <stdio.h> //incluindo a biblioteca

#define MAX_ALUNOS 100
#define MAX_NOME 100
#define MAX_CURSO 50
#define MAX_OBS 200

 typedef struct {
    char nome[MAX_NOME];
    int matricula;
    char curso[MAX_CURSO];
    char observacoes[MAX_OBS];
    float p1;
    float p2;
    float p3;
    float media;
    

} Aluno;

Aluno alunos[MAX_ALUNOS];

// definindo a função que irá exibir as notas e as médias

void media(int i) {

    //essa variavel vai contar a quantidade de provas que ja foram aplicadas ate o momento
    //se uma prova ainda nao foi aplicada, o professor deve atribuir uma nota negativa
    int quant_de_provas = 0;


    //mensagem ao entrar na pagina de consulta das notas
    printf("\n\tAvaliação do aluno %s:\n\n", alunos[i].nome);

     //checando se todas as provas ja foram aplicadas
    if (alunos[i].p1 >= 0 && alunos[i].p2 >= 0 && alunos[i].p3 >= 0) {


        alunos[i].media = (alunos[i].p1 + alunos[i].p2 + alunos[i].p3) / 3; //se todas ja foram aplicadas calcula a media
        quant_de_provas = 3;                               //foram aplicadas 3 provas


    }else if (alunos[i].p2 < 0) {      // checando se a p2 foi aplicada, se nao tiver sido aplicada, automaticamente a p3 tambem nao foi

        alunos[i].media = alunos[i].p1;  // a media do alunos[i] sera apenas a nota da primeira prova
        quant_de_provas = 1;    // apenas uma prova foi aplicada, a p1  

    } else {                   // se a p2 foi aplicada entao a unica nao aplicada foi a p3

        alunos[i].media =  (alunos[i].p1 + alunos[i].p2) / 2; // a media sera calculada apenas pelas duas primeiras notas
        quant_de_provas = 2;                     // duas provas foram aplicadas


    }

    //checando quantas provas foram feitas para exibir as medias
    switch(quant_de_provas) {

        case 3: 

        printf("Primeira prova: %2.f\n", alunos[i].p1);
        printf("Segunda prova:  %2.f\n", alunos[i].p2);
        printf("Terceira prova: %2.f\n", alunos[i].p3);
        printf("\nMédia final:    %2.f\n", alunos[i].media);

        break;

        case 2: 
        
        printf("Primeira prova: %2.f\n", alunos[i].p1);
        printf("Segunda prova:  %2.f\n", alunos[i].p2);
        printf("Terceira prova: Não aplicada\n");
        printf("\nMédia parcial:    %2.f\n", alunos[i].media);

        break;

        case 1: 
        
        printf("Primeira prova: %2.f\n", alunos[i].p1);
        printf("Segunda prova:  Não aplicada\n");
        printf("Terceira prova: Não aplicada\n");
        printf("\nMédia parcial:    %2.f\n", alunos[i].media);

        break;


    }
};


