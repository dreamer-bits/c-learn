#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

int
main()
{
    char *path = "./sharefile";
    int fd;
    char *p;
    long pagesize = sysconf(_SC_PAGESIZE); 
    printf("page size: %ld\n", pagesize);

    fd = open(path, O_CREAT|O_RDWR);
    if(fd < 0) {
        perror("open file error");
        return 1;
    }

    // if(lseek(fd, 1, SEEK_SET) < 0) {
    //     perror("lseek error");
    //     return 2;
    // }

    // if(write(fd, "", 1) < 0) {
    //     perror("write error");
    //     return 3;
    // }

    p = (char *)mmap(NULL, pagesize, PROT_READ, MAP_SHARED, 
            fd, 0);

    if(p < 0) {
        perror("mmap error");
        return 4;
    }

    close(fd);

    while(1) {
        printf("%s\n", p);
        sleep(1);
    }
    
    return 0;
}
