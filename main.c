/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ARQUIVO_AUTORES "Autores.txt"
#define AUTORES_TEMP "TempAut.csv"
#define ARQUIVO_USUARIOS "Usuarios.txt"
#define USUARIOS_TEMP "TempUsu.csv"
#define MAX 50
#define BUFFER_SIZE 256

    struct Autores {
        char nome[50];
        int codigoautor;
        char historautor[100];
        char idade[16];
    };
    
    struct Autores autor[MAX];
    int total_autores = 0;

    void menuAutores(void);
    void carregar_autores(void);
    void consulta_autor(void);
    void listar_autores(void);
    void ordenarcod(struct Autores *a, int total);
    void cadastrar_autor(void);
    void atualizar_autor(void);
    void excluir_autores(void);
    
    struct Usuarios {
        char nome[50];
        int matricula;
        char email[100];
        char telefone[16];
    };
    
    struct Usuarios user[MAX];
    int total_usuarios = 0;
    
    void menuUsuarios(void);
    void carregar_usuarios(void);
    void listar_usuarios(void);
    void ordenarmat(struct Usuarios *a, int total);
    void consulta_usuarios(void);
    void cadastrar_usuarios(void);
    void atualizar_usuarios(void);
    void excluir_usuarios(void);
    
int main()
{
    int opcao;
    
    carregar_autores();
    carregar_usuarios();
    
    do {    
        printf("\n\n++++++++++++++++++++++++++++++++++++++++++\n");
	    printf("SISBIB - Sistema de Gestão de Bibliotecas.\n");
	    printf("++++++++++++++++++++++++++++++++++++++++++\n\n");
	
	    printf("1 - Gestão de Livros. \n");
	    printf("2 - Gestão de Autores. \n");
	    printf("3 - Gestão de Usuários. \n");
	    printf("4 - Gestão de Empréstimos. \n");
	    printf("5 - Relatórios. \n");
	    printf("6 - Sair. \n\n");
	    printf("Escolha uma opção: ");
	    scanf("%d", &opcao); 
	    switch(opcao) {
            case 1:
                break;
            case 2:
                menuAutores();
                break;
            case 3:
                menuUsuarios();
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                printf("\nObrigado por utilizar o SISBIB!\n");
                break;
            default:
                printf("\nOpção inválida!");
                break;
	    }
    } while (opcao != 6);            

    return 0;
}

void menuAutores(void) {
    int opcao;
    
    do {
        printf("\n\n++++++++++++++++++++++++++++++++++++++++++\n");
	    printf("           Gestão de Autores.\n");
	    printf("++++++++++++++++++++++++++++++++++++++++++\n\n");
	    printf("\n1 - Consulta de autor.");
        printf("\n2 - Criar novo registro de autor.");
        printf("\n3 - Editar autor.");
        printf("\n4 - Excluir autor.");
        printf("\n5 - Imprimir lista de Autores.");
        printf("\n6 - Voltar.");
        printf("\n\nEscolha uma opção: ");
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao) {
            case 1:
                consulta_autor();
                break;
            case 2:
                cadastrar_autor();
                break;
            case 3:
                atualizar_autor();
                carregar_autores();
                break;
            case 4:
                excluir_autores();
                carregar_autores();
                break;
            case 5:
                listar_autores();
                break;
            case 6:
                printf("\nVoltando ao menu principal...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
                break;
        }
    } while (opcao != 6);    
}

void carregar_autores(void) {
    FILE *arquivo = fopen(ARQUIVO_AUTORES, "r");
    char linha[BUFFER_SIZE];
    
    total_autores = 0;

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    
    while (fgets(linha, sizeof(linha), arquivo) && total_autores < MAX) {
        linha[strcspn(linha, "\r\n")] = 0;
        if (strlen(linha) == 0) continue;
        int lidos = sscanf(linha, "%49[^;];%d;%99[^;];%15[^\n]", autor[total_autores].nome, &autor[total_autores].codigoautor, autor[total_autores].historautor, autor[total_autores].idade);
        if (lidos == 4) {
            total_autores++;
        }
    }

    fclose(arquivo);
}

void consulta_autor(void) {
    int consulta;
    int ok;
    
    printf("\nFavor inserir código de autor para consulta: ");
    scanf("%d", &consulta);
    getchar();
    ok = 0;
    for (int i = 0; i < total_autores; i++) {
        if (consulta == autor[i].codigoautor) {
            printf("\n++++++++++++++++++++++++++++++++++++++++++\n");
            printf("Nome: %s\n", autor[i].nome);
            printf("Código: %03d\n", autor[i].codigoautor);
            printf("Idade: %s\n", autor[i].idade);
            printf("Mini-bio: %s\n", autor[i].historautor);
            printf("\n++++++++++++++++++++++++++++++++++++++++++\n");
            ok = 1;    
            break;
        } 
    }
    if (ok == 0) {
        printf("\nCódigo inválido\n");
    }
}

void listar_autores(void) {
    if (total_autores == 0) {
        printf("\nNenhum autor cadastrado.\n");
    } else {
        ordenarcod(autor, total_autores);
        printf("\n------ Lista de Autores (%d) ------\n", total_autores);
        for (int i = 0; i < total_autores; i++) {
            printf("Autor: %s | Código: %03d | Idade: %s | História: %s \n", autor[i].nome, autor[i].codigoautor, autor[i].idade, autor[i].historautor);
        }
    }
}    

void ordenarcod(struct Autores *a, int total) {
    struct Autores temp[total];
    for (int i = 0; i < total - 1; i++) {
        for (int x = 0; x < total - 1 - i; x++) {
            if (a[x].codigoautor > a[x + 1].codigoautor) {
                temp[x] = a[x];
                a[x] = a[x + 1];
                a[x + 1] = temp[x];
            }
        }
    }
}

void cadastrar_autor(void) {
    int consulta;
    int ok;
    char opcaosn;
    
    do {
        if (total_autores < MAX) {
            printf("\nQual o código do novo autor: ");
            scanf("%d", &consulta);
            getchar();
            ok = 1;
            for (int i = 0; i < total_autores; i++) {
                if (consulta == autor[i].codigoautor) {
                    printf("\nEste código já existe, tente novamente.");
                    ok = 0;    
                    break;
                } 
            }
            if (ok == 1) {
                autor[total_autores].codigoautor = consulta; 
                printf("\nQual o nome do novo autor: ");
                fgets(autor[total_autores].nome, sizeof(autor[total_autores].nome), stdin);
                autor[total_autores].nome[strcspn(autor[total_autores].nome, "\n")] = '\0';
                
                printf("\nDigite um trecho pequeno que defina o autor: ");
                fgets(autor[total_autores].historautor, sizeof(autor[total_autores].historautor), stdin);
                autor[total_autores].historautor[strcspn(autor[total_autores].historautor, "\n")] = '\0';
                
                printf("\nDigite a idade, ou período XXXX-XXXX para registo: ");
                fgets(autor[total_autores].idade, sizeof(autor[total_autores].idade), stdin);
                autor[total_autores].idade[strcspn(autor[total_autores].idade, "\n")] = '\0';
                
                printf("\n\nAutor %s, código %d foi cadastrado com sucesso.\n", autor[total_autores].nome , autor[total_autores].codigoautor);
                
                FILE *arquivo = fopen(ARQUIVO_AUTORES, "a");

                if (arquivo == NULL) {
                    printf("\nErro: nao foi possivel abrir %s para gravacao.\n", ARQUIVO_AUTORES);
