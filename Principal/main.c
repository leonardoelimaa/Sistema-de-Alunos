#include <stdio.h>

char acessos_professor_cadastrados [4][2][30] = {
    {"leonardoelima", "senhaleonardo"},
    {"pedrobrito", "senhapedro"},
    {"danilopimentel", "senhadanilo"},
    {"joaopaulo", "senhajoao"}
};
char usuario_professor[30];
char senha_professor[30];


int tela_de_inicio();
int login_professor();


int main () {
    int retorno_acesso = tela_de_inicio(); // Atualmente retornando 2
    int retorno_login; // Atualmente retornando 2

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
            printf("Codigo ta funcionando");
            break;
    }  
}
