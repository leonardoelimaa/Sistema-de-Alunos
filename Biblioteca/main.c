#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sistema.h"


int main () {
    system("cls");
    zerarMatriculas();

    int retorno_acesso = tela_de_inicio(); // Atualmente retornando 2 
    int retorno_menu; 

    switch (retorno_acesso) {
        case 1: 
            retorno_menu = login_professor();
            break;
        case 2:
            printf("Saindo do sistema...");
            return 0;
            break;
    }

    if (retorno_menu == 1) {
        // Inicializa o gerador de números aleatórios
    srand(time(NULL));
    
    int opcao;
    
    do {
        menu();
        scanf("%d", &opcao);
        limparBuffer();
        
        switch(opcao) {
            case 1:
                cadastrarAluno();
                voltarAoMenu();
                break;
            case 2:
                listarAlunos();
                voltarAoMenu();
                break;
            case 3:
                buscarAluno();
                voltarAoMenu();
                break;
            case 4:
                editarAluno();
                voltarAoMenu();
                break;
            case 5:
                removerAluno();
                voltarAoMenu();
                break;
            case 6:
                cadastro_notas();
                voltarAoMenu();
                break;
            case 7:
                relatorioBoletim();
                voltarAoMenu();
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                voltarAoMenu();
        }
    } while (opcao != 0);
    
    return 0;
    }
}  

