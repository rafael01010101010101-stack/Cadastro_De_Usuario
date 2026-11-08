#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAMANHO 10

struct Elemento
{
    char nome[50];
    char senha[50];
    struct Elemento* next;
};

struct Elemento* tabela[TAMANHO];

int funcaoHash(char nome[])
{
    int soma = 0;
    for(int i = 0; nome[i] != '\0'; i++)
    {
        soma += nome[i];
    }
    
    return soma % TAMANHO;
}

void iniciarTabela()
{
    for(int i = 0; i < TAMANHO; i++)
    {
        tabela[i] = NULL;
    }
}

void inserir(char nome[], char senha[])
{
    int indice = funcaoHash(nome);
    
    struct Elemento* novo = malloc(sizeof(struct Elemento));
    strcpy(novo->nome, nome);
    strcpy(novo->senha, senha);
    novo->next = NULL;
    
    if(tabela[indice] == NULL)
    {
        tabela[indice] = novo;
    }
    else
    {
        struct Elemento* atual = tabela[indice];
        
        while(atual->next != NULL)
        {
            atual = atual->next;
        }
        atual->next = novo;
    }
}

char* buscar(char nome[])
{
    int indice = funcaoHash(nome);
    struct Elemento* atual = tabela[indice];
    
    while(atual != NULL)
    {
        
        if(strcmp(atual->nome, nome) == 0)
        {
            return atual->senha;
        }
        atual = atual->next;
    }
    
    return "Esse usuário não foi encontrado!";
}


int main()
{
    int opcao;
    char nome[50];
    char senha[50];
    
    iniciarTabela();
    do
    {
        printf("\nEscolha uma das opções abaixo:");
        printf("0 - Sair!\n");
        printf("1 - Cadastrar Usuário!\n");
        printf("2 - Buscar Usuário!\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao)
        {
            case 0:
                printf("Encerrando o programa...");
                break;
            case 1:
                printf("\nVocê escolheu cadastrar um usuário!\n\n");
                printf("Informe o nome do usuário: ");
                scanf("%49s", nome);
                printf("\n");
                
                printf("Informe a senha do usuário: ");
                scanf("%49s", senha);
                printf("\n");
                
                inserir(nome, senha);
                printf("Usuário inserido com sucesso!");
                break;
            case 2:
                printf("\nVocê escolheu buscar um usuário!\n\n");
                printf("Informe o nome do usuário: ");
                scanf("%49s", nome);
                
                printf("Resultado da pesquisa: %s\n", buscar(nome));
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    }while(opcao != 0);
    
    return 0;
}