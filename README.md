# sisbib-management-c

# 📚 SISBIB - Sistema de Gestão de Bibliotecas (Módulo de Usuários)

Este repositório contém a minha contribuição para o **SISBIB**, um sistema interativo via terminal desenvolvido em **Linguagem C** para automação de uma biblioteca. O projeto foi construído de forma modularizada e em equipe.

## 👥 Meu Papel no Projeto (Desenvolvimento Modular)

Para fins de organização do grupo, o sistema foi dividido em blocos. Eu fui o responsável por planejar e codificar a estrutura base do **Módulo de Gestão de Usuários (Opção 3)**, focando especificamente na **modelagem da estrutura e na lógica inicial de cadastro**, além de garantir que a navegação do menu funcionasse perfeitamente no sistema global desenvolvido pelos meus colegas.

## 🚀 Funcionalidades Desenvolvidas por Mim

- **Modelagem da Estrutura (`struct Usuario`):** Definição do tipo de dado customizado para o sistema, estruturando os campos essenciais de cadastro: Código, Nome, CPF e Telefone.
- **Tratamento de Memória (`limparBuffer()`):** Criação de uma rotina vital para limpar o buffer do teclado em qualquer sistema operacional, evitando o bug de o programa "pular" a digitação do nome no momento do cadastro.
- **Árvore de Decisão do Menu:** Construção da interface interna de usuários usando `do-while` e `switch-case` para direcionar o fluxo de dados para a área de cadastro e consulta.

## 💻 Conceitos Técnicos Aplicados no Meu Código

- **Estruturas Puras em C:** Uso de arrays de caracteres (`char`) de tamanho fixo para garantir o armazenamento seguro dos dados textuais de cadastro.
- **Manipulação de I/O de Baixo Nível:** Uso estratégico de um loop com `getchar()` para controle fino das entradas do teclado do usuário.
- **Modularização e Integração:** Escrita de código limpo preparado para receber as demais funções da equipe dentro dos blocos correspondentes do menu.

## 🛠️ Como rodar o projeto

1. Certifique-se de ter um compilador C (como o `gcc`) instalado no seu computador.
2. Baixe o código fonte final do projeto (`main.c`).
3. Abra o terminal na pasta do arquivo e compile o código:
```bash
gcc main.c -o sisbib
```
4. Execute o programa gerado:
```bash
./sisbib
```
