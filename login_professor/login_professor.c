#include <stdio.h>
#include <string.h>

int login_professor () {
    printf("\nVoce escolheu a opcao de acesso como professor!\n");
    printf("Para conectar-se ao sistema, insira seu nome de usuario e senha, respectivamente, a seguir:\n\n");

    while(1) {
        printf("Nome de usuario: "); scanf("%s", &usuario_professor);
        printf("Senha: "); scanf("%s", &senha_professor);

        char array_verificacao[2][30];
        strcpy(array_verificacao[0], usuario_professor);
        strcpy(array_verificacao[1], senha_professor);

        int numero_de_usuarios = sizeof(acessos_professor_cadastrados) / sizeof(acessos_professor_cadastrados[0]);

        for (int i = 0; i < numero_de_usuarios; i++) {
            if (strcmp(array_verificacao, acessos_professor_cadastrados[i]) == 0) {
                return 2; // Na main, o retorno de 1 libera o usuario
            } 
        } 
        printf("Nome de usuario/Senha invalidos! Tente novamente!!! \n\n");
    }
}
