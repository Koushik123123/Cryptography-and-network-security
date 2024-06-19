#include <math.h>
#include <stdio.h>
long long int power(long long int a, long long int b,long long int P)
{
    if (b == 1)
        return a;
    else
        return (((long long int)pow(a, b)) % P);
}
int main()
{
    long long int P, G, x, a, y, b, ka, kb;
    printf("Enter The value of P \n");
    scanf("%lld",&P);
    printf("Enter The value of G \n\n");
    scanf("%lld",&G);
    printf("The private key a for Alice \n");
    scanf("%lld",&a);
    x = power(G, a, P); 
    printf("The private key b for Bob \n\n");
    scanf("%lld",&b);
    y = power(G, b, P);
    ka = power(y, a, P); 
    kb = power(x, b, P); 
    printf("Secret key for the Alice is : %lld\n", ka);
    printf("Secret Key for the Bob is : %lld\n", kb);
    return 0;
}
