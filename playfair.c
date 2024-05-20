#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100

void preparePlainText(char *plaintext) {
    int i, j = 0;
    char temp[SIZE];
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            temp[j++] = toupper(plaintext[i]);
        }
    }
    temp[j] = '\0';
    strcpy(plaintext, temp);
}

void insertFiller(char *plaintext) {
    int i, j = 0;
    int len = strlen(plaintext);
    char temp[SIZE];
    for (i = 0; i < len; i++) {
        temp[j++] = plaintext[i];
        if (i + 1 < len && plaintext[i] == plaintext[i + 1]) {
            temp[j++] = 'X'; 
        }
    }
    temp[j] = '\0';
    strcpy(plaintext, temp);
}

void generateKeyTable(char key[], char keyTable[5][5]) {
    int i, j, k;
    char *ptr;
    char alphabet[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; 
    for (i = 0; i < strlen(key); i++) {
        key[i] = toupper(key[i]);
        if (key[i] == 'J')
            key[i] = 'I'; 
    }
    ptr = key;
    for (i = 0; i < strlen(key); i++) {
        for (j = i + 1; key[j] != '\0'; j++) {
            if (key[j] == key[i]) {
                for (k = j; key[k] != '\0'; k++)
                    key[k] = key[k + 1];
            }
        }
    }
    j = 0;
    int len = strlen(key);
    for (i = 0; i < len; i++) {
        keyTable[j / 5][j % 5] = key[i];
        alphabet[key[i] - 'A'] = 0; 
        j++;
    }
    for (i = 0; i < 26; i++) {
        if (alphabet[i] != 0 && (char)('A' + i) != 'J') {
            keyTable[j / 5][j % 5] = (char)('A' + i);
            j++;
        }
    }
}

void findPosition(char keyTable[5][5], char letter, int *row, int *col) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (keyTable[i][j] == letter) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encryptPlayfair(char *plaintext, char keyTable[5][5], char *ciphertext) {
    int i = 0, len;
    char a, b;
    int row1, col1, row2, col2;
    insertFiller(plaintext);
    len = strlen(plaintext);
    while (i < len) {
        a = plaintext[i];
        b = (i + 1 < len) ? plaintext[i + 1] : 'X';
        i += 2;
        findPosition(keyTable, a, &row1, &col1);
        findPosition(keyTable, b, &row2, &col2);
        if (row1 == row2) { 
            ciphertext[i - 2] = keyTable[row1][(col1 + 1) % 5];
            ciphertext[i - 1] = keyTable[row2][(col2 + 1) % 5];
        } else if (col1 == col2) { 
            ciphertext[i - 2] = keyTable[(row1 + 1) % 5][col1];
            ciphertext[i - 1] = keyTable[(row2 + 1) % 5][col2];
        } else { 
            ciphertext[i - 2] = keyTable[row1][col2];
            ciphertext[i - 1] = keyTable[row2][col1];
        }
    }
    ciphertext[i] = '\0';
}

void decryptPlayfair(char *ciphertext, char keyTable[5][5], char *plaintext) {
    int i = 0, len;
    char a, b;
    int row1, col1, row2, col2;
    int plaintext_index = 0;
    len = strlen(ciphertext);
    while (i < len) {
        a = ciphertext[i];
        b = ciphertext[i + 1];
        i += 2;
        findPosition(keyTable, a, &row1, &col1);
        findPosition(keyTable, b, &row2, &col2);
        if (row1 == row2) { 
            plaintext[plaintext_index++] = keyTable[row1][(col1 + 4) % 5];
            plaintext[plaintext_index++] = keyTable[row2][(col2 + 4) % 5];
        } else if (col1 == col2) { 
            plaintext[plaintext_index++] = keyTable[(row1 + 4) % 5][col1];
            plaintext[plaintext_index++] = keyTable[(row2 + 4) % 5][col2];
        } else {
            plaintext[plaintext_index++] = keyTable[row1][col2];
            plaintext[plaintext_index++] = keyTable[row2][col1];
        }
    }
    plaintext[plaintext_index] = '\0';
    int filtered_index = 0;
    for (int j = 0; j < plaintext_index; j++) {
        if (plaintext[j] != 'X') {
            plaintext[filtered_index++] = plaintext[j];
        }
    }
    plaintext[filtered_index] = '\0'; 
}

int main() {
    char key[SIZE], plaintext[SIZE], ciphertext[SIZE];
    char keyTable[5][5];
    printf("Enter key (no 'J', only unique alphabets): ");
    scanf("%s", key);
    printf("Enter plaintext: ");
    getchar(); 
    fgets(plaintext, SIZE, stdin);
    preparePlainText(plaintext);
    generateKeyTable(key, keyTable);
    encryptPlayfair(plaintext, keyTable, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    decryptPlayfair(ciphertext, keyTable, plaintext);
    printf("Decrypted plaintext: %s\n", plaintext);
    return 0;
}
