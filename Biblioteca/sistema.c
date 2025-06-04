// ===== DEFINICOES ===== //

#include "sistema.h"            //cabeçalho da biblioteca do projeto

Aluno alunos[MAX_ALUNOS];     // Array de alunos baseado no struct criado

int totalAlunos = 0;        //número inicial de alunos

//Defindo uma matriz multidimensional que armazena as credenciais dos professores
char acessos_professor_cadastrados [5][2][30] = {
    {"leonardolima", "senhaleonardo"},
    {"pedrobrito", "senhapedro"},
    {"danilopimentel", "senhadanilo"},
    {"joaopaulo", "senhajoao"},
    {"lucassantana", "senhalucas"}
};


// ===== FUNCOES INICIAIS ===== //


//Função responsável pela tela de início do programa 
int tela_de_inicio() {
    
    char acesso = '0';

    printf ("\n----- Bem-vindo ao EduC, a maior plataforma de gestao de alunos do Brasil! -----\n\n");
    
    while (acesso != '1' && acesso != '2') {   //o loop se repete até que algum dos comandos básicos seja digitado pelo usuário
        printf("Para acessar nosso sistema: \n\n");
        printf("*Digite 1 para conectar-se ao sistema\n");
        printf("*Digite 2 para sair do sistema\n\n");

        printf("Escolha uma opcao: ");
        scanf(" %c", &acesso);

        if (acesso == '1') {
            return 1;                     // Na main, o retorno 1 ira direcionar para a pagina de login
        } else if (acesso == '2') {
            return 2;                   // Na main, o retorno 2 ira retornar 0, saindo do sistema
        } else {
            printf("\nCaractere digitado invalido! Selecione um caracter valido a seguir: \n\n");
        }
    }

    return 0; // retorno padrão, mas não é usado
}

//Função que solicita e verifica o login do professor
int login_professor () {

    printf("\nPara conectar-se ao sistema, insira seu nome de usuario e senha, respectivamente, a seguir:\n\n");

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
            printf("Saindo do sistema...\n");
            return 2; // Na main, o retorno de 2 sai do sistema
        }
    }
}


// ===== FUNCOES DE MENU ===== //


//Função de menu
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

//Função para perguntar se deseja voltar ao menu
void voltarAoMenu() {
    printf("\nDeseja voltar ao menu principal? (1 - Sim / 0 - Nao): ");
    int opcao;
    scanf("%d", &opcao);
    limparBuffer();
    limpa_tela();
    
    if (opcao == 0) {
        salvarDadosEmArquivo();
        printf("Saindo do sistema...\n");
        exit(0);
    }
}


// ===== FUNCOES DE LIMPEZA ===== //


//Função para limpar a tela do termial, chamada quando entra no programa, ou quando retorna ao menu principal
void limpa_tela() {
    #ifdef _WIN32
        system("cls");      //opcao para sistemas windows
    #else
        system("clear");   //opcao para sistemas linux 
    #endif
}

//Funçaõ que remove o '\n', caracter que pode cabar sendo armazenado e lido de forma errônea por outros trecho do código
void limparBuffer() {
    while (getchar() != '\n');
}


// ==== FUNCOES DE MATRICULA ==== //


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

// Função para padrozinar a entrada do usuário ao digitar a matrícula
int digitarMatricula() {

    int matricula;
    printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);
    limparBuffer();
        
    int pos = buscarPorMatricula(matricula);

    if (pos == -1) printf("\nAluno nao encontrado.\n");

    return pos;
}


// ==== FUNCOES DE BUSCA ==== //


// Função que busca por meio da matrícula
int buscarPorMatricula(int matricula) {
    for (int i = 0; i < totalAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            return i;
        }
    }
    return -1;
}

//Função de busca completa, por matrícula e por nome
void buscarAluno() {

    int opcao;
    printf("\n--- Buscar Aluno ---\n");
    printf("1. Por matricula\n");
    printf("2. Por nome\n");
    printf("0. Voltar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    limparBuffer();
    
    if (opcao == 1) {
        
        int pos = digitarMatricula(); //usa a funçaõ digitarMatricula() para escrever encontrar a posição

        if (pos != -1) {
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
            printf("\nNenhum aluno encontrado com esse nome.\n");
        }
    } else if (opcao == 0) return;
        
    else printf("Opcao invalida.\n");
}


// ==== FUNCOES DE CADASTRO ==== //


// Função que irá cadastrar o aluno
void cadastrarAluno() {
    if (totalAlunos >= MAX_ALUNOS) {
        printf("Limite de alunos atingido!\n");
        return;
    }

    Aluno novoAluno;    //variavel temporária do tipo Aluno usada para fazer o cadastro
    
    printf("\n--- Cadastro de Aluno ---\n");
    printf("Nome completo: ");
    fgets(novoAluno.nome, MAX_NOME, stdin);
    novoAluno.nome[strcspn(novoAluno.nome, "\n")] = '\0';   //substitui o '\n' por '\0'
    
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
    
    //Inicializando a primeira nota como -1 para denotar que ainda não foram registradas as notas do aluno
    novoAluno.notas[0] = -1;

    alunos[totalAlunos] = novoAluno;
    totalAlunos++;
    
    printf("Aluno cadastrado com sucesso!\n");
    
}

//Função que cadastra as notas
void cadastro_notas() {
    int opcao;
    printf("\n--- Cadastro de notas ---\n");
    printf("1. Cadastrar notas\n");
    printf("2. Ver notas cadastradas\n");
    printf("0. Voltar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    limparBuffer();

    if (opcao == 1) {
        
        int pos = digitarMatricula(); //usando digitarMatricula para pedir a entrada do usuário

        if (pos == -1) return;      // retorna de a matricula não for achada
            
        else {
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

    else if (opcao == 2) {
        
        int pos = digitarMatricula();   // usando digitarMatricula para pedir a entrada do usuário

        if (pos == -1) return;        // retorna de a matricula não for achada
         
        //checando se as notas do aluno já foram cadastradas para que sejam exibidas
        else if(alunos[pos].notas[0] != -1){
            printf("\nAluno encontrado: %s\n", alunos[pos].nome);

            printf("\n--- Notas do aluno ---\n");
            printf("Prova 1: %.2f\n", alunos[pos].notas[0]);
            printf("Prova 2: %.2f\n", alunos[pos].notas[1]);
            printf("Prova 3: %.2f\n\n", alunos[pos].notas[2]);
            printf("Media: %.2f\n\n", alunos[pos].media);
            printf("Status: %s\n", alunos[pos].status);

        }else {

            printf("\n--- Notas do aluno ---\n");
            printf("\nAs notas deste aluno ainda nao foram cadastradas\n");
        }
    }

    if (opcao == 0) return;

}


// ==== FUNCOES GERAIS DE ALUNO ==== //


// Função que lista todos os alunos
void listarAlunos() {
    if (totalAlunos == 0) {
        printf("\nNenhum aluno cadastrado.\n");
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

//Função que edita os dados dos alunos depois de já criados
void editarAluno() {
    int opcao;

    printf("\n--- Editar Aluno ---\n");
    
    int pos = digitarMatricula();   // usando digitarMatricula para pedir a entrada do usuário

    if (pos == -1) return;        // retorna se nao for encontrada a matricula
        
    printf("\nEditando aluno: %s\n", alunos[pos].nome);
    printf("\n-- O que deseja editar ? --\n");


    printf("1. Nome\n");
    printf("2. Curso\n");
    printf("3. Observacoes\n");
    printf("0. Voltar\n");
    printf("Escolha uma opcao: ");
    
    do {

        scanf("%d", &opcao); //escolhendo uma opção
        limparBuffer();

        switch(opcao) {   

            case 1: //editando apenas o nome do aluno

                printf("\nNovo nome (atual: %s): ", alunos[pos].nome);
                fgets(alunos[pos].nome, MAX_NOME, stdin);
                alunos[pos].nome[strcspn(alunos[pos].nome, "\n")] = '\0';
                break;
        
            case 2: //editando apenas o curso do aluno

                printf("\nNovo curso (atual: %s): ", alunos[pos].curso);
                fgets(alunos[pos].curso, MAX_CURSO, stdin);
                alunos[pos].curso[strcspn(alunos[pos].curso, "\n")] = '\0';
                break;
            
            case 3: //editando apenas as observações

                printf("\nNovas observacoes (atual: %s): ", alunos[pos].observacoes);
                fgets(alunos[pos].observacoes, MAX_OBS, stdin);
                alunos[pos].observacoes[strcspn(alunos[pos].observacoes, "\n")] = '\0';
                break;
            
            case 0: //retornando para a main, que ira chamar a função voltarAoMenu()

                return;
            
            default: //se for digitada uma opção invalida imprime essa mensagem na tela

                printf("\nOpcao invalida, digite novamente:");
        }

    }while(opcao > 3 || opcao < 0); // checa se a opção está entre 0 e 3, se não é inválida e recomeça o loop

        printf("Aluno atualizado com sucesso!\n");
}

//Função que remove o registro de um aluno
void removerAluno() {
   
    printf("\n--- Remover Aluno ---\n");
    
    int pos = digitarMatricula();   // usando digitarMatricula() para pedir a entrada do usuário

    if (pos == -1) return;        // retorna se a matricula não for encontrada
    
    printf("\nRemovendo aluno: %s\n", alunos[pos].nome);
    
    // sobe os alunos uma posicao quando algum e excluido
    for (int i = pos; i < totalAlunos - 1; i++) {
        alunos[i] = alunos[i + 1];
    }
    
    totalAlunos--;
    printf("Aluno removido com sucesso!\n");
}


// ==== FUNCOES DE MEDIA ==== //


// Função que irá calcular a média
void calcular_media(int i) {
    if (alunos[i].notas[0] >= 0 && alunos[i].notas[1] >= 0 && alunos[i].notas[2] >= 0) {
        alunos[i].media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2]) / 3.0;
    }
}

// Função de classificação 
void classificacao(int i) {
    if (alunos[i].media >= 6) {
        strcpy(alunos[i].status, "Aprovado");
    } else {
        strcpy(alunos[i].status, "Reprovado");
    }
}


// ==== FUNCOES DE RELATORIO ==== //


//Função que imprime um relatório acerca dos aprovados e reprovados da turma
void relatorio() {
    int aprovados = 0;
    int reprovados = 0;
    
    printf("---- Relatorio da turma ----\n\n");
    
    for (int i = 0; i < totalAlunos; i++) {

        if (alunos[i].matricula != 0) 
            printf("Aluno: %s | Media: %lf | Status: %s", alunos[i].nome, alunos[i].media, alunos[i].status);
        
        if (strcmp(alunos[i].status, "Aprovado") == 0) aprovados++;

        else if (strcmp(alunos[i].status, "Reprovado") == 0) reprovados++;
        
    }

    printf("\nTotal de aprovados: %d\n", aprovados);
    printf("Total de reprovados: %d\n", reprovados);
}

//Função que gera um arquivo contendo o relatório
void boletimCSV() {

    FILE *arquivo;
    arquivo = fopen("relatorio.csv", "w");

    if (arquivo == NULL) {
        printf("\nERRO: Nao foi possivel carregar o boletim, tente novamente!");
        return;
    }

    fprintf(arquivo, "Nome,Prova1,Prova2,Prova3,Media,Status\n"); // CSV eh uma tabela, separada por virgula e sem espaco!

    for (int i = 0; i < totalAlunos; i++) {

        if (alunos[i].matricula != 0)
        fprintf(arquivo, "%s,%.2lf,%.2lf,%.2lf,%.2lf,%s\n", alunos[i].nome, alunos[i].notas[0], alunos[i].notas[1], alunos[i].notas[2], alunos[i].media, alunos[i].status);

    }

    fclose(arquivo);
    printf("\nBoletim criado com sucesso!");
}

//Função de submenu para gerar o relatório da turma (chama relatorio() ou boletimCSV() dependendo da opção)
void relatorioBoletim() {
    int opcao;
    printf("\n--- Relatorio e Boletim ---\n");
    printf("1. Exibir relatorio da turma\n");
    printf("2. Criar uma tabela boletim do relatorio da turma\n");
    printf("0. Voltar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    limparBuffer();

    if (opcao == 1) relatorio();
        
    else if (opcao == 2) boletimCSV();
        
    else if (opcao == 0) return;
        
}


// ==== FUNCOES DE ARQUIVO ==== //


//Função para o salvamento dos dados em um arquivo binário
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

//Função para a leitura(e cópia em memória) dos dados em um arquivo binário
void carregarDadosDoArquivo() {
    FILE *arquivo = fopen("alunos.bin", "rb"); // abre para leitura binária
    if (arquivo == NULL) {
        printf("\nNenhum dado anterior encontrado.\n");
        return;
    }

    fread(&totalAlunos, sizeof(int), 1, arquivo); // lê o total de alunos no arquivo e faz copia local
    fread(alunos, sizeof(Aluno), totalAlunos, arquivo); // lê os dados dos alunos e salva em copia local

    fclose(arquivo);
    printf("Dados carregados com sucesso!\n");
}