#include <unistd.h>
#include <stdio.h>

int
main()
{
    pid_t pid;

    pid = fork();

    if(pid < 0) {
        perror("fork error");
    } else if(pid == 0) {
        int i = 0;
        while(i < 5) {
            printf("child:pid=%d, ppid=%d\n", getpid(), getppid());
            sleep(1);
            i++;
        }
    } else {
        printf("parent:pid=%d\n", getpid());
        sleep(2);
        printf("parent exit\n");
    }

    return 0;
}
