#include <unistd.h>
#include "./util.h"
#include <stdio.h>

int
main(void)
{
    struct sigaction act;

    act.sa_handler = do_sig;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    printsigset(&act.sa_mask);
    
    sigaction(SIGINT, &act, NULL);

    while (1) {
        printf("********\n");
        sleep(1);
    }
}
