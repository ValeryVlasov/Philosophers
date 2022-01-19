#include "philosophers.h"

int left(int n, int amount)
{
	if ((n + 1) % amount == 0)
		return (amount);
	return ((n + 1) % amount);
}

int right(int n, int amount)
{
	if ((n - 1) % amount == 0)
		return (amount);
	return ((n - 1) % amount);
}