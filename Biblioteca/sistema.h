#ifndef SISTEMA_H
#define SISTEMA_H

// ==== BIBLIOTECAS ====
#include <stdio.h>         // Biblioteca padrão de entrada e saída
#include <stdlib.h>       // Biblioteca de funções de uso comum
#include <string.h>      // Biblioteca de strings
#include <ctype.h>      // Biblioteca para manipular caracteres
#include <time.h>      // Biblioteca para usar funções relacionadas ao tempo

// ==== CONSTANTES ====

#define MAX_ALUNOS 100   // Constante do número de alunos
#define MAX_NOME 100    // Constante do número máximo de caracteres de um nome
#define MAX_CURSO 50   // Constante do número máximo de caracteres do nome do curso
#define MAX_OBS 200   // Costante que define o tamanho máximo das observações
#define MAX_NOTAS 3  // Constante que define o número de notas a serem cadastradas

// ==== STRUCT ====

typedef struct {
    char  nome[MAX_NOME];
    int   matricula;
    char  curso[MAX_CURSO];
    char  observacoes[MAX_OBS];
    float media;
    float notas[MAX_NOTAS];
    char status[10];
} Aluno;

// ==== PROTOTIPOS DAS FUNCOES ====

int  tela_de_inicio();
void limpa_tela();
int  login_professor();
int  menu_iniciar();
void media(int i);
void classificacao(int i);
void classificacao();
void limparBuffer();
int  matriculaExiste(int matricula);
int  gerarMatricula();
void cadastrarAluno();
void listarAlunos();
int  buscarPorMatricula(int matricula);
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
