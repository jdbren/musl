#include <unistd.h>
#include <errno.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "syscall.h"

int isatty(int fd)
{
	struct termios term;
	/* +1 converts from error status (0/-1) to boolean (1/0) */
	return syscall(SYS_ioctl, fd, TCGETS, &term) + 1;
}
