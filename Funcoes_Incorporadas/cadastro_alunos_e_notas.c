#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALUNOS 100
#define MAX_NOME 100
#define MAX_CURSO 50
#define MAX_OBS 200
#define MAX_NOTAS 3

typedef struct {
    char nome[MAX_NOME];
    int matricula;
    char curso[MAX_CURSO];
    char observacoes[MAX_OBS];
    float notas[MAX_NOTAS];
} Aluno;

Aluno alunos[MAX_ALUNOS]; // Criação de um vetor de structs
int totalAlunos = 0;

void limparBuffer() {
    while (getchar() != '\n');
}

// Função para verificar se a matrícula já existe
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

int buscarPorMatricula(int matricula) {
    for (int i = 0; i < totalAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            return i;
        }
    }
    return -1;
}

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
    
    // Move os alunos uma posição para frente quando algum é excluído
    for (int i = pos; i < totalAlunos - 1; i++) {
        alunos[i] = alunos[i + 1];
    }
    
    totalAlunos--;
    printf("Aluno removido com sucesso!\n");
}

// Função para perguntar se deseja voltar ao menu
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

void menu() {
    printf("\n=== SISTEMA DE GESTAO DE ALUNOS ===\n");
    printf("1. Cadastrar aluno\n");
    printf("2. Listar alunos\n");
    printf("3. Buscar aluno\n");
    printf("4. Editar aluno\n");
    printf("5. Remover aluno\n");
    printf("6. Cadastro de notas\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

void cadastro_notas()
{
    int opcao;
    printf("\n--- Cadastro de notas ---\n");
    printf("1. Cadastrar notas\n");
    printf("2. Ver notas cadastradas\n");
    printf("0. Voltar\n");
    scanf("%d", &opcao);
    limparBuffer();

    if(opcao == 1)
    {
        int matricula;
        printf("Escreva a matricula do aluno que voce ira registrar a nota.\n");
        scanf("%d", &matricula);
        limparBuffer();

        int pos = buscarPorMatricula(matricula);
        if (pos == -1) {
            printf("Aluno nao encontrado.\n");
        } else {
            printf("\nAluno encontrado: %s\n", alunos[pos].nome);
            
            for(int i = 0; i < 3; i++)
            {
                printf("Digite a nota %d.\n", (i + 1));
                scanf("%f", &alunos[pos].notas[i]);
                limparBuffer();
            }
            }
    }

    if(opcao == 2)
    {
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
        }
    }

    if(opcao == 0)
        voltarAoMenu();

}


int main() {
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