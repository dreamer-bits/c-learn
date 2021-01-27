#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 100

int
main()
{
    char *p;

    p = (char *)mmap(NULL, BUF_SIZE, PROT_READ|PROT_WRITE, 
            MAP_SHARED|MAP_ANONYMOUS, -1, 0);

    if(fork() == 0) {
        sleep(1);
        printf("child got a msg: %s\n", p);
        sprintf(p, "%s", "hi, parent, this is child");
        munmap(p, BUF_SIZE);
        return 0;
    }

    sprintf(p, "%s", "hi, this is child");

    sleep(2);

    printf("parent got a msg: %s\n", p);

    return 0;
}
