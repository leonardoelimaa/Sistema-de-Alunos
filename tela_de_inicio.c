int tela_de_inicio () {
    
    char acesso = '0';

    printf ("\n----- Bem-vindo ao EduC, a maior plataforma de gestao de alunos do Brasil! -----\n\n");
    
    while (acesso != '1' && acesso != '2') {
        printf("Para acessar nosso sistema: \n\n");
        printf("*Digite 1 para conectar-se como aluno\n");
        printf("*Digite 2 para conectar-se como professor\n\n");

        scanf(" %c", &acesso);

        if (acesso == '1') {
            return 1; // Na main, o retorno 1 ira direcionar para o aluno
        } else if (acesso == '2') {
            return 2; // Na main, o retorno 2 ira direcionar para o aluno
        } else {
            printf("\nCaractere digitado invalido! Selecione um caracter valido a seguir: \n\n");
        }
    }
}

