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
#define ARQUIVO_LIVROS "Livros.txt"
#define LIVROS_TEMP "TempLiv.csv"
#define ARQUIVO_EMP "Emp.txt"
#define EMP_TEMP "TempEmp.csv"
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
    
    struct Livros {
        char titulo[75];
        int codigolivro;
        int codautor;
        int ano;
    };
    
    struct Livros book[MAX];
    int total_livros = 0;
    
    void menuLivros(void);
    void carregar_livros(void);
    void listar_livros(void);
    void ordenarlivros(struct Livros *a, int total);
    void consulta_livro(void);
    void cadastrar_livros(void);
    void atualizar_livros(void);
    void excluir_livros(void);
    
    struct Emprestimos {
        int codemp;
        int codigolivro;
        int matricula;
        char data[12];
        char status;
    };
    
    struct Emprestimos emp[MAX];
    int total_emprestimos = 0;
    
    void menuEmprestimos(void);
    void carregar_emprestimos(void);
    void consulta_emprestimo(void);
    void listar_emprestimos(void);
    void ordenaremp(struct Emprestimos *a, int total);
    void cadastrar_emprestimos(void);
    void atualizar_emprestimos(void);
    void excluir_emprestimos(void);
    
    void relatorio(void);
    
int main()
{
    int opcao;
    
    carregar_autores();
    carregar_usuarios();
    carregar_livros();
    carregar_emprestimos();
    
    do {    
        printf("\n\n++++++++++++++++++++++++++++++++++++++++++\n");
	    printf("SISBIB - Sistema de Gestão de Bibliotecas.\n");
	    printf("++++++++++++++++++++++++++++++++++++++++++\n\n");
	
	    printf("1 - Gestão de Livros. \n");
	    printf("2 - Gestão de Autores. \n");
	    printf("3 - Gestão de Usuários. \n");
	    printf("4 - Gestão de Empréstimos. \n");
	    printf("5 - Relatório Geral. \n");
	    printf("6 - Sair. \n\n");
	    printf("Escolha uma opção: ");
	    scanf("%d", &opcao); 
	    switch(opcao) {
            case 1:
                menuLivros();
                break;
            case 2:
                menuAutores();
                break;
            case 3:
                menuUsuarios();
                break;
            case 4:
                menuEmprestimos();
                break;
            case 5:
                relatorio();
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

void menuLivros(void) {
    int opcao;
    
    do {
        printf("\n\n++++++++++++++++++++++++++++++++++++++++++\n");
	    printf("              Gestão de Livros.\n");
	    printf("++++++++++++++++++++++++++++++++++++++++++\n\n");
	    printf("\n1 - Consulta de livro.");
        printf("\n2 - Criar novo registro de livro.");
        printf("\n3 - Editar livro.");
        printf("\n4 - Excluir livro.");
        printf("\n5 - Imprimir lista de livros.");
        printf("\n6 - Voltar.");
        printf("\n\nEscolha uma opção: ");
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao) {
            case 1:
                consulta_livro();
                break;
            case 2:
                cadastrar_livros();
                break;
            case 3:
                atualizar_livros();
                carregar_livros();
                break;
            case 4:
                excluir_livros();
                carregar_livros();
                break;
            case 5:
                listar_livros();
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

void menuUsuarios(void) {
    int opcao;
    
    do {
        printf("\n\n++++++++++++++++++++++++++++++++++++++++++\n");
	    printf("           Gestão de Usuários.\n");
	    printf("++++++++++++++++++++++++++++++++++++++++++\n\n");
	    printf("\n1 - Consulta de Usuário.");
        printf("\n2 - Criar novo registro de usuário.");
        printf("\n3 - Editar usuário.");
        printf("\n4 - Excluir usuário.");
        printf("\n5 - Imprimir lista de usuários");
        printf("\n6 - Voltar.");
        printf("\n\nEscolha uma opção: ");
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao) {
            case 1:
                consulta_usuarios();
                break;
            case 2:
                cadastrar_usuarios();
                break;
            case 3:
                atualizar_usuarios();
                carregar_usuarios();
                break;
            case 4:
                excluir_usuarios();
                carregar_usuarios();
                break;
            case 5:
                listar_usuarios();
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

void menuEmprestimos(void) {
    int opcao;
    
    do {
        printf("\n\n++++++++++++++++++++++++++++++++++++++++++\n");
	    printf("             Gestão de Empréstimos.\n");
	    printf("++++++++++++++++++++++++++++++++++++++++++\n\n");
	    printf("\n1 - Consulta de empréstimo.");
        printf("\n2 - Empréstimo.");
        printf("\n3 - Editar Status.");
        printf("\n4 - Exclusão.");
        printf("\n5 - Imprimir lista de empréstimos.");
        printf("\n6 - Voltar.");
        printf("\n\nEscolha uma opção: ");
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao) {
            case 1:
                consulta_emprestimo();
                break;
            case 2:
                cadastrar_emprestimos();
                break;
            case 3:
                atualizar_emprestimos();
                carregar_emprestimos();
                break;
            case 4:
                excluir_emprestimos();
                carregar_emprestimos();
                break;
            case 5:
                listar_emprestimos();
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

/////// AUTORES ///////

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
                    return;
                }

                int gravados = fprintf(arquivo, "%s;%d;%s;%s\n", autor[total_autores].nome, autor[total_autores].codigoautor, autor[total_autores].historautor, autor[total_autores].idade);
                int erroFechamento = fclose(arquivo);

                if (gravados < 0 || erroFechamento != 0) {
                    printf("\nErro ao gravar o usuario em %s.\n", ARQUIVO_AUTORES);
                    return;
                }

                total_autores++;

                printf("\nUsuario cadastrado e salvo em %s com sucesso!\n", ARQUIVO_AUTORES);
                
                printf("\n\nGostaria de cadastrar um novo registro? (s/n): ");
                scanf("%c", &opcaosn);
                getchar();
                opcaosn = tolower(opcaosn);
            }
        } else {
        printf("\nMáximo de cadastros de autores atingido.\n");
        }
        break;
    } while (opcaosn == 's');
}

void atualizar_autor(void) {
    int codaut, atualizado = 0;
    struct Autores aut;
    char linha[BUFFER_SIZE];
    FILE *arquivo  = fopen(ARQUIVO_AUTORES, "r");
    FILE *temp = fopen(AUTORES_TEMP, "w");

    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        if (arquivo) fclose(arquivo);
        if (temp) fclose(temp);
        return;
    }

    printf("\nQual o código do autor para edição? ");
    scanf("%d", &codaut);
    getchar();

    while (fscanf(arquivo, "%49[^;];%d;%99[^;];%15[^\n]\n", aut.nome, &aut.codigoautor, aut.historautor, aut.idade) == 4) {
        if (aut.codigoautor == codaut) {
            printf("\nAutor encontrado: %s\n", aut.nome);

            printf("\nEdite o nome do autor: ");
            fgets(aut.nome, 50, stdin);
            aut.nome[strcspn(aut.nome, "\n")] = '\0';
            
            printf("\nEdite a mini biografia do autor: ");
            fgets(aut.historautor, 100, stdin);
            aut.historautor[strcspn(aut.historautor, "\n")] = '\0';

            printf("\nEdite a idade, ou período XXXX-XXXX para registo: ");
            fgets(aut.idade, 16, stdin);
            aut.idade[strcspn(aut.idade, "\n")] = '\0';
            
            fprintf(temp, "%s;%d;%s;%s\n", aut.nome, aut.codigoautor, aut.historautor, aut.idade);
            atualizado = 1;
            printf("\nAutor %s, código %d foi editado com sucesso.", aut.nome , aut.codigoautor);
        } else {
            fprintf(temp, "%s;%d;%s;%s\n", aut.nome, aut.codigoautor, aut.historautor, aut.idade);
        }
    }

    fclose(arquivo);
    fclose(temp);

    if (atualizado) {
        remove(ARQUIVO_AUTORES);
        rename(AUTORES_TEMP, ARQUIVO_AUTORES);
        printf("\n\nBanco de dados atualizado!\n");
    } else {
        remove(AUTORES_TEMP);
        printf("\nCódigo %d não encontrado, tente novamente!\n", codaut);
    }
}

void excluir_autores(void) {
    int cd, excluido = 0;
    struct Autores autemp;
    FILE *arquivo  = fopen(ARQUIVO_AUTORES, "r");
    FILE *temp = fopen(AUTORES_TEMP, "w");

    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        if (arquivo) fclose(arquivo);
        if (temp) fclose(temp);
        return;
    }

    printf("\nQual o código do autor a ser excluído? ");
    scanf("%d", &cd);
    getchar();

    while (fscanf(arquivo, "%49[^;];%d;%99[^;];%15[^\n]\n", autemp.nome, &autemp.codigoautor, autemp.historautor, autemp.idade) == 4) {
        
        if (autemp.codigoautor != cd) {
            fprintf(temp, "%s;%d;%s;%s\n", autemp.nome, autemp.codigoautor, autemp.historautor, autemp.idade);
        } else {
            printf("\n%s, o autor de código %d foi excluído com sucesso.", autemp.nome , autemp.codigoautor);
            excluido = 1;
        }
    }

    fclose(arquivo);
    fclose(temp);

    if (excluido) {
        remove(ARQUIVO_AUTORES);
        rename(AUTORES_TEMP, ARQUIVO_AUTORES);
        printf("\n\nBanco de dados atualizado!\n");
    } else {
        remove(AUTORES_TEMP);
        printf("\nCódigo %d não encontrado, tente novamente!\n", cd);
    }
}

///////// USUARIOS //////////

void carregar_usuarios(void) {
    FILE *arquivo = fopen(ARQUIVO_USUARIOS, "r");
    char linha[BUFFER_SIZE];
    
    total_usuarios = 0;

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    
    while (fgets(linha, sizeof(linha), arquivo) && total_usuarios < MAX) {
        linha[strcspn(linha, "\r\n")] = 0;
        if (strlen(linha) == 0) continue;
        int lidos = sscanf(linha, "%49[^;];%d;%99[^;];%15[^\n]", user[total_usuarios].nome, &user[total_usuarios].matricula, user[total_usuarios].email, user[total_usuarios].telefone);
        if (lidos == 4) {
            total_usuarios++;
        }
    }

    fclose(arquivo);
}

void listar_usuarios(void) {
    if (total_usuarios == 0) {
        printf("\nNenhum usuário cadastrado.\n");
    } else {
        ordenarmat(user, total_usuarios);
        printf("\n------ Lista de Autores (%d) ------\n", total_usuarios);
        for (int i = 0; i < total_usuarios; i++) {
            printf("Nome: %s | Matrícula: %d | E-mail: %s | Telefone: %s \n", user[i].nome, user[i].matricula, user[i].email, user[i].telefone);
        }
    }
}    

void ordenarmat(struct Usuarios *a, int total) {
    struct Usuarios temp[total];
    for (int i = 0; i < total - 1; i++) {
        for (int x = 0; x < total - 1 - i; x++) {
            if (a[x].matricula > a[x + 1].matricula) {
                temp[x] = a[x];
                a[x] = a[x + 1];
                a[x + 1] = temp[x];
            }
        }
    }
}

void consulta_usuarios(void) {
    int consulta;
    int ok;
    
    printf("\nFavor inserir o código do usuário para consulta: ");
    scanf("%d", &consulta);
    getchar();
    ok = 0;
    for (int i = 0; i < total_usuarios; i++) {
        if (consulta == user[i].matricula) {
            printf("\n++++++++++++++++++++++++++++++++++++++++++\n");
            printf("Nome: %s\n", user[i].nome);
            printf("Matrícula: %d\n", user[i].matricula);
            printf("E-mail: %s\n", user[i].email);
            printf("Telefone: %s\n", user[i].telefone);
            printf("\n++++++++++++++++++++++++++++++++++++++++++\n");
            ok = 1;    
            break;
        } 
    }
    if (ok == 0) {
        printf("\nCódigo inválido\n");
    }
}

void cadastrar_usuarios(void) {
    int consulta;
    int ok;
    char opcaosn;
    
    do {
        if (total_usuarios < MAX) {
            printf("\nQual o código do novo usuários: ");
            scanf("%d", &consulta);
            getchar();
            ok = 1;
            for (int i = 0; i < total_usuarios; i++) {
                if (consulta == user[i].matricula) {
                    printf("\nEste código já existe, tente novamente.");
                    ok = 0;    
                    break;
                } 
            }
            if (ok == 1) {
                user[total_usuarios].matricula = consulta; 
                printf("\nQual o nome do novo usuário: ");
                fgets(user[total_usuarios].nome, sizeof(user[total_usuarios].nome), stdin);
                user[total_usuarios].nome[strcspn(user[total_usuarios].nome, "\n")] = '\0';
                
                printf("\nDigite o e-mail do usuário: ");
                fgets(user[total_usuarios].email, sizeof(user[total_usuarios].email), stdin);
                user[total_usuarios].email[strcspn(user[total_usuarios].email, "\n")] = '\0';
                
                printf("\nDigite o telefone do usuário: ");
                fgets(user[total_usuarios].telefone, sizeof(user[total_usuarios].telefone), stdin);
                user[total_usuarios].telefone[strcspn(user[total_usuarios].telefone, "\n")] = '\0';
                
                printf("\n\nUsuário %s, matrícula %d foi cadastrado com sucesso.\n", user[total_usuarios].nome , user[total_usuarios].matricula);
                
                FILE *arquivo = fopen(ARQUIVO_USUARIOS, "a");

                if (arquivo == NULL) {
                    printf("\nErro: nao foi possivel abrir %s para gravacao.\n", ARQUIVO_USUARIOS);
                    return;
                }

                int gravados = fprintf(arquivo, "%s;%d;%s;%s\n", user[total_usuarios].nome, user[total_usuarios].matricula, user[total_usuarios].email, user[total_usuarios].telefone);
                int erroFechamento = fclose(arquivo);

                if (gravados < 0 || erroFechamento != 0) {
                    printf("\nErro ao gravar o usuario em %s.\n", ARQUIVO_USUARIOS);
                    return;
                }

                total_usuarios++;

                printf("\nUsuario cadastrado e salvo em %s com sucesso!\n", ARQUIVO_USUARIOS);
                
                printf("\n\nGostaria de cadastrar um novo registro? (s/n): ");
                scanf("%c", &opcaosn);
                getchar();
                opcaosn = tolower(opcaosn);
            }
        } else {
        printf("\nMáximo de cadastros de autores atingido.\n");
        }
        break;
    } while (opcaosn == 's');
}

void atualizar_usuarios(void) {
    int matri, atualizado = 0;
    struct Usuarios usu;
    char linha[BUFFER_SIZE];
    FILE *arquivo  = fopen(ARQUIVO_USUARIOS, "r");
    FILE *temp = fopen(USUARIOS_TEMP, "w");

    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        if (arquivo) fclose(arquivo);
        if (temp) fclose(temp);
        return;
    }

    printf("\nQual a matrícula do usuário para edição? ");
    scanf("%d", &matri);
    getchar();

    while (fscanf(arquivo, "%49[^;];%d;%99[^;];%15[^\n]\n", usu.nome, &usu.matricula, usu.email, usu.telefone) == 4) {
        if (usu.matricula == matri) {
            printf("\nUsuário encontrado: %s\n", usu.nome);

            printf("\nEdite o nome do usuário: ");
            fgets(usu.nome, 50, stdin);
            usu.nome[strcspn(usu.nome, "\n")] = '\0';
            
            printf("\nEdite o e-mail do usuário: ");
            fgets(usu.email, 100, stdin);
            usu.email[strcspn(usu.email, "\n")] = '\0';

            printf("\nEdite o telefone do usuário: ");
            fgets(usu.telefone, 16, stdin);
            usu.telefone[strcspn(usu.telefone, "\n")] = '\0';
            
            fprintf(temp, "%s;%d;%s;%s\n", usu.nome, usu.matricula, usu.email, usu.telefone);
            atualizado = 1;
            printf("\nUsuário %s, matrícula %d foi editado com sucesso.", usu.nome , usu.matricula);
        } else {
            fprintf(temp, "%s;%d;%s;%s\n", usu.nome, usu.matricula, usu.email, usu.telefone);
        }
    }

    fclose(arquivo);
    fclose(temp);

    if (atualizado) {
        remove(ARQUIVO_USUARIOS);
        rename(USUARIOS_TEMP, ARQUIVO_USUARIOS);
        printf("\n\nBanco de dados atualizado!\n");
    } else {
        remove(USUARIOS_TEMP);
        printf("\nMatrícula %d não encontrada, tente novamente!\n", matri);
    }
}

void excluir_usuarios(void) {
    int mat, excluido = 0;
    struct Usuarios usutemp;
    FILE *arquivo  = fopen(ARQUIVO_USUARIOS, "r");
    FILE *temp = fopen(USUARIOS_TEMP, "w");

    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        if (arquivo) fclose(arquivo);
        if (temp) fclose(temp);
        return;
    }

    printf("\nQual a matrícula do usuário a ser excluído? ");
    scanf("%d", &mat);
    getchar();

    while (fscanf(arquivo, "%49[^;];%d;%99[^;];%15[^\n]\n", usutemp.nome, &usutemp.matricula, usutemp.email, usutemp.telefone) == 4) {
        
        if (usutemp.matricula != mat) {
            fprintf(temp, "%s;%d;%s;%s\n", usutemp.nome, usutemp.matricula, usutemp.email, usutemp.telefone);
        } else {
            printf("\n%s, o usuário de matrícula %d foi excluído com sucesso.", usutemp.nome , usutemp.matricula);
            excluido = 1;
        }
    }

    fclose(arquivo);
    fclose(temp);

    if (excluido) {
        remove(ARQUIVO_USUARIOS);
        rename(USUARIOS_TEMP, ARQUIVO_USUARIOS);
        printf("\n\nBanco de dados atualizado!\n");
    } else {
        remove(USUARIOS_TEMP);
        printf("\nMatrícula %d não encontrado, tente novamente!\n", mat);
    }
}

///// LIVROS ///////

void carregar_livros(void) {
    FILE *arquivo = fopen(ARQUIVO_LIVROS, "r");
    char linha[BUFFER_SIZE];
    
    total_livros = 0;

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    
    while (fgets(linha, sizeof(linha), arquivo) && total_livros < MAX) {
        linha[strcspn(linha, "\r\n")] = 0;
        if (strlen(linha) == 0) continue;
        int lidos = sscanf(linha, "%74[^;];%d;%d;%d", book[total_livros].titulo, &book[total_livros].codigolivro, &book[total_livros].codautor, &book[total_livros].ano);
        if (lidos == 4) {
            total_livros++;
        }
    }

    fclose(arquivo);
}

void listar_livros(void) {
    if (total_livros == 0) {
        printf("\nNenhum usuário cadastrado.\n");
    } else {
        ordenarlivros(book, total_livros);
        printf("\n------ Lista de Livros (%d) ------\n", total_livros);
        for (int i = 0; i < total_livros; i++) {
            for (int x = 0; x < total_autores; x++) {
                if (book[i].codautor == autor[x].codigoautor) {
                printf("Título: %s | Código: %d | Autor: %s | Publicação: %d \n", book[i].titulo, book[i].codigolivro, autor[x].nome, book[i].ano);
                break;
                }
            }
        }
    }
}    

void ordenarlivros(struct Livros *a, int total) {
    struct Livros temp[total];
    for (int i = 0; i < total - 1; i++) {
        for (int x = 0; x < total - 1 - i; x++) {
            if (a[x].codigolivro > a[x + 1].codigolivro) {
                temp[x] = a[x];
                a[x] = a[x + 1];
                a[x + 1] = temp[x];
            }
        }
    }
}

void consulta_livro(void) {
    int consulta;
    int ok;
    
    printf("\nFavor inserir o código do livro para consulta: ");
    scanf("%d", &consulta);
    getchar();
    ok = 0;
    for (int i = 0; i < total_livros; i++) {
        if (consulta == book[i].codigolivro) {
            for (int x = 0; x < total_autores; x++) {
                if (book[i].codautor == autor[x].codigoautor) {
                    printf("\n++++++++++++++++++++++++++++++++++++++++++\n");
                    printf("Título: %s\n", book[i].titulo);
                    printf("Código: %d\n", book[i].codigolivro);
                    printf("Autor: %s\n", autor[x].nome);
                    printf("Publicação: %d\n", book[i].ano);
                    printf("\n++++++++++++++++++++++++++++++++++++++++++\n");
                    ok = 1;    
                    break;    
                }
            }
        break;    
        } 
    }
    if (ok == 0) {
        printf("\nCódigo inválido\n");
    }
}

void cadastrar_livros(void) {
    int consulta;
    int ok;
    char opcaosn;
    
    do {
        if (total_livros < MAX) {
            printf("\nQual o código do novo livro: ");
            scanf("%d", &consulta);
            getchar();
            ok = 1;
            for (int i = 0; i < total_livros; i++) {
                if (consulta == book[i].codigolivro) {
                    printf("\nEste código já existe, tente novamente.");
                    ok = 0;    
                    break;
                } 
            }
            if (ok == 1) {
                book[total_livros].codigolivro = consulta; 
                printf("\nQual o título do novo livro: ");
                fgets(book[total_livros].titulo, sizeof(book[total_livros].titulo), stdin);
                book[total_livros].titulo[strcspn(book[total_livros].titulo, "\n")] = '\0';
                
                printf("\nDigite o código de autor do livro: ");
                scanf("%d", &book[total_livros].codautor);
                getchar();
                
                printf("\nDigite o ano de publicação do livro: ");
                scanf("%d", &book[total_livros].ano);
                getchar();
                
                printf("\n\nLivro %s, código %d foi cadastrado com sucesso.\n", book[total_livros].titulo, book[total_livros].codigolivro);
                
                FILE *arquivo = fopen(ARQUIVO_LIVROS, "a");

                if (arquivo == NULL) {
                    printf("\nErro: nao foi possivel abrir %s para gravacao.\n", ARQUIVO_LIVROS);
                    return;
                }

                int gravados = fprintf(arquivo, "%s;%d;%d;%d\n", book[total_livros].titulo, book[total_livros].codigolivro, book[total_livros].codautor, book[total_livros].ano);
                int erroFechamento = fclose(arquivo);

                if (gravados < 0 || erroFechamento != 0) {
                    printf("\nErro ao gravar o livro em %s.\n", ARQUIVO_LIVROS);
                    return;
                }

                total_livros++;

                printf("\nLivro cadastrado e salvo em %s com sucesso!\n", ARQUIVO_LIVROS);
                
                printf("\n\nGostaria de cadastrar um novo registro? (s/n): ");
                scanf("%c", &opcaosn);
                getchar();
                opcaosn = tolower(opcaosn);
            }
        } else {
        printf("\nMáximo de cadastros de livros atingido.\n");
        }
        break;
    } while (opcaosn == 's');
}

void atualizar_livros(void) {
    int codigo, atualizado = 0;
    struct Livros liv;
    char linha[BUFFER_SIZE];
    FILE *arquivo  = fopen(ARQUIVO_LIVROS, "r");
    FILE *temp = fopen(LIVROS_TEMP, "w");

    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        if (arquivo) fclose(arquivo);
        if (temp) fclose(temp);
        return;
    }

    printf("\nQual o código do livro para edição? ");
    scanf("%d", &codigo);
    getchar();

    while (fscanf(arquivo, "%74[^;];%d;%d;%d\n", liv.titulo, &liv.codigolivro, &liv.codautor, &liv.ano) == 4) {
        if (liv.codigolivro == codigo) {
            printf("\nLivro encontrado: %s\n", liv.titulo);

            printf("\nEdite o nome do livro: ");
            fgets(liv.titulo, 75, stdin);
            liv.titulo[strcspn(liv.titulo, "\n")] = '\0';
            
            printf("\nEdite o código de autor do livro: ");
            scanf("%d", &liv.codautor);
            getchar();

            printf("\nEdite o ano de publicação do livro: ");
            scanf("%d", &liv.ano);
            
            fprintf(temp, "%s;%d;%d;%d\n", liv.titulo, liv.codigolivro, liv.codautor, liv.ano);
            atualizado = 1;
            printf("\nLivro %s, código %d foi editado com sucesso.", liv.titulo , liv.codigolivro);
        } else {
            fprintf(temp, "%s;%d;%d;%d\n", liv.titulo, liv.codigolivro, liv.codautor, liv.ano);
        }
    }

    fclose(arquivo);
    fclose(temp);

    if (atualizado) {
        remove(ARQUIVO_LIVROS);
        rename(LIVROS_TEMP, ARQUIVO_LIVROS);
        printf("\n\nBanco de dados atualizado!\n");
    } else {
        remove(LIVROS_TEMP);
        printf("\nCódigo %d não encontrado, tente novamente!\n", codigo);
    }
}

void excluir_livros(void) {
    int codigo, excluido = 0;
    struct Livros livtemp;
    FILE *arquivo  = fopen(ARQUIVO_LIVROS, "r");
    FILE *temp = fopen(LIVROS_TEMP, "w");

    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        if (arquivo) fclose(arquivo);
        if (temp) fclose(temp);
        return;
    }

    printf("\nQual o código do livro a ser excluído? ");
    scanf("%d", &codigo);
    getchar();

    while (fscanf(arquivo, "%74[^;];%d;%d;%d\n", livtemp.titulo, &livtemp.codigolivro, &livtemp.codautor, &livtemp.ano) == 4) {
        
        if (livtemp.codigolivro != codigo) {
            fprintf(temp, "%s;%d;%d;%d\n", livtemp.titulo, livtemp.codigolivro, livtemp.codautor, livtemp.ano);
        } else {
            printf("\n%s, o livro de código %d foi excluído com sucesso.", livtemp.titulo , livtemp.codigolivro);
            excluido = 1;
        }
    }

    fclose(arquivo);
    fclose(temp);

    if (excluido) {
        remove(ARQUIVO_LIVROS);
        rename(LIVROS_TEMP, ARQUIVO_LIVROS);
        printf("\n\nBanco de dados atualizado!\n");
    } else {
        remove(LIVROS_TEMP);
        printf("\nCódigo %d não encontrado, tente novamente!\n", codigo);
    }
}

////// EMPRESTIMOS //////

void carregar_emprestimos(void) {
    FILE *arquivo = fopen(ARQUIVO_EMP, "r");
    char linha[BUFFER_SIZE];
    
    total_emprestimos = 0;

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    
    while (fgets(linha, sizeof(linha), arquivo) && total_emprestimos < MAX) {
        linha[strcspn(linha, "\r\n")] = 0;
        if (strlen(linha) == 0) continue;
        int lidos = sscanf(linha, "%d;%d;%d;%11[^;];%c", &emp[total_emprestimos].codemp, &emp[total_emprestimos].codigolivro, &emp[total_emprestimos].matricula ,emp[total_emprestimos].data, &emp[total_emprestimos].status);
        if (lidos == 5) {
            total_emprestimos++;
        }
    }   

    fclose(arquivo);
}

void consulta_emprestimo(void) {
    int consulta;
    int ok;
    
    printf("\nFavor inserir código do empréstimo para consulta: ");
    scanf("%d", &consulta);
    getchar();
    ok = 0;
    for (int i = 0; i < total_emprestimos; i++) {
        if (consulta == emp[i].codemp) {
            printf("\n++++++++++++++++++++++++++++++++++++++++++\n");
            printf("Código de empréstimo: %03d\n", emp[i].codemp);
            for (int x = 0; x < total_livros; x++) {
                if (emp[i].codigolivro == book[x].codigolivro) {
                    printf("Título: %s\n", book[x].titulo);
                    printf("Código do livro: %d\n", book[x].codigolivro);
                    break;
                }    
            }
            for (int j = 0; j < total_usuarios; j++) {
                if (emp[i].matricula == user[j].matricula) {
                    printf("Aluno: %s\n", user[j].nome);
                    printf("Matrícula: %d\n", user[j].matricula);
                    break;
                }
            }
            printf("Data: %s\n", emp[i].data);
            printf("Status: %c", toupper(emp[i].status));
            printf("\n++++++++++++++++++++++++++++++++++++++++++\n");
            ok = 1;    
            break;
        } 
    }
    if (ok == 0) {
        printf("\nCódigo inválido\n");
    }
}

void listar_emprestimos(void) {
    if (total_emprestimos == 0) {
        printf("\nNenhum empréstimo cadastrado.\n");
    } else {
        ordenaremp(emp, total_emprestimos);
        printf("\n------ Lista de Empréstimos (%d) ------\n", total_emprestimos);
        for (int i = 0; i < total_emprestimos; i++) {
            printf("Código: %d | Código do livro: %d | Matrícula: %d | Data: %s | Status: %c \n", emp[i].codemp, emp[i].codigolivro, emp[i].matricula, emp[i].data, toupper(emp[i].status));
        }
    }
}    

void ordenaremp(struct Emprestimos *a, int total) {
    struct Emprestimos temp[total];
    for (int i = 0; i < total - 1; i++) {
        for (int x = 0; x < total - 1 - i; x++) {
            if (a[x].codemp > a[x + 1].codemp) {
                temp[x] = a[x];
                a[x] = a[x + 1];
                a[x + 1] = temp[x];
            }
        }
    }
}

void cadastrar_emprestimos(void) {
    int consulta;
    int consulta2;
    int ok;
    char opcaosn;
    
    do {
        if (total_emprestimos < MAX) {
            printf("\nQual o código do novo empréstimo: ");
            scanf("%d", &consulta);
            getchar();
            ok = 1;
            for (int i = 0; i < total_emprestimos; i++) {
                if (consulta == emp[i].codemp) {
                    printf("\nEste código já existe, tente novamente.");
                    ok = 0;    
                    break;
                } 
            }
            printf("\nQual o código do livro a ser emprestado: ");
            scanf("%d", &consulta2);
            getchar();    
            for (int x = 0; x < total_emprestimos; x++) {
                if (consulta2 == emp[x].codigolivro) {
                    printf("\nEste livro não está disponível, tente novamente.");
                    ok = 0;    
                    break;
                }
            }
            if (ok == 1) {
                emp[total_emprestimos].codemp = consulta;
                
                emp[total_emprestimos].codigolivro = consulta2;
                
                printf("\nDigite a matrícula do aluno para qual o livro será emprestado: ");
                scanf("%d", &emp[total_emprestimos].matricula);
                getchar();
                
                printf("\nDigite a data do empréstimo xx/xx/xxxx: ");
                fgets(emp[total_emprestimos].data, sizeof(emp[total_emprestimos].data), stdin);
                emp[total_emprestimos].data[strcspn(emp[total_emprestimos].data, "\n")] = '\0';
                
                emp[total_emprestimos].status = 'C';
                
                printf("\n\nEmpréstimo %d foi cadastrado com sucesso, a devolução deve ser feita em 5 dias.\n", emp[total_emprestimos].codemp);
                
                FILE *arquivo = fopen(ARQUIVO_EMP, "a");

                if (arquivo == NULL) {
                    printf("\nErro: nao foi possivel abrir %s para gravacao.\n", ARQUIVO_EMP);
                    return;
                }

                int gravados = fprintf(arquivo, "%d;%d;%d;%s;%c\n", emp[total_emprestimos].codemp, emp[total_emprestimos].codigolivro, emp[total_emprestimos].matricula, emp[total_emprestimos].data, emp[total_emprestimos].status);
                int erroFechamento = fclose(arquivo);

                if (gravados < 0 || erroFechamento != 0) {
                    printf("\nErro ao gravar o usuario em %s.\n", ARQUIVO_EMP);
                    return;
                }

                total_emprestimos++;

                printf("\nEmpréstimo cadastrado e salvo em %s com sucesso!\n", ARQUIVO_EMP);
                
                printf("\n\nGostaria de cadastrar um novo registro? (s/n): ");
                scanf("%c", &opcaosn);
                getchar();
                opcaosn = tolower(opcaosn);
            }
        } else {
        printf("\nMáximo de cadastros de autores atingido.\n");
        }
        break;
    } while (opcaosn == 's');
}

void atualizar_emprestimos(void) {
    int code, atualizado = 0;
    struct Emprestimos e;
    char linha[BUFFER_SIZE];
    FILE *arquivo  = fopen(ARQUIVO_EMP, "r");
    FILE *temp = fopen(EMP_TEMP, "w");

    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        if (arquivo) fclose(arquivo);
        if (temp) fclose(temp);
        return;
    }

    printf("\nQual o código do empréstimo para edição? ");
    scanf("%d", &code);
    getchar();

    while (fscanf(arquivo, "%d;%d;%d;%11[^;];%c\n", &e.codemp, &e.codigolivro, &e.matricula, e.data, &e.status) == 5) {
        if (e.codemp == code) {
            printf("\nEmpréstimo encontrado: %d\n", e.codemp);

            printf("\nEdite o código do livro emprestado: ");
            scanf("%d", &e.codigolivro);
            getchar();
            
            printf("\nEdite a matrícula para qual o livro foi emprestado: ");
            scanf("%d", &e.matricula);
            getchar();

            printf("\nEdite o status do empréstimo: ");
            scanf("%c", &e.status);
            getchar();
            
            fprintf(temp, "%d;%d;%d;%s;%c\n", e.codemp, e.codigolivro, e.matricula, e.data, e.status);
            atualizado = 1;
            printf("\nEmpréstimo %d foi editado com sucesso.", e.codemp);
        } else {
            fprintf(temp, "%d;%d;%d;%s;%c\n", e.codemp, e.codigolivro, e.matricula, e.data, e.status);
        }
    }

    fclose(arquivo);
    fclose(temp);

    if (atualizado) {
        remove(ARQUIVO_EMP);
        rename(EMP_TEMP, ARQUIVO_EMP);
        printf("\n\nBanco de dados atualizado!\n");
    } else {
        remove(EMP_TEMP);
        printf("\nCódigo %d não encontrado, tente novamente!\n", code);
    }
}

void excluir_emprestimos(void) {
    int code, excluido = 0;
    struct Emprestimos emptemp;
    FILE *arquivo  = fopen(ARQUIVO_EMP, "r");
    FILE *temp = fopen(EMP_TEMP, "w");

    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        if (arquivo) fclose(arquivo);
        if (temp) fclose(temp);
        return;
    }

    printf("\nQual o código do emprésto a ser excluído? ");
    scanf("%d", &code);
    getchar();

    while (fscanf(arquivo, "%d;%d;%d;%11[^;];%c\n", &emptemp.codemp, &emptemp.codigolivro, &emptemp.matricula, emptemp.data, &emptemp.status) == 5) {
        
        if (emptemp.codemp != code) {
            fprintf(temp, "%d;%d;%d;%s;%c\n", emptemp.codemp, emptemp.codigolivro, emptemp.matricula, emptemp.data, emptemp.status);
        } else {
            printf("\nO empréstimo de código %d foi excluído com sucesso.", emptemp.codemp);
            excluido = 1;
        }
    }

    fclose(arquivo);
    fclose(temp);

    if (excluido) {
        remove(ARQUIVO_EMP);
        rename(EMP_TEMP, ARQUIVO_EMP);
        printf("\n\nBanco de dados atualizado!\n");
    } else {
        remove(EMP_TEMP);
        printf("\nCódigo %d não encontrado, tente novamente!\n", code);
    }
}

///////// RELATORIO /////////

void relatorio(void) {
    printf("\n\n++++++++++++++++++++++++++++++++++++++++++\n");
    printf("           Relatório Geral SISBIB          \n");
    printf("++++++++++++++++++++++++++++++++++++++++++\n\n");

    printf("--- AUTORES ---\n");
    printf("Total de autores cadastrados: %d\n\n", total_autores);

    printf("--- USUÁRIOS ---\n");
    printf("Total de usuários cadastrados: %d\n\n", total_usuarios);

    int autores_com_livros = 0;
    for (int i = 0; i < total_autores; i++) {
        for (int j = 0; j < total_livros; j++) {
            if (book[j].codautor == autor[i].codigoautor) {
                autores_com_livros++;
                break; 
            }
        }
    }

    printf("--- LIVROS ---\n");
    printf("Total de livros cadastrados: %d\n", total_livros);
    printf("Quantidade de autores dos livros cadastrados: %d\n\n", autores_com_livros);

    int count_A = 0, count_C = 0, count_D = 0;

    for (int i = 0; i < total_emprestimos; i++) {
        char st = toupper(emp[i].status);
        if (st == 'A') count_A++;
        else if (st == 'C') count_C++;
        else if (st == 'D') count_D++;
    }

    printf("--- EMPRÉSTIMOS ---\n");
    printf("Total de empréstimos registrados: %d\n", total_emprestimos);
    printf("  - Atrasados (A): %d\n", count_A);
    printf("  - Corretos (C): %d\n", count_C);
    printf("  - Devolvidos (D): %d\n\n", count_D);

    printf("Detalhamento de empréstimos por data:\n");
    if (total_emprestimos == 0) {
        printf("  Nenhum empréstimo registrado.\n");
    } else {
        int processado[MAX] = {0};

        for (int i = 0; i < total_emprestimos; i++) {
            if (!processado[i]) {
                int count_data = 0;
                int data_A = 0, data_C = 0, data_D = 0;

                // Percorre todos os empréstimos a partir de 'i' para contabilizar os status da mesma data
                for (int j = i; j < total_emprestimos; j++) {
                    if (strcmp(emp[i].data, emp[j].data) == 0) {
                        count_data++;
                        processado[j] = 1;

                        char st = toupper(emp[j].status);
                        if (st == 'A') data_A++;
                        else if (st == 'C') data_C++;
                        else if (st == 'D') data_D++;
                    }
                }

                printf("  - Data: %-10s | Total: %d (Atrasados: %d, Corretos: %d, Devolvidos: %d)\n", 
                       emp[i].data, count_data, data_A, data_C, data_D);
            }
        }
    }

    printf("\nPressione ENTER para voltar ao menu principal...");
    getchar();
    getchar();
}
