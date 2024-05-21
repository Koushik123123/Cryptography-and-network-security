#include<stdio.h>
#include<string.h>
#include<ctype.h>
char encryptchar(char c,char key[])
{
    if(isalpha(c))
    {
        if(islower(c))
        {
            return tolower(key[c - 'a']);
        }
        else 
        {
            return toupper(key[c - 'A']);
        }
    }
    return c;
}
char decryptchar(char c,char key[])
{
    for(int i=0;i<26;i++)
    {
        if(tolower(c)==tolower(key[i]))
        {
            if(islower(c))
            {
                return 'a'+ i;
            }
            else 
            {
                return 'A'+ i;
            }
        }
    }
    return c;
}
void encrypt(char plaintext[],char key[])
{
    for(int i=0;i<strlen(plaintext);i++)
    {
        plaintext[i]=encryptchar(plaintext[i],key);
    }
}
void decrypt(char ciphertext[],char key[])
{
    for(int i=0;i<strlen(ciphertext);i++)
    {
        ciphertext[i]=decryptchar(ciphertext[i],key);
    }
}
int main()
{
    char key[27];
    char plaintext[100];
    printf("Enter the plaintext: \n");
    fgets(plaintext,sizeof(plaintext),stdin);
    printf("Enter the key: \n");
    fgets(key,sizeof(key),stdin);
    char ciphertext[strlen(plaintext)];
    strcpy(ciphertext,plaintext);
    encrypt(ciphertext,key);
    printf("Encrypted text: %s\n",ciphertext);
    decrypt(ciphertext,key);
    printf("Decrypted text: %s \n",ciphertext);
    return 0;
}
