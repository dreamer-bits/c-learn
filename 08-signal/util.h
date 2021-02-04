#ifndef __UTIL_H__
#include <signal.h>

void printsigset(const sigset_t *set);
void do_sig(int num);

#endif
