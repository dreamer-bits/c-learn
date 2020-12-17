#include <unistd.h>
#include <stdio.h>

int
main()
{
    pid_t pid;
    FILE *file;
    file = fopen("./test", "a+");

    // 子进程数量计算公式：2^n
    for(int n=0; n<5; n++) {
        pid = fork();
        if(pid < 0) {
            printf("fork error");
        }else if(pid == 0) {
            fprintf(file, "pid=%d,n=%d\n", getpid(), n);
            fflush(file);
        }else if(pid > 0 && n == 0) {
            fprintf(file, "pid=%d,n=%d\n", getpid(), n);
            fflush(file);
            sleep(1);
        }
    }
    fclose(file);
    return 0;
}
