#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void altera_int(int *var, int valor) {
    *var = valor;
}

int main(void) {
    int x = 10;
    int *px;

    px = &x;
    *px = 20;

    printf("%d\n", x);
    altera_int(&x, 100);
    printf("%d\n", x);

    return 0;
}