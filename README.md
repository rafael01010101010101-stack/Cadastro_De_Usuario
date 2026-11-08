# Cadastro e Busca de Usuários utilizando Tabela Hash em C

## Descrição
Este projeto foi desenvolvido na linguagem C utilizando a estrutura de dados Tabela Hash. O programa possui um sistema de cadastro e busca de usuários, armazenando seus nomes e senhas.

## Funcionalidades
- Cadastrar novos usuários.
- Armazenar nomes e senhas na tabela hash.
- Buscar usuários pelo nome.
- Retornar a senha correspondente ao usuário encontrado.
- Informar quando um usuário não for encontrado.
- Tratar colisões utilizando o método de encadeamento separado.

## Estrutura de dados
O programa utiliza uma tabela hash de tamanho inicial 10, implementada com um vetor de ponteiros para estruturas do tipo `Elemento`.

Para tratar colisões, foi utilizado o método de encadeamento separado, no qual os elementos que possuem o mesmo índice são armazenados em uma lista ligada.

## Principais funções

- `funcaoHash()`: calcula o índice onde o usuário será armazenado, utilizando a soma dos caracteres do nome e o resto da divisão pelo tamanho da tabela.
- `iniciarTabela()`: inicializa todas as posições da tabela com `NULL`.
- `inserir()`: cadastra um novo usuário e armazena seus dados na posição calculada pela função hash.
- `buscar()`: percorre a lista ligada do índice correspondente até encontrar o usuário desejado.

## Tecnologias utilizadas
- Linguagem C
- Biblioteca stdio.h
- Biblioteca string.h
- Biblioteca stdlib.h

## Como funciona
O programa apresenta um menu interativo no terminal, permitindo que o usuário escolha entre cadastrar um novo usuário ou realizar uma busca.

Durante o cadastro, o nome é utilizado pela função hash para calcular o índice de armazenamento. Caso ocorra uma colisão, o novo elemento é conectado ao final da lista ligada correspondente.

Na busca, o programa calcula novamente o índice utilizando o nome informado e percorre a lista ligada até encontrar o usuário e retornar sua senha.

## Objetivo
Praticar os conceitos de Tabela Hash, funções hash, tratamento de colisões e listas ligadas, desenvolvendo um sistema simples de cadastro e busca de usuários.
