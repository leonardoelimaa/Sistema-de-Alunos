#include "sistema.h"  //cabeçalho da biblioteca do projeto

Aluno alunos[MAX_ALUNOS]; // Array de alunos baseado no struct criado

int totalAlunos = 0; //número inicial de alunos

//defindo uma matriz multidimensional que armazena as credenciais dos professores
char acessos_professor_cadastrados [5][2][30] = {
    {"leonardolima", "senhaleonardo"},
    {"pedrobrito", "senhapedro"},
    {"danilopimentel", "senhadanilo"},
    {"joaopaulo", "senhajoao"},
    {"lucassantana", "senhalucas"}
};
char usuario_professor[30];
char senha_professor[30];

// Funcoes: 

//função responsável pela tela de início do programa 
int tela_de_inicio() {
    
    char acesso = '0';

    printf ("\n----- Bem-vindo ao EduC, a maior plataforma de gestao de alunos do Brasil! -----\n\n");
    
    while (acesso != '1' && acesso != '2') {   //o loop se repete até que algum dos comandos básicos seja digitado pelo usuário
        printf("Para acessar nosso sistema: \n\n");
        printf("*Digite 1 para conectar-se ao sistema\n");
        printf("*Digite 2 para sair do sistema\n\n");

        scanf(" %c", &acesso);

        if (acesso == '1') {
            return 1;                     // Na main, o retorno 1 ira direcionar para a pagina de login
        } else if (acesso == '2') {
            return 2;                   // Na main, o retorno 2 ira retorna 0, saindo do sistema
        } else {
            printf("\nCaractere digitado invalido! Selecione um caracter valido a seguir: \n\n");
        }
    }

    return 0; // retorno padrão, mas não é usado
}

//função que solicita e verifica o login do professor
int login_professor () {

    printf("Para conectar-se ao sistema, insira seu nome de usuario e senha, respectivamente, a seguir:\n\n");

    while(1) {
        int opcao;
        char tentativa_login[2][30];    //essa variável será usada para testar se as entradas batem com os professores cadastrados

        printf("Nome de usuario: "); scanf("%s", tentativa_login[0]);
        printf("Senha: "); scanf("%s", tentativa_login[1]);

        //essa operação identifica o números de professores cadastrados
        int numero_de_usuarios = sizeof(acessos_professor_cadastrados) / sizeof(acessos_professor_cadastrados[0]);

        //checa um por um se a tentativa de login bate com algum professor cadastrado
        for (int i = 0; i < numero_de_usuarios; i++) {
            if (strcmp(tentativa_login[0], acessos_professor_cadastrados[i][0]) == 0 && 
                strcmp(tentativa_login[1], acessos_professor_cadastrados[i][1]) == 0) {
                return 1; // Na main, o retorno de 1 libera o usuario
            } 
        } 
        printf("Nome de usuario/Senha invalidos!\n");
        printf("Deseja tentar novamente? (1. Sim / 0. Nao)\n");
        scanf("%d", &opcao);

        if (opcao == 0) {
            printf("Saindo do sistema...");
            return 2; // Na main, o retorno de 2 sai do sistema
        }
    }
}

//função que irá calcular a média
void calcular_media(int i) {
    if (alunos[i].p1 >= 0 && alunos[i].p2 >= 0 && alunos[i].p3 >= 0) {
        alunos[i].media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2]) / 3;
    }
}

//função de classificação 
void classificacao(int i) {
    if (alunos[i].media >= 6) {
        strcpy(alunos[i].status, "Aprovado");
    } else {
        strcpy(alunos[i].status, "Reprovado");
    }
}

//funçaõ que remove o \n, caracter que pode cabar sendo armazenado e lido de forma errônea por outros trecho do código
void limparBuffer() {
    while (getchar() != '\n');
}

// Função para verificar se a matrícula gerada já existe (é usada em gerarMatricula();)
int matriculaExiste(int matricula) {
    for (int i = 0; i < totalAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            return 1; // Verdadeiro - matrícula existe
        }
    }
    return 0; // Falso - matrícula não existe
}

// Função para gerar matrícula automática (ano atual + 5 dígitos aleatórios)
int gerarMatricula() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int ano = tm.tm_year + 1900;
    int matricula;
    int tentativas = 0;
    
    do {
        // Gera 5 dígitos aleatórios
        int randomDigits = rand() % 90000 + 10000; // Garante que terá 5 dígitos
        
        // Combina ano com dígitos aleatórios (ex: 202312345)
        matricula = ano * 100000 + randomDigits;
        
        tentativas++;
        
        // Previne loop infinito caso (improvável) de muitas colisões
        if (tentativas > 100) {
            printf("Erro: Não foi possível gerar uma matrícula única após 100 tentativas.\n");
            return -1;
        }
    } while (matriculaExiste(matricula)); // Continua até achar uma matrícula única
    
    return matricula;
}

//função que irá cadastrar o aluno
void cadastrarAluno() {
    if (totalAlunos >= MAX_ALUNOS) {
        printf("Limite de alunos atingido!\n");
        return;
    }

    Aluno novoAluno;
    
    printf("\n--- Cadastro de Aluno ---\n");
    
    printf("Nome completo: ");
    fgets(novoAluno.nome, MAX_NOME, stdin);
    novoAluno.nome[strcspn(novoAluno.nome, "\n")] = '\0';
    
    // Gera matrícula automaticamente
    novoAluno.matricula = gerarMatricula();
    if (novoAluno.matricula == -1) {
        printf("Erro ao gerar matrícula. Cadastro cancelado.\n");
        return;
    }
    printf("Numero de matricula gerado automaticamente: %d\n", novoAluno.matricula);
    
    printf("Curso: ");
    fgets(novoAluno.curso, MAX_CURSO, stdin);
    novoAluno.curso[strcspn(novoAluno.curso, "\n")] = '\0';
    
    printf("Observacoes: ");
    fgets(novoAluno.observacoes, MAX_OBS, stdin);
    novoAluno.observacoes[strcspn(novoAluno.observacoes, "\n")] = '\0';
    
    alunos[totalAlunos] = novoAluno;
    totalAlunos++;
    
    printf("Aluno cadastrado com sucesso!\n");
}

//função que lista todos os alunos
void listarAlunos() {
    if (totalAlunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }
    
    printf("\n--- Lista de Alunos ---\n");
    for (int i = 0; i < totalAlunos; i++) {
        printf("\nAluno %d:\n", i+1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Curso: %s\n", alunos[i].curso);
        printf("Observacoes: %s\n", alunos[i].observacoes);
    }
}

//função que busca por meio da matrícula
int buscarPorMatricula(int matricula) {
    for (int i = 0; i < totalAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            return i;
        }
    }
    return -1;
}

//função de busca completa, por matrícula e por nome
void buscarAluno() {
    int opcao;
    printf("\n--- Buscar Aluno ---\n");
    printf("1. Por matricula\n");
    printf("2. Por nome\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    limparBuffer();
    
    if (opcao == 1) {
        int matricula;
        printf("Digite a matricula: ");
        scanf("%d", &matricula);
        limparBuffer();
        
        int pos = buscarPorMatricula(matricula);
        if (pos == -1) {
            printf("Aluno nao encontrado.\n");
        } else {
            printf("\nAluno encontrado:\n");
            printf("Nome: %s\n", alunos[pos].nome);
            printf("Matricula: %d\n", alunos[pos].matricula);
            printf("Curso: %s\n", alunos[pos].curso);
            printf("Observacoes: %s\n", alunos[pos].observacoes);
        }
    } else if (opcao == 2) {
        char nome[MAX_NOME];
        printf("Digite o nome (ou parte): ");
        fgets(nome, MAX_NOME, stdin);
        nome[strcspn(nome, "\n")] = '\0';
        
        printf("\nResultados da busca:\n");
        int encontrados = 0;
        
        for (int i = 0; i < totalAlunos; i++) {
            if (strstr(alunos[i].nome, nome) != NULL) {
                printf("\nAluno %d:\n", i+1);
                printf("Nome: %s\n", alunos[i].nome);
                printf("Matricula: %d\n", alunos[i].matricula);
                printf("Curso: %s\n", alunos[i].curso);
                printf("Observacoes: %s\n", alunos[i].observacoes);
                encontrados++;
            }
        }
        
        if (encontrados == 0) {
            printf("Nenhum aluno encontrado com esse nome.\n");
        }
    } else {
        printf("Opcao invalida.\n");
    }
}

//função que edita os dados dos alunos depois de já criados
void editarAluno() {
    int matricula;
    printf("\n--- Editar Aluno ---\n");
    printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);
    limparBuffer();
    
    int pos = buscarPorMatricula(matricula);
    if (pos == -1) {
        printf("Aluno nao encontrado.\n");
        return;
    }
    
    printf("\nEditando aluno: %s\n", alunos[pos].nome);
    printf("Novo nome (atual: %s): ", alunos[pos].nome);
    fgets(alunos[pos].nome, MAX_NOME, stdin);
    alunos[pos].nome[strcspn(alunos[pos].nome, "\n")] = '\0';
    
    printf("Novo curso (atual: %s): ", alunos[pos].curso);
    fgets(alunos[pos].curso, MAX_CURSO, stdin);
    alunos[pos].curso[strcspn(alunos[pos].curso, "\n")] = '\0';
    
    printf("Novas observacoes (atual: %s): ", alunos[pos].observacoes);
    fgets(alunos[pos].observacoes, MAX_OBS, stdin);
    alunos[pos].observacoes[strcspn(alunos[pos].observacoes, "\n")] = '\0';
    
    printf("Aluno atualizado com sucesso!\n");
}

//função que remove o registro de um aluno
void removerAluno() {
    int matricula;
    printf("\n--- Remover Aluno ---\n");
    printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);
    limparBuffer();
    
    int pos = buscarPorMatricula(matricula);
    if (pos == -1) {
        printf("Aluno nao encontrado.\n");
        return;
    }
    
    printf("Removendo aluno: %s\n", alunos[pos].nome);
    
    // sobe os alunos uma posicao quando algum e excluido
    for (int i = pos; i < totalAlunos - 1; i++) {
        alunos[i] = alunos[i + 1];
    }
    
    totalAlunos--;
    printf("Aluno removido com sucesso!\n");
}

//função de menu
void menu() {
    printf("\n=== SISTEMA DE GESTAO DE ALUNOS ===\n");
    printf("1. Cadastrar aluno\n");
    printf("2. Listar alunos\n");
    printf("3. Buscar aluno\n");
    printf("4. Editar aluno\n");
    printf("5. Remover aluno\n");
    printf("6. Cadastro de notas\n");
    printf("7. Relatorio e Boletim\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

//função para perguntar se deseja voltar ao menu
void voltarAoMenu() {
    printf("\nDeseja voltar ao menu principal? (1 - Sim / 0 - Nao): ");
    int opcao;
    scanf("%d", &opcao);
    limparBuffer();
    
    if (opcao == 0) {
        printf("Saindo do sistema...\n");
        exit(0);
    }
}

//função que cadastra as notas
void cadastro_notas() {
    int opcao;
    printf("\n--- Cadastro de notas ---\n");
    printf("1. Cadastrar notas\n");
    printf("2. Ver notas cadastradas\n");
    printf("0. Voltar\n");
    scanf("%d", &opcao);
    limparBuffer();

    if (opcao == 1) {
        int matricula;
        printf("Escreva a matricula do aluno que voce ira registrar a nota.\n");
        scanf("%d", &matricula);
        limparBuffer();

        int pos = buscarPorMatricula(matricula);
        if (pos == -1) {
            printf("Aluno nao encontrado.\n");
        } else {
            printf("\nAluno encontrado: %s\n", alunos[pos].nome);
            
            for (int i = 0; i < 3; i++) {
                printf("Digite a nota %d.\n", (i + 1));
                scanf("%f", &alunos[pos].notas[i]);
                limparBuffer();
            }
            calcular_media(pos);
            classificacao(pos);
        }
    }

    if (opcao == 2) {
        int matricula;
        printf("Escreva a matricula do aluno que voce quer ver as notas.\n");
        scanf("%d", &matricula);
        limparBuffer();

        int pos = buscarPorMatricula(matricula);
        if (pos == -1) {
            printf("Aluno nao encontrado.\n");
        } else {
            printf("\nAluno encontrado: %s\n", alunos[pos].nome);

            printf("\n--- Notas do aluno ---\n");
            printf("Prova 1: %.2f\n", alunos[pos].notas[0]);
            printf("Prova 2: %.2f\n", alunos[pos].notas[1]);
            printf("Prova 3: %.2f\n\n", alunos[pos].notas[2]);
            printf("Media: %.2f\n\n", alunos[pos].media);
            printf("Status: %s\n", alunos[pos].status);
        }
    }

    if (opcao == 0)
        voltarAoMenu();

}

void relatorio() {
    int aprovados = 0;
    int reprovados = 0;
    
    printf("---- Relatorio da turma ----\n\n");
    
    for (int i = 0; i < totalAlunos; i++) {
        if (alunos[i].matricula != 0) {
            printf("Aluno: %s | Media: %lf | Status: %s", alunos[i].nome, alunos[i].media, alunos[i].status);
        }
        
        if (strcmp(alunos[i].status, "Aprovado") == 0) {
            aprovados++;
        } else if (strcmp(alunos[i].status, "Reprovado") == 0) {
            reprovados++;
        }
    }

    printf("\nTotal de aprovados: %d\n", aprovados);
    printf("Total de reprovados: %d\n", reprovados);
}

void boletimCSV() {
    int aprovados = 0;
    int reprovados = 0;

    FILE *arquivo;
    arquivo = fopen("relatorio.csv", "w");

    if (arquivo == NULL) {
        printf("ERRO: Nao foi possivel carregar o boletim, tente novamente!");
        return;
    }

    fprintf(arquivo, "Nome,Prova1,Prova2,Prova3,Media,Status\n"); // CSV eh uma tabela, separa por virgula sem espaco!

    for (int i = 0; i < totalAlunos; i++) {
        if (alunos[i].matricula != 0) {
            fprintf(arquivo, "%s,%.2lf,%.2lf,%.2lf,%.2lf,%s\n", alunos[i].nome, alunos[i].notas[0], alunos[i].notas[1], alunos[i].notas[2], alunos[i].media, alunos[i].status);
        }
    }

    fclose(arquivo);
}

void relatorioBoletim() {
    int opcao;
    printf("\n--- Relatorio e Boletim ---\n");
    printf("1. Exibir relatorio da turma\n");
    printf("2. Criar uma tabela boletim do relatorio da turma\n");
    printf("0. Voltar\n");
    scanf("%d", &opcao);
    limparBuffer();

    if (opcao == 1) {
        relatorio();
    } else if (opcao == 2) {
        boletimCSV();
    } else if (opcao == 0)
        voltarAoMenu();
}

void salvarDadosEmArquivo() {
    FILE *arquivo = fopen("alunos.bin", "wb"); // abre para escrita binária
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar os dados.\n");
        return;
    }

    fwrite(&totalAlunos, sizeof(int), 1, arquivo); // salva o total de alunos no arquivo binario
    fwrite(alunos, sizeof(Aluno), totalAlunos, arquivo); // salva o array de alunos no arquivo binario 

    fclose(arquivo);
    printf("Dados salvos com sucesso!\n");
}

void carregarDadosDoArquivo() {
    FILE *arquivo = fopen("alunos.bin", "rb"); // abre para leitura binária
    if (arquivo == NULL) {
        printf("Nenhum dado anterior encontrado.\n");
        return;
    }

    fread(&totalAlunos, sizeof(int), 1, arquivo); // lê o total de alunos no arquivo e faz copia local
    fread(alunos, sizeof(Aluno), totalAlunos, arquivo); // lê os dados dos alunos e salva em copia local

    fclose(arquivo);
    printf("Dados carregados com sucesso!\n");
}