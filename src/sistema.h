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

//funcoes iniciais//
int  tela_de_inicio();
int  login_professor();

//funcoes de menu//
void menu();
void voltarAoMenu();

//funcoes de limpeza//
void limpa_tela();
void limparBuffer();

//funcoes de matricula//
int  matriculaExiste(int matricula);
int  gerarMatricula();
int  digitarMatricula();

//funcoes de busca//
int  buscarPorMatricula(int matricula);
void buscarAluno();

//funcoes de cadastro//
void cadastrarAluno();
void cadastro_notas();

//funcoes gerais de aluno//
void listarAlunos();
void editarAluno();
void removerAluno();

//funcoes de media//
void calcular_media(int i);
void classificacao(int i);

//funcoes de relatorio//
void relatorio();
void boletimCSV();
void relatorioBoletim();

//funcoes de arquivo//
void salvarDadosEmArquivo();
void carregarDadosDoArquivo();

#endif // SISTEMA_H
