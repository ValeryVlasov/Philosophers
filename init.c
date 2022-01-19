#include "philosophers.h"

static void init_mute_thread(t_table *table)
{
	int ret;
	int i;

	i = -1;
	if (pthread_mutex_init(&table->print_m, NULL) != 0)
		err_handle("Creating mutex failed\n");
	while (++i < table->philo_num)
	{
		ret = pthread_create(&table->threads[i], NULL, routine, &table->philos[i]);
		if (ret)
		{
			err_handle("Creating thread failed\n");
		}
		else
		{
			ret = pthread_detach(table->threads[i]);
			if (ret)
			{
				err_handle("Detaching thread failed\n");
			}
		}
	}
}

static void init_philos(t_table *table)
{
	int i;

	i = -1;
	while (++i < table->philo_num)
		pthread_mutex_init(&table->forks_m[i], NULL);
	i = -1;
	while (++i < table->philo_num)
	{
		table->philos[i].num = i + 1;
		table->philos[i].ate_enough = 0;
		table->philos[i].table = table;
		table->philos[i].last_eat = 0;
		table->philos[i].left_fork = table->forks_m[i];
		table->philos[i].right_fork = table->forks_m[right(i + 1, table->philo_num) - 1];
	}
}

void init_phil(t_table *table)
{
	table->threads = (pthread_t *)malloc(sizeof(pthread_t) * table->philo_num);
	if (!table->threads)
		err_handle("Malloc failed\n");
	table->philos = (t_philo *)malloc(sizeof(t_philo) * table->philo_num);
	if (!table->philos)
		err_handle("Malloc failed\n");
	table->forks_m = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * table->philo_num);
	if (!table->forks_m)
		err_handle("Malloc failed\n");
	init_philos(table);
	init_mute_thread(table);
}

int validation(char **args, t_table *table)
{
	int i;

	i = 0;
	while (args[++i])
	{
		if (ft_atoi(args[i]) <= 0)
			return (0);
		else if (i == 1)
			table->philo_num = ft_atoi(args[i]);
		else if (i == 2)
			table->time_to_die = ft_atoi(args[i]);
		else if (i == 3)
			table->time_to_eat = ft_atoi(args[i]);
		else if (i == 4)
			table->time_to_sleep = ft_atoi(args[i]);
		else if (i == 5)
			table->count_must_eat = ft_atoi(args[i]);
		else
			table->count_must_eat = -1;
		i++;
	}
	return (1);
}
