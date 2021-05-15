#include <stdio.h>

int main() {
    int test = 3;

    printf("Hello, World! %d\n", test);

    int *p = &test;

    printf("test: %d\n", *p);
    return 0;
}