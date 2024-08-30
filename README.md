# Minitalk

O projeto **Minitalk** faz parte do currículo da Escola 42 e tem como objetivo criar uma aplicação cliente-servidor para comunicação entre processos usando sinais Unix. O servidor pode receber mensagens do cliente e exibi-las corretamente no terminal.

## Funcionalidades

- Comunicação entre dois processos via sinais Unix.
- O servidor recebe mensagens e as exibe no terminal.
- O cliente envia uma string ao servidor, que a exibe no terminal.
- Implementação de gerenciamento de erros e sinais.

## Estrutura do Projeto

- **server.c**: Implementa o servidor que recebe mensagens enviadas pelo cliente.
- **client.c**: Implementa o cliente que envia uma string ao servidor.
- **minitalk.h**: Arquivo de cabeçalho que contém as definições e protótipos utilizados em ambos os arquivos.

## Como Usar

### Compilação

Use o comando `make` para compilar o projeto. Isso irá gerar dois executáveis: `server` e `client`.

```bash
make
