#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int
main()
{
    pid_t pid;
    
    pid = fork();

    if(pid < 0) {
        perror("fork error");
    }else if(pid == 0) {
        printf("child_1:pid=%d\n", getpid());
        sleep(2);
        return 0;
    }

    pid = fork();
    if(pid < 0) {
        perror("fork error");
        return -1;
    }else if(pid == 0) {
        printf("child_2:pid=%d\n", getpid());
        return 0;
    }

    pid_t cpid;
    for (int i=0; i<3; i++) {
        cpid= wait(NULL);
        if(cpid == -1) {
            perror("wait error");
            //return -1;
        }
    }
    
    
    while (1) {
        printf("parent:pid=%d, cpid=%d\n", getpid(), cpid);
        sleep(1);
    }
    
    return 0;
}
