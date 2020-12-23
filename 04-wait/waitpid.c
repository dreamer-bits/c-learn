#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int
main()
{
    pid_t pid;
    for (char i=0; i<5; i++) {
        pid = fork();
        if(pid == 0) {
            break;
        }
    }

    if(pid == 0) {
        printf("I am child: %d\n", getpid());
        sleep(3);
    }

    pid_t cid;
    while(1) {
        cid = waitpid(-1, NULL, WNOHANG);
        if(cid == 0) {
            printf("not child exit\n");
        } else if (cid == -1) {
            printf("all child exit\n");
            return 0;
        } else {
            printf("child %d exit\n", cid);
        }
        sleep(1);
    }

    return 0;
}
