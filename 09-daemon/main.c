#include "daemon.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    FILE *fd;
    daemon_init();

    fd = fopen("/home/wwwroot/c-learn/09-daemon/test", "w+");
    if (fd == NULL) {
        exit(-1);
    }
    while (1) {
        fputs("hhhhh\n", fd);
        fflush(fd);
        sleep(1);
    }
}
