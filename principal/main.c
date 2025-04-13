#include <stdio.h>
#include <stdlib.h>


int tela_de_inicio();
int login_professor();
int login_professor();
int menu_iniciar();


int main () {
    system("cls");
    
    int retorno_acesso = tela_de_inicio(); // Atualmente retornando 2
    int retorno_login; // Atualmente retornando 
    int retorno_menu; 

    switch (retorno_acesso) {
        case 1: 
            printf("Login aluno, ainda a ser criado!");
            break;
        case 2:
            retorno_login = login_professor();
            break;
        case 3:
            return 0;
    }

    switch (retorno_login) {
        case 1:
            printf("Pagina de aluno ainda nao criada!");
            break;
        case 2:           
            retorno_menu = menu_iniciar();
            break;
    }  

    switch (retorno_menu) {
        case 1:
            printf("Buscar estudantes ainda nao criado");
            break;
        case 2:           
            printf("Cadastro de estudantes ainda nao criado!");
            break;
        case 3:           
            printf("Cadastro de notas ainda nao criado!");
            break;
        case 4:           
            printf("Opcao de observacoes ainda nao criado!");
            break;
        case 5:           
            printf("Opcao de relatorios ainda nao criado!");
            break;
        case 6:           
            return 0;
    }  
}
