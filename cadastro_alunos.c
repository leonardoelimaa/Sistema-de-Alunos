#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 100
#define MAX_NOME 100
#define MAX_CURSO 50
#define MAX_OBS 200

typedef struct {
    char nome[MAX_NOME];
    int matricula;
    char curso[MAX_CURSO];
    char observacoes[MAX_OBS];
} Aluno;

Aluno alunos[MAX_ALUNOS]; // Criacao de um vetor de structs
int totalAlunos = 0;

void limparBuffer() {
    while (getchar() != '\n');
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
    
    printf("Numero de matricula: ");
    scanf("%d", &novoAluno.matricula);
    limparBuffer();
    
    // Verificar se tem matricula repetida
    for (int i = 0; i < totalAlunos; i++) {
        if (alunos[i].matricula == novoAluno.matricula) {
            printf("Erro: Matricula ja existe!\n");
            return;
        }
    }
    
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
    
    // sobe os alunos uma posicao quando algum e excluido
    for (int i = pos; i < totalAlunos - 1; i++) {
        alunos[i] = alunos[i + 1];
    }
    
    totalAlunos--;
    printf("Aluno removido com sucesso!\n");
}

void menu() {
    printf("\n=== SISTEMA DE GESTAO DE ALUNOS ===\n");
    printf("1. Cadastrar aluno\n");
    printf("2. Listar alunos\n");
    printf("3. Buscar aluno\n");
    printf("4. Editar aluno\n");
    printf("5. Remover aluno\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    int opcao;
    
    do {
        menu();
        scanf("%d", &opcao);
        limparBuffer();
        
        switch(opcao) {
            case 1:
                cadastrarAluno();
                break;
            case 2:
                listarAlunos();
                break;
            case 3:
                buscarAluno();
                break;
            case 4:
                editarAluno();
                break;
            case 5:
                removerAluno();
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
    
    return 0;
}
