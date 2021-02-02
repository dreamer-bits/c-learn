#include <signal.h>
#include <unistd.h>
#include "./util.h"

int
main()
{
    sigset_t *s;
    sigset_t *p;
    sigemptyset(s);
    sigaddset(s, SIGINT);
    sigprocmask(SIG_BLOCK, s, NULL);
    while(1) {
        sigpending(p);
        printsigset(p);
        sleep(1);
    }
    return 0;
}
