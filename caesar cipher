#include <stdio.h>
#include<ctype.h>

int main(){
    char c[100],ch;
    int key;
    printf("enter the string: ");
    fgets(c, sizeof(c), stdin);
    printf("enter the key :");
    scanf("%d", &key);
    for (int i = 0; c[i] != '\0'; ++i) {
        ch = c[i];
        if (isalnum(ch)) {
            if (islower(ch)) {
                ch = (ch - 'a' + key) % 26 + 'a';
            }
            if (isupper(ch)) {
                ch = (ch - 'A' + key) % 26 + 'A';
            }
        }
          c[i] = ch;
    }
    printf("Encrypted message: %s", c);
    for (int i = 0; c[i] != '\0'; ++i) {
        ch = c[i];
        if (isalnum(ch)) {
            if (islower(ch)) {
                ch = (ch - 'a' -key +26) % 26 + 'a';
            }
            if (isupper(ch)) {
                ch = (ch - 'A' - key +26) % 26 + 'A';
            }
        }
          c[i] = ch;
    }
    printf("Decrypted  message: %s", c);
    
    
    return 0;
}
