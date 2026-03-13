#include <stdio.h> 
#include <stdlib.h>

long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;

    printf("Enter an integer number: ");
    if (scanf("%d", &n) != 1) {
        printf("Error: Invalid input. Only integers are accepted.\n");
        exit(1);
    }

    if (n < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
        exit(1);
    }

    printf("Factorial of %d = %lld\n", n, factorial(n)); 
    return 0;
}