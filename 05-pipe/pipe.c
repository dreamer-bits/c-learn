#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int
main()
{
    char buf[1024];
    int fd[2];
    if(pipe(fd) < 0) {
        perror("pipe");
        return -1;
    }

    pid_t pid;
    pid = fork();

    if(pid == 0) {
        strcpy(buf, "hello world\n");
        write(fd[1], buf, strlen(buf));
        // 等待父进程读取完管道内容
        sleep(2);
        memset(buf, 0, sizeof(buf));
        int len = read(fd[0], buf, sizeof(buf));
        printf("parent say: %s", buf);
        close(fd[0]);
        close(fd[1]);
        return 0;
    }

    memset(buf, 0, sizeof(buf));
    int len = read(fd[0], buf, sizeof(buf));
    printf("child say: %s", buf);
    fflush(stdout);
    memset(buf, 0, sizeof(buf));
    strcpy(buf, "fuck the world child\n");
    write(fd[1], buf, strlen(buf));
    wait(NULL);
    close(fd[0]);
    close(fd[1]);
    return 0;
}
