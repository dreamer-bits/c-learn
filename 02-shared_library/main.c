#include <stdio.h>
#include "include/calc.h"

int
main()
{
    int a = 7;
    int b = 3;

    printf("add:%d\n", add(a, b));
    printf("sub:%d\n", sub(a, b));
    printf("mul:%d\n", mul(a, b));
    printf("div:%d\n", div(a, b));

    return 0;
}
