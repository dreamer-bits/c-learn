#include <unistd.h>
#include <stdio.h>

int
main()
{
    pid_t pid;
    
    pid = fork();

    if(pid < 0) {
        perror("fork error");
    }else if(pid == 0) {
        printf("child:pid=%d\n", getpid());
    }else {
        while (1) {
            printf("parent:pid=%d\n", getpid());
            sleep(1);
        }
    }
    return 0;
}
