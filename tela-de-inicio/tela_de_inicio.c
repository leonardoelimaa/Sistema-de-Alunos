#include <stdio.h>

int tela_inicio_professor() {
    char opcao_menu_inicial;
    
    printf("Bem-vindo ao menu inicial!!!\n\n");

    printf("*Digite 1 para buscar estudantes cadastrados\n");
    printf("*Digite 2 para cadastrar estudantes\n");
    printf("*Digite 3 para cadastrar notas dos estudantes\n");
    printf("*Digite 4 para incluir observacoes dos estudantes\n");
    printf("*Digite 5 para gerar relatorios de desempenho da turma\n\n");

    scanf("%c", &opcao_menu_inicial);

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
            break;
    }
}
