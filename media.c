
#include <stdio.h> //incluindo a biblioteca

// definindo uma struct para registrar mais facilmente a nota de cada aluno
// obs: A struct será definida em outra parte do projeto, essa é apenas para testes

struct provas {

    float p1;
    float p2;
    float p3;
    float media;
};


// definindo a função que irá exibir as notas e as médias

void media(struct provas aluno) {

    //essa variavel vai contar a quantidade de provas que ja foram realizadas ate o momento
    //se uma prova ainda nao foi realizada, o professor deve atribuir uma nota negativa
    int quant_de_provas = 0;


    //mensagem ao entrar na pagina de consulta das notas
    printf("\n\tAvaliação do aluno Alberto:\n\n");

     //checando se todas as provas ja foram realizadas
    if (aluno.p1 >= 0 && aluno.p2 >= 0 && aluno.p3 >= 0) {


        aluno.media = (aluno.p1 + aluno.p2 + aluno.p3) / 3; //se todas ja foram realizadas calcula a media
        quant_de_provas = 3;                               //foram realizadas 3 provas


    }else if (aluno.p2 < 0) {      // checando se a p2 foi realizada, se nao tiver sido realizada, automaticamente a p3 tambem nao foi

        aluno.media = aluno.p1;  // a media do aluno sera apenas a nota da primeira prova
        quant_de_provas = 1;    // apenas uma prova foi realizada, a p1  

    } else {                   // se a p2 foi realizada entao a unica nao realizada foi a p3

        aluno.media =  (aluno.p1 + aluno.p2) / 2; // a media sera calculada apenas pelas duas primeiras notas
        quant_de_provas = 2;                     // duas provas foram realizadas


    }

    //checando quantas provas foram feitas para exibir as medias
    switch(quant_de_provas) {

        case 3: 

        printf("Primeira prova: %2.f\n", aluno.p1);
        printf("Segunda prova:  %2.f\n", aluno.p2);
        printf("Terceira prova: %2.f\n", aluno.p3);
        printf("\nMédia final:    %2.f\n", aluno.media);

        break;

        case 2: 
        
        printf("Primeira prova: %2.f\n", aluno.p1);
        printf("Segunda prova:  %2.f\n", aluno.p2);
        printf("Terceira prova: Não realizada\n");
        printf("\nMédia parcial:    %2.f\n", aluno.media);

        break;

        case 1: 
        
        printf("Primeira prova: %2.f\n", aluno.p1);
        printf("Segunda prova:  Não realizada\n");
        printf("Terceira prova: Não realizada\n");
        printf("\nMédia parcial:    %2.f\n", aluno.media);

        break;


    }
};


int main() {

    struct provas Alberto;

        Alberto.p1 =10;
        Alberto.p2 = 8; 
        Alberto.p3 = -1;
        

    
    media(Alberto);



}