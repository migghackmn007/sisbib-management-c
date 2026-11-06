# sisbib-management-c

# 📚 SISBIB - Sistema de Gestão de Bibliotecas (Módulo de Usuários)

Este repositório contém a minha contribuição para o **SISBIB**, um sistema interativo via terminal desenvolvido em **Linguagem C** para automação de uma biblioteca. O projeto foi construído de forma modularizada e em equipe.

## 👥 Meu Papel no Projeto (Desenvolvimento Modular)

Para fins de organização do grupo, o sistema foi dividido em blocos. Eu fui o responsável por planejar e codificar a estrutura base do **Módulo de Gestão de Usuários (Opção 3)**, focando especificamente na **modelagem da estrutura (`struct`) e na lógica inicial de navegação e fluxo do cadastro**, além de garantir que a integração do menu funcionasse perfeitamente no sistema global desenvolvido pelos meus colegas.

## 🚀 Funcionalidades Desenvolvidas por Mim

- **Modelagem da Estrutura (`struct Usuarios`):** Definição do tipo de dado customizado para o sistema, estruturando os campos de cadastro exigidos pelo escopo: Nome, Matrícula (inteiro para busca), E-mail e Telefone.
- **Árvore de Decisão do Menu de Usuários:** Construção da interface interna de usuários usando loops `do-while` e condicionais `switch-case` para direcionar o fluxo de dados para as funções de consulta, cadastro, atualização, exclusão e listagem de usuários.
- **Tratamento Inicial de Input:** Uso estratégico da função `getchar()` após a leitura de opções para tratar o buffer do teclado no menu, evitando falhas na captura das entradas textuais subsequentes.

## 💻 Conceitos Técnicos Aplicados no Meu Código

- **Estruturas Puras em C:** Uso de vetores de caracteres (`char`) de tamanho fixo dentro da `struct` para garantir o armazenamento estável de dados textuais.
- **Modularização de Funções:** Declaração e prototipação das assinaturas de funções CRUD (`cadastrar_usuarios`, `consulta_usuarios`, `atualizar_usuarios`, `excluir_usuarios`, `listar_usuarios` e `ordenarmat`) prontas para a integração com o banco de arquivos do sistema.
- **Navegação Modular:** Desenvolvimento de submenus independentes que facilitam o trabalho paralelo da equipe sem gerar conflitos no código principal (`main`).

## 🛠️ Como rodar o projeto

1. Assegure-se de ter um compilador C (como o `gcc`) instalado no seu computador.
2. Baixe o código fonte final do projeto (`main.c`).
3. Abra o terminal na pasta do arquivo e compile o código:
```bash
gcc main.c -o sisbib
```
4. Execute o programa gerado:
```bash
./sisbib
```
