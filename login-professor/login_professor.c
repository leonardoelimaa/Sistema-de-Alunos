#include <stdio.h>
#include <string.h>


char acessos_professor_cadastrados [4][2][30] = {
    {"leonardoelima", "senhaleonardo"},
    {"pedrobrito", "senhapedro"},
    {"danilopimentel", "senhadanilo"},
    {"joaopaulo", "senhajoao"}
};
char usuario_professor[30];
char senha_professor[30];


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
