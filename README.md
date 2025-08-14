<h1 align="center" style="color:#2E86C1;"> Sistema de Gestão de Alunos</h1> <p align="center"> <img src="https://img.shields.io/badge/license-GNU%20GPL%20v2-brightgreen.svg"> <img src="https://img.shields.io/badge/status-desenvolvido-brightgreen.svg"> </p> <p align="center"> Um sistema desenvolvido por estudantes de Sistemas de Informação na Universidade Federal de Goiás (UFG) em <strong>C</strong> para gerenciar alunos, com <em>cadastro, edição, remoção, busca, registro de notas e exportação para CSV</em>. </p>
<h2 style="color:#28B463;"> Funcionalidades</h2> <ul> <li> Cadastro de alunos</li> <li> Edição e remoção de registros</li> <li> Registro e cálculo de notas</li> <li> Relatórios organizados</li> <li> Exportação de dados para <strong>CSV</strong></li> </ul>
<h2 style="color:#E67E22;"> Estrutura do Projeto</h2>
sistema-gestao-alunos/

├── src/

│   ├── main.c       // Arquivo principal que inicia o sistema

│   ├── sistema.c     // Implementa funções de gerenciamento de alunos

│   ├── sistema.h     // Cabeçalhos das funções de alunos

│   ├── alunos.bin     // Arquivo binário que garante persistência de dados

│   ├── Makefile     // Arquivo para facilitar os comandos de compilação do código


├── data/

│   ├── README.md        // Documentação completa do projeto

│    └── LICENSE          // Licença GNU GPL v2.0

<h2 style="color:#AF7AC5;"> Instalação e Execução</h2> <p> Siga os passos abaixo para clonar, compilar e executar o sistema no seu computador: </p>
// Compilar todos os arquivos C
gcc main.c sistema.c -o sistema

// Executar o programa
./sistema

<h2 style="color:#3498DB;"> Exemplo de Uso</h2>
=== Sistema de Gestão de Alunos ===
1. Cadastrar aluno

2. Editar aluno
  
3. Remover aluno
 
4. Listar alunos
   
5. Exportar para CSV
   
6. Sair
    
Escolha: 1

<h2 style="color:#F1C40F;"> Tecnologias</h2>

Linguagem: C

Compilador: GCC

Editor/IDE: VS Code

Sistema Operacional: Windows 11

Formato de dados: CSV para exportação de informações e bin para persistência de dados

<h2 style="color:#C0392B;"> Licença</h2> <p> Este projeto está licenciado sob a <strong>GNU General Public License v2.0 (GPL-2.0)</strong>. Isso significa que qualquer pessoa pode usar, estudar e modificar o código livremente, **desde que as versões redistribuídas permaneçam GPL** e mantenham créditos ao autor original. </p>

Leia o arquivo LICENSE para mais detalhes.

<h2 style="color:#8E44AD;"> Autor</h2>

Leonardo Lima e Silva
[GitHub](https://github.com/leonardoelimaa) | [LinkedIn](www.linkedin.com/in/leonardo-lima-43bb62241) 

Pedro Ferreira de Brito
[GitHub](https://github.com/pedrofb7)

Lucas Santana Dalla Déa
[GitHub](https://github.com/dalladea)

Danilo Oliveira Pimentel 
[GitHub](https://github.com/DanTechOliveira)

João Paulo de Souza Rosa
[GitHub](https://github.com/N1GHTM4R3939)

