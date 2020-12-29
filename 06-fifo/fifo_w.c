#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int
main()
{
    char *path = "./myfifo.sock";

    if(access(path, F_OK) < 0) {
        if(mkfifo(path, 0777) < 0) {
            perror("mkfifo error");
            return -1;
        }
    }

    int fd = open(path, O_WRONLY);
    if(fd < 0) {
        perror("open fifo error");
        return -2;
    }

    char *buf = "hello world\n";
    int len = write(fd, buf, strlen(buf));
    if(len < 0) {
        perror("write fifo error");
        return -3;
    }

    printf("write success, write %d bytes\n", len);

    close(fd);

    return 0;
}
