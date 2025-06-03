#ifndef SISTEMA_H
#define SISTEMA_H

// ==== BIBLIOTECAS ====
#include <stdio.h>         //biblioteca padrão de entrada e saída
#include <stdlib.h>       //biblioteca de funções de uso comum
#include <string.h>      //biblioteca de strings
#include <ctype.h>      //biblioteca para manipular caracteres
#include <time.h>      //biblioteca para usar funções relacionadas ao tempo

// ==== CONSTANTES ====

#define MAX_ALUNOS 100   //constante do número de alunos
#define MAX_NOME 100    //constante do número máximo de caracteres de um nome
#define MAX_CURSO 50   //constante do número máximo de caracteres do nome do curso
#define MAX_OBS 200   //costante que define o tamanho máximo das observações
#define MAX_NOTAS 3  //constante que define o número de notas a serem cadastradas(experimental)

// ==== STRUCT ====

typedef struct {
    char  nome[MAX_NOME];
    int   matricula;
    char  curso[MAX_CURSO];
    char  observacoes[MAX_OBS];
    float p1;
    float p2;
    float p3;
    float media;
    float notas[MAX_NOTAS]; //experimental
    char status[10];
} Aluno;

// ==== PROTOTIPOS DAS FUNCOES ====

int tela_de_inicio();
int login_professor();
int menu_iniciar();
void media(int i);
void classificacao(int i);
void classificacao();
void limparBuffer();
int matriculaExiste(int matricula);
int gerarMatricula();
void cadastrarAluno();
void listarAlunos();
int buscarPorMatricula(int matricula);
void buscarAluno();
void editarAluno();
void removerAluno();
void menu();
void voltarAoMenu();
void cadastro_notas();
void relatorio();
void boletimCSV();
void relatorioBoletim();
void salvarDadosEmArquivo();
void carregarDadosDoArquivo();

#endif // SISTEMA_H
