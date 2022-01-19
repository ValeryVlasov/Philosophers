#include "philosophers.h"

int print_err(char *msg)
{
	printf("%s", msg);
	return (1);
}

void err_handle(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}