Caesar cipher
#include<stdio.h>
#include<string.h>
#include<ctype.h>
void encrypt(char text[],int k)
{
    for(int i=0;text[i]!='\0';i++)
    {
        char ch=text[i];
        if(isalnum(ch))
        {
            if(islower(ch))
            {
                ch=(ch - 'a' + k)%26 +'a';
            }
            if(isupper(ch))
            {
                ch=(ch - 'A' + k)%26 +'A';
            }
        }
        text[i]=ch;
    }
}
void decrypt(char text[],int k)
{
    for(int i=0;text[i]!='\0';i++)
    {
        char ch=text[i];
        if(isalnum(ch))
        {
            if(islower(ch))
            {
                ch=(ch - 'a' - k + 26)%26 +'a';
            }
            if(isupper(ch))
            {
                ch=(ch - 'A' - k + 26)%26 +'A';
            }
        }
        text[i]=ch;
    }
}
int main()
{
    int k;
    char text[100];
    printf("Enter the Plaintext:\n");
    fgets(text,sizeof(text),stdin);
    printf("Enter the Key:\n");
    scanf("%d",&k);
    encrypt(text,k);
    printf("Cipher text : %s\n",text);
    decrypt(text,k);
    printf("Plain text : %s\n",text);
    return 0;
}
