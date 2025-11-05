#include <stdio.h>

int g (int *a, int *b);

int main() {
    int a = 2;
    int b = 7;

    b = g(&b, &a);

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}

int g(int *a, int *b) {
    (*a) = (*a) + 3; 
    (*b) = 2*(*a) - (*b)+5;

    printf("a = %d, b = %d\n", *a, *b);

    return (*a) + (*b);
}

