# Remote Command Execution Client

This is a C-based backdoor client that allows remote execution of commands on a server through a TCP connection.

## Description

The backdoor uses the Windows Socket (Winsock) API to establish a TCP connection with a remote server and executes the `cmd.exe` command on the server. It also applies an XOR operation on the data before sending it to obfuscate communication.

## Key Features

- Establish TCP connection with a remote server.
- Execution of the `cmd.exe` command on the remote server.
- Application of an XOR operation on the data to obfuscate communication.

## Requirements

- Windows operating system.
- C compiler compatible with the Windows environment (e.g., MinGW).
- Winsock library (already included in Windows).

## Compilation and Execution

To compile the program, you can use a C compiler compatible with the Windows environment, such as MinGW. Make sure to include the `-lws2_32` option to link the Winsock library.

## Demonstration:

![EDR_C](https://github.com/daniel-de-lima0xa/bypassAV/assets/59209081/2a1f1034-31ba-4106-a5a5-8b91783a10bd)

```sh
gcc -o remote_command_client remote_command_client.c -lws2_32
Then, execute the program:
