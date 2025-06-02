#ifndef SISTEMA_H
#define SISTEMA_H

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
void zerarMatriculas();

#endif
