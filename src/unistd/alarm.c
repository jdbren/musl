#include <unistd.h>
#include <sys/time.h>
#include "syscall.h"

unsigned alarm(unsigned seconds)
{
#ifdef SYS_alarm
	long ret = syscall(SYS_alarm, seconds);
	return __syscall_ret(ret);
#else
	struct itimerval it = { .it_value.tv_sec = seconds }, old = { 0 };
	setitimer(ITIMER_REAL, &it, &old);
	return old.it_value.tv_sec + !!old.it_value.tv_usec;
#endif
}
