#include "../philosophers.h"

void	*delete_mem(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (NULL);
}

void	*free_strarr(char **arr)
{
	int		i;

	i = -1;
	if (arr)
	{
		while (arr[++i])
		{
			if (arr[i])
				delete_mem(arr[i]);
		}
		delete_mem(arr);
	}
	return (NULL);
}