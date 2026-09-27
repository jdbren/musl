#define _BSD_SOURCE
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include "syscall.h"

void *sbrk(intptr_t inc)
{
	unsigned long cur = __syscall(SYS_brk, 0);
	if (!inc) return (void *)cur;
	unsigned long want = cur + inc;
	if (__syscall(SYS_brk, want) != want)
		return (void *)__syscall_ret(-ENOMEM);
	return (void *)cur;
}
