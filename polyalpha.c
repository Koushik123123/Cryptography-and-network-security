#include <stdio.h>
#include <string.h>
#include<ctype.h>
#define MAX_LEN 100
void encrypt(char *message, char *key) 
{
    int messageLen = strlen(message);
    int keyLen = strlen(key);
    int keyIndex = 0;
    for (int i = 0; i < messageLen; i++) 
    {
        if (isalpha(message[i])) 
        {
            int shift = tolower(key[keyIndex]) - 'a';
            message[i] = (char)(((tolower(message[i]) - 'a' + shift) % 26) + 'a');
            keyIndex = (keyIndex + 1) % keyLen;
        }
    }
    printf("Encrypted message: %s\n", message);
}
void decrypt(char *message, char *key)
{ 
    int messageLen = strlen(message);
    int keyLen = strlen(key);
    int keyIndex = 0;
    for (int i = 0; i < messageLen; i++) 
    {
        if (isalpha(message[i])) 
        {
            int shift = tolower(key[keyIndex]) - 'a';
            int decryptedChar = tolower(message[i]) - 'a' - shift;
            if (decryptedChar < 0)
                decryptedChar += 26;
            message[i] = (char)(decryptedChar % 26 + 'a');
            keyIndex = (keyIndex + 1) % keyLen;
        }
    }
    printf("Decrypted message: %s\n", message);
}
int main() 
{
    char message[MAX_LEN];
    char key[MAX_LEN];
    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 
    encrypt(message, key);
    printf("\n");
    decrypt(message, key);
    return 0;
}
