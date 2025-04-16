// ---- este trecho é definido na biblioteca do projeto ----
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

// ---- aqui acaba o trecho que é definido na biblioteca do projeto ----



// definindo a função que irá calcular a média e exibir as notas e as médias

void media(int i) {

    /* -- A variável quant_de_provas vai contar a quantidade de provas que já foram aplicadas até o momento
       -- Se uma prova ainda não foi aplicada, o professor deve atribuir uma nota negativa à variável p(1, 2 ou 3)
       -- Logicamente, se uma prova ainda não foi aplicada, a prova seguinte também não. Um professor não vai aplicar a terceira prova sem antes
    aplicar a segunda
       -- Portanto, p1 = -1, p2 =10, p3 = 4 é um exemplo de sequencia inválida de notas
    */
    int quant_de_provas = 0;


     //checando se todas as provas já foram aplicadas
    if (alunos[i].p1 >= 0 && alunos[i].p2 >= 0 && alunos[i].p3 >= 0) {


        alunos[i].media = (alunos[i].p1 + alunos[i].p2 + alunos[i].p3) / 3; //se todas já foram aplicadas calcula a média
        quant_de_provas = 3;                                               //foram aplicadas as 3 provas

    }else if (alunos[i].p1 < 0) {       //checando se a p1 foi aplicada, se não foi então o professor ainda não aplicou nenhuma prova

        alunos[i].media = -1;         //definindo a média com um valor arbitrário de -1, mas ela não será exibida
        quant_de_provas =  0;

    }else if (alunos[i].p2 < 0) {          // checando se a p2 foi aplicada, se não tiver sido aplicada, automaticamente a p3 também não foi
    
        alunos[i].media = alunos[i].p1;  // a média do alunos[i] será apenas a nota da primeira prova
        quant_de_provas = 1;            // apenas uma prova foi aplicada, a p1  

    } else {                          // se a p2 foi aplicada então a única não aplicada foi a p3

        alunos[i].media = (alunos[i].p1 + alunos[i].p2) / 2;  // a média será calculada apenas pelas duas primeiras notas
        quant_de_provas = 2;                                 // duas provas foram aplicadas
    }


    //mensagem ao entrar na página de consulta das notas
    printf("\n\t----- Avaliação do aluno %s -----\n\n", alunos[i].nome); 

    //checando quantas provas foram feitas para exibir as médias
    switch(quant_de_provas) {

        case 3:  //se as três provas foram aplicadas

        printf("Primeira prova: %.2f\n", alunos[i].p1);
        printf("Segunda prova:  %.2f\n", alunos[i].p2);
        printf("Terceira prova: %.2f\n", alunos[i].p3);
        printf("\nMédia final:    %.2f\n", alunos[i].media);

        break;

        case 2: //se apenas duas foram aplicadas
        
        printf("Primeira prova: %.2f\n", alunos[i].p1);
        printf("Segunda prova:  %.2f\n", alunos[i].p2);
        printf("Terceira prova: Não aplicada\n");
        printf("\nMédia parcial:    %.2f\n", alunos[i].media);

        break;

        case 1: //se apenas uma foi aplicada
        
        printf("Primeira prova: %.2f\n", alunos[i].p1);
        printf("Segunda prova:  Não aplicada\n");
        printf("Terceira prova: Não aplicada\n");
        printf("\nMédia parcial:    %.2f\n", alunos[i].media);

        break;

        case 0: //se nenhuma prova foi aplicada ainda

        printf("Nenhuma prova foi aplicada ainda\n");
        printf("\nMédia parcial será disponibilizada após a aplicação da primeira prova\n");

        break;

        default:

        //se a quantidade de provas não for um número entre 0 e 3, há algum problema de lógica
        //essa opção provavelmente será removida na versão final 
        printf("Um erro foi detectado"); 

    }
}