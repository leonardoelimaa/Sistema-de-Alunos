#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "sistema.h"


char acessos_professor_cadastrados [5][2][30] = {
    {"leonardolima", "senhaleonardo"},
    {"pedrobrito", "senhapedro"},
    {"danilopimentel", "senhadanilo"},
    {"joaopaulo", "senhajoao"},
    {"lucassantana", "senhalucas"}
};
char usuario_professor[30];
char senha_professor[30];

int tela_de_inicio() {
    
    char acesso = '0';

    printf ("\n----- Bem-vindo ao EduC, a maior plataforma de gestao de alunos do Brasil! -----\n\n");
    
    while (acesso != '1' && acesso != '2' && acesso != '3') {
        printf("Para acessar nosso sistema: \n\n");
        printf("*Digite 1 para conectar-se como aluno\n");
        printf("*Digite 2 para conectar-se como professor\n");
        printf("*Digite 3 para sair do sistema\n\n");

        scanf(" %c", &acesso);

        if (acesso == '1') {
            return 1; // Na main, o retorno 1 ira direcionar para o aluno
        } else if (acesso == '2') {
            return 2; // Na main, o retorno 2 ira direcionar para o professor
        } else if (acesso == '3'){
            return 3; // Na main, o retorno 3 vai fazer a main retornar 0 e sair do programa
        } else {
            printf("\nCaractere digitado invalido! Selecione um caracter valido a seguir: \n\n");
        }
    }
}


int login_professor () {
    printf("\nVoce escolheu a opcao de acesso como professor!\n");
    printf("Para conectar-se ao sistema, insira seu nome de usuario e senha, respectivamente, a seguir:\n\n");

    while(1) {
        char tentativa_login[2][30];

        printf("Nome de usuario: "); scanf("%s", tentativa_login[0]);
        printf("Senha: "); scanf("%s", tentativa_login[1]);

        
        int numero_de_usuarios = sizeof(acessos_professor_cadastrados) / sizeof(acessos_professor_cadastrados[0]);

        for (int i = 0; i < numero_de_usuarios; i++) {
            if (strcmp(tentativa_login[0], acessos_professor_cadastrados[i][0]) == 0 && 
                strcmp(tentativa_login[1], acessos_professor_cadastrados[i][1]) == 0) {
                return 2; // Na main, o retorno de 1 libera o usuario
            } 
        } 
        printf("Nome de usuario/Senha invalidos! Tente novamente!!! \n\n");
    }
}


int menu_iniciar() {
    char opcao_menu_inicial;
    
    printf("\n\nBem-vindo ao menu inicial!!!\n\n");

    printf("*Digite 1 para buscar estudantes cadastrados\n");
    printf("*Digite 2 para cadastrar estudantes\n");
    printf("*Digite 3 para cadastrar notas dos estudantes\n");
    printf("*Digite 4 para incluir observacoes dos estudantes\n");
    printf("*Digite 5 para gerar relatorios de desempenho da turma\n\n");

    scanf(" %c", &opcao_menu_inicial);

    switch (opcao_menu_inicial) {
        case '1': 
            return 1; // Na main, permite buscar estudantes.
            break; 
        case '2': 
            return 2; // Na main, permite cadastrar estudantes.
            break;
        case '3': 
            return 3; // Na main, permite cadastrar notas de estudantes.
            break;
        case '4': 
            return 4; // Na main, permite incluir observacoes de estudantes.
            break;
        case '5': 
            return 5; // Na main, permite gerar relatorios de estudantes.
    }
}



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
// Fim

int classificacao() {
    char usuario_aluno[40];
    float media;

    if (media >= 6) {
        printf("O aluno %s, com %.2f de média, foi aprovado!", usuario_aluno, media);
    } else {
        printf("O aluno %s, com %.2f de média, foi reprovado.", usuario_aluno, media);
    }
}


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
int totalAlunos = 0;

void limparBuffer() {
    while (getchar() != '\n');
}

void cadastrarAluno() {
    if (totalAlunos >= MAX_ALUNOS) {
        printf("Limite de alunos atingido!\n");
        return;
    }

    Aluno novoAluno;
    
    printf("\n--- Cadastro de Aluno ---\n");
    
    printf("Nome completo: ");
    fgets(novoAluno.nome, MAX_NOME, stdin);
    novoAluno.nome[strcspn(novoAluno.nome, "\n")] = '\0';
    
    printf("Numero de matricula: ");
    scanf("%d", &novoAluno.matricula);
    limparBuffer();
    
    // Verificar se tem matricula repetida
    for (int i = 0; i < totalAlunos; i++) {
        if (alunos[i].matricula == novoAluno.matricula) {
            printf("Erro: Matricula ja existe!\n");
            return;
        }
    }
    
    printf("Curso: ");
    fgets(novoAluno.curso, MAX_CURSO, stdin);
    novoAluno.curso[strcspn(novoAluno.curso, "\n")] = '\0';
    
    printf("Observacoes: ");
    fgets(novoAluno.observacoes, MAX_OBS, stdin);
    novoAluno.observacoes[strcspn(novoAluno.observacoes, "\n")] = '\0';
    
    alunos[totalAlunos] = novoAluno;
    totalAlunos++;
    
    printf("Aluno cadastrado com sucesso!\n");
}

void listarAlunos() {
    if (totalAlunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }
    
    printf("\n--- Lista de Alunos ---\n");
    for (int i = 0; i < totalAlunos; i++) {
        printf("\nAluno %d:\n", i+1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Curso: %s\n", alunos[i].curso);
        printf("Observacoes: %s\n", alunos[i].observacoes);
    }
}

int buscarPorMatricula(int matricula) {
    for (int i = 0; i < totalAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            return i;
        }
    }
    return -1;
}

void buscarAluno() {
    int opcao;
    printf("\n--- Buscar Aluno ---\n");
    printf("1. Por matricula\n");
    printf("2. Por nome\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    limparBuffer();
    
    if (opcao == 1) {
        int matricula;
        printf("Digite a matricula: ");
        scanf("%d", &matricula);
        limparBuffer();
        
        int pos = buscarPorMatricula(matricula);
        if (pos == -1) {
            printf("Aluno nao encontrado.\n");
        } else {
            printf("\nAluno encontrado:\n");
            printf("Nome: %s\n", alunos[pos].nome);
            printf("Matricula: %d\n", alunos[pos].matricula);
            printf("Curso: %s\n", alunos[pos].curso);
            printf("Observacoes: %s\n", alunos[pos].observacoes);
        }
    } else if (opcao == 2) {
        char nome[MAX_NOME];
        printf("Digite o nome (ou parte): ");
        fgets(nome, MAX_NOME, stdin);
        nome[strcspn(nome, "\n")] = '\0';
        
        printf("\nResultados da busca:\n");
        int encontrados = 0;
        
        for (int i = 0; i < totalAlunos; i++) {
            if (strstr(alunos[i].nome, nome) != NULL) {
                printf("\nAluno %d:\n", i+1);
                printf("Nome: %s\n", alunos[i].nome);
                printf("Matricula: %d\n", alunos[i].matricula);
                printf("Curso: %s\n", alunos[i].curso);
                printf("Observacoes: %s\n", alunos[i].observacoes);
                encontrados++;
            }
        }
        
        if (encontrados == 0) {
            printf("Nenhum aluno encontrado com esse nome.\n");
        }
    } else {
        printf("Opcao invalida.\n");
    }
}

void editarAluno() {
    int matricula;
    printf("\n--- Editar Aluno ---\n");
    printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);
    limparBuffer();
    
    int pos = buscarPorMatricula(matricula);
    if (pos == -1) {
        printf("Aluno nao encontrado.\n");
        return;
    }
    
    printf("\nEditando aluno: %s\n", alunos[pos].nome);
    printf("Novo nome (atual: %s): ", alunos[pos].nome);
    fgets(alunos[pos].nome, MAX_NOME, stdin);
    alunos[pos].nome[strcspn(alunos[pos].nome, "\n")] = '\0';
    
    printf("Novo curso (atual: %s): ", alunos[pos].curso);
    fgets(alunos[pos].curso, MAX_CURSO, stdin);
    alunos[pos].curso[strcspn(alunos[pos].curso, "\n")] = '\0';
    
    printf("Novas observacoes (atual: %s): ", alunos[pos].observacoes);
    fgets(alunos[pos].observacoes, MAX_OBS, stdin);
    alunos[pos].observacoes[strcspn(alunos[pos].observacoes, "\n")] = '\0';
    
    printf("Aluno atualizado com sucesso!\n");
}

void removerAluno() {
    int matricula;
    printf("\n--- Remover Aluno ---\n");
    printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);
    limparBuffer();
    
    int pos = buscarPorMatricula(matricula);
    if (pos == -1) {
        printf("Aluno nao encontrado.\n");
        return;
    }
    
    printf("Removendo aluno: %s\n", alunos[pos].nome);
    
    // sobe os alunos uma posicao quando algum e excluido
    for (int i = pos; i < totalAlunos - 1; i++) {
        alunos[i] = alunos[i + 1];
    }
    
    totalAlunos--;
    printf("Aluno removido com sucesso!\n");
}

void menu() {
    printf("\n=== SISTEMA DE GESTAO DE ALUNOS ===\n");
    printf("1. Cadastrar aluno\n");
    printf("2. Listar alunos\n");
    printf("3. Buscar aluno\n");
    printf("4. Editar aluno\n");
    printf("5. Remover aluno\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}
