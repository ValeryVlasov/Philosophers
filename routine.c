#include "philosophers.h"

void *routine(void *phil)
{
	int i;
	t_philo *philo;
	char *state;

	i = 0;
	philo = (t_philo *)phil;
	state = NULL;
	while (1)
	{
		if (i++ >= philo->table->count_must_eat)
		{
			philo->ate_enough = 1;
			break ;
		}
		//eat//if dead - break
		//sleep
		print_state(philo, state);
		//think
	}
	return (NULL);
}