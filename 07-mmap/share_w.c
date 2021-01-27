#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

/**
 * 使用共享映射实现两个进程通讯，写端
 *
 */

int
main()
{
    char *path = "./sharefile";
    int fd;
    char *p;
    long pagesize = sysconf(_SC_PAGESIZE);
    printf("page size: %ld\n", pagesize);

    fd = open(path, O_CREAT|O_RDWR|O_TRUNC);
    if(fd < 0) {
        perror("open file error");
        return 1;
    }

    if(lseek(fd, 1, SEEK_SET) < 0) {
        perror("lseek error");
        return 2;
    }

    if(write(fd, "", 1) < 0) {
        perror("write error");
        return 3;
    }

    p = (char *)mmap(NULL, pagesize, PROT_READ|PROT_WRITE, MAP_SHARED, 
            fd, 0);

    if(p < 0) {
        perror("mmap error");
        return 4;
    }

    close(fd);

    int i = 0;
    char c = 'a';
    while(1) {
        if(i > 25) {
            break;
        }
        *(p+i) = c+i;
        printf("%s\n", p);
        i++;
        sleep(1);
    }

    sleep(10);

    munmap(p, pagesize);
    return 0;

}
