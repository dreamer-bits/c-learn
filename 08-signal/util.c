#include "./util.h"
#include <stdio.h>

void
printsigset(const sigset_t *set)
{
    int i;
    for(i=1; i<32; i++) {
        if(sigismember(set, i) == 1) {
            putchar('1');
        } else {
            putchar('0');
        }
    }
    puts("");
}

void
do_sig(int num)
{
    printf("do_sig, num=%d\n", num);
}
