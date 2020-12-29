#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define BUFSIZE 1024

int
main()
{
    char *path = "./myfifo.sock";
    char *buf;
    buf = (char *)malloc(BUFSIZE);
    memset(buf, 0, BUFSIZE);

    if(access(path, F_OK) < 0) {
        int result = mkfifo(path, 777);
        if(result < 0) {
            perror("mkfifo error");
            return -1;
        }
    }

    int fd = open(path, O_RDONLY);
    if(fd < 0) {
        perror("open mkfifo error");
        return -2;
    }

    int len = read(fd, buf, BUFSIZE);
    if(len < 0) {
        perror("read fifo error");
        return -3;
    }

    printf("read fifo: %s", buf);
    printf("read string length: %d\n", len);
    close(fd);

    return 0;
}
