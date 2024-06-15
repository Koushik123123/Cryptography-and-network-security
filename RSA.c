#include<stdio.h> 
long long int power(long long int base, long long int exp, long long int modulus) 
{
    long long int result = 1;
    while (exp > 0) 
    {
        if (exp % 2 == 1) 
        {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exp /= 2;
    }
    return result;
}
long long int encrypt(long long int plaintext, long long int e, long long int n) 
{
    return power(plaintext, e, n);
}
long long int decrypt(long long int ciphertext, long long int d, long long int n) 
{
    return power(ciphertext, d, n);
}
int main() 
{
    long long int p, q;
    printf("Enter prime number p: ");
    scanf("%lld", &p);
    printf("Enter prime number q: ");
    scanf("%lld", &q);
    long long int n = p * q;
    long long int phi = (p - 1) * (q - 1);
    long long int e;
    printf("Enter public exponent e (such that 1 < e < phiNo and e is coprime to phiNo): ");
    scanf("%lld", &e);
    long long int d = 1;
    while (((d * e) % phi) != 1) 
    {
        d++;
    }
    long long int plaintext;
    printf("Enter plaintext message: ");
    scanf("%lld", &plaintext);
    long long int ciphertext = encrypt(plaintext, e, n);
    printf("Encrypted message: %lld\n", ciphertext);
    long long int decryptedtext = decrypt(ciphertext, d, n);
    printf("Decrypted message: %lld\n", decryptedtext);
    return 0;
}
