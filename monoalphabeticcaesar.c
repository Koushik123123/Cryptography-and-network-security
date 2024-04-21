#include<stdio.h>
#include<string.h>
#define ALPHABET_SIZE 26
char encrypt(char ch,char key[])
{
	if(ch>='A' && ch<='Z')
	{
		return key[ch-'A'];
	}
	else if(ch>='a' && ch<='z')
	{
		return key[ch-'a']+('a'-'A');
	}
	else 
	{
		return ch;
	}
}
char decrypt(char ch,char key[])
{
	for(int i=0;i<26;i++)
	{
		if(ch==key[i])
		{
			return 'A'+i;
		}
		else if(ch==(key[i]+('a'-'A')))
		{
			return 'a'+i;
		}
	}
	return ch;
}
void encryptMessage(char plaintext[],char key[],char ciphertext[])
{
	int i;
	for(i=0;plaintext[i]!='\0';i++) 
	{
		ciphertext[i]=encrypt(plaintext[i],key);
	}
	ciphertext[i]='\0';
}
void decryptMessage(char ciphertext[],char key[],char plaintext[])
{
	int i;
	for(i=0;ciphertext[i]!='\0';i++) 
	{
		plaintext[i]=decrypt(ciphertext[i],key);
	}
	plaintext[i]='\0';
}
int main() 
{
	char plaintext[100];
	char key[100];
	char ciphertext[100];
	char decryptedtext[100];
	printf("Enter plaintext:\n");
	fgets(plaintext, sizeof(plaintext), stdin);
	printf("Enter key:\n");
	scanf("%s",key);
	encryptMessage(plaintext,key,ciphertext);
	printf("Encrypted text: %s\n",ciphertext);
	decryptMessage(ciphertext,key,decryptedtext);
	printf("Decrypted text: %s\n",decryptedtext);
	return 0;
}
