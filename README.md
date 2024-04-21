# Remote Command Execution Client

Este é um Backdoor cliente em C que permite a execução remota de comandos em um servidor através de uma conexão TCP.

## Descrição

O Backdoor utiliza a API do Windows Socket (Winsock) para estabelecer uma conexão TCP com um servidor remoto e executa o comando `cmd.exe` no servidor. Ele também aplica uma operação XOR nos dados antes de enviá-los para ofuscar a comunicação.

## Funcionalidades Principais

- Estabelecimento de conexão TCP com um servidor remoto.
- Execução do comando `cmd.exe` no servidor remoto.
- Aplicação de uma operação XOR nos dados para ofuscar a comunicação.

## Requisitos

- Sistema operacional Windows.
- Compilador C compatível com o ambiente Windows (por exemplo, MinGW).
- Biblioteca Winsock (já incluída no Windows).

## Compilação e Execução

Para compilar o programa, você pode usar um compilador C compatível com o ambiente Windows, como o MinGW. Certifique-se de incluir a opção `-lws2_32` para vincular a biblioteca Winsock.

## Demonstração:

![EDR_C](https://github.com/daniel-de-lima0xa/bypassAV/assets/59209081/2a1f1034-31ba-4106-a5a5-8b91783a10bd)

```sh
gcc -o remote_command_client remote_command_client.c -lws2_32
Em seguida, execute o programa:

sh
Copy code
remote_command_client.exe
Demonstração
Veja a demonstração do funcionamento do Backdoor aqui.

Notas
Este é um exemplo educacional e deve ser usado com cuidado. A execução remota de comandos pode representar um risco de segurança.
O Backdoor pode ser modificado para aceitar comandos de entrada do usuário e enviar esses comandos para execução remota no servidor.



