#include "daemon.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/param.h>

void
daemon_init()
{
    pid_t pid;
    // fork 子进程，父进程退出
    pid = fork();
    if (pid < 0) {
        exit(-1);
    } else if (pid > 0) {
        exit(0);
    }

    // 子进程脱离父进程会话
    setsid();

    pid = fork();
    if (pid < 0) {
        exit(-1);
    } else if (pid > 0) {
        exit(0);
    }

    // 关闭已经打开的文件描述符
    for (int i=0; i<NOFILE; i++) {
        close(i);
    }

    // 修改掩码
    umask(0);

    // 更改工作目录
    chdir("/tmp");
}
