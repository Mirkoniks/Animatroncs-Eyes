#include <stdio.h>

int main()
{
    int* a;

    int b = 5;

    *a = b;

    printf("%d", *a);

    return 0;
}