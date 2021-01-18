#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[2];
    char age[3];
} person;

int
main()
{
    char *path = "./sharefile";
    int fd;
    person *p;
    long pagesize = sysconf(_SC_PAGESIZE);

    printf("page size: %ld\n", pagesize);

    fd = open(path, O_CREAT|O_RDWR|O_TRUNC);
    if(fd < 0) {
        perror("open file error");
    }

    if(lseek(fd, (sizeof(person) * 5) - 1, SEEK_SET) < 0) {
        perror("lseek error");
    }
    if(write(fd, "", 1) < 0) {
        perror("write error");
    }

    p = (person *)mmap(NULL, pagesize, PROT_READ|PROT_WRITE, MAP_SHARED, 
            fd, 0);

    close(fd);

    char name = 'a';

    for(int i=0; i<10; i++) {
        name += i;
        (*(p+i)).name[1] = ' ';
        memcpy((*(p+i)).name, &name, 1);
        sprintf((*(p+i)).age, "%d\n", 20+i);
    }
    
    munmap(p, pagesize);

    printf("write finish\n");

    return 0;
}
