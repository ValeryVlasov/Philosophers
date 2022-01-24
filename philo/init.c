/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrounds <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:53:50 by tgrounds          #+#    #+#             */
/*   Updated: 2022/01/20 13:53:51 by tgrounds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_mute_thread(t_table *tabl)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&tabl->print_m, NULL) != 0)
		err_handle(tabl, "Creating mutex failed\n");
	tabl->time_start = get_time(0);
	while (++i < tabl->philo_num)
	{
		if (pthread_create(&tabl->threads[i], NULL, routine, &tabl->philos[i]))
			err_handle(tabl, "Creating thread failed\n");
		else
		{
			if (pthread_detach(tabl->threads[i]))
				err_handle(tabl, "Detaching thread failed\n");
		}
	}
}

static void	init_philos(t_table *table)
{
	int		i;
	int		right_idx;

	i = -1;
	while (++i < table->philo_num)
	{
		if (pthread_mutex_init(&table->forks_m[i], NULL) != 0)
			err_handle(table, "Mutex init failed\n");
	}
	if (pthread_mutex_init(&table->one_philo_m, NULL) != 0)
		err_handle(table, "Mutex init failed\n");
	pthread_mutex_lock(&table->one_philo_m);
	i = -1;
	while (++i < table->philo_num)
	{
		right_idx = right(i + 1, table->philo_num) - 1;
		table->philos[i].num = i + 1;
		table->philos[i].ate_enough = 0;
		table->philos[i].table = table;
		table->philos[i].last_eat = 0;
		table->philos[i].left_fork = i;
		table->philos[i].right_fork = right_idx;
		if (table->philo_num == 1)
			table->philos[i].right_fork = -1;
	}
}

int	init_phil(t_table *table)
{
	table->is_sm1_dead = 0;
	table->threads = (pthread_t *)malloc(sizeof(pthread_t) * table->philo_num);
	if (!table->threads)
		err_handle(table, "Malloc failed\n");
	table->philos = (t_philo *)malloc(sizeof(t_philo) * table->philo_num);
	if (!table->philos)
		err_handle(table, "Malloc failed\n");
	table->forks_m
		= (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * table->philo_num);
	if (!table->forks_m)
		err_handle(table, "Malloc failed\n");
	init_philos(table);
	init_mute_thread(table);
	return (0);
}

int	validation(char **args, t_table *table)
{
	int	i;

	i = 0;
	while (args[++i])
	{
		if (ft_atoi(args[i]) <= 0)
			return (0);
	}
	table->philo_num = ft_atoi(args[1]);
	table->time_to_die = ft_atoi(args[2]);
	table->time_to_eat = ft_atoi(args[3]);
	table->time_to_sleep = ft_atoi(args[4]);
	if (args[5])
		table->count_must_eat = ft_atoi(args[5]);
	else
		table->count_must_eat = -1;
	return (1);
}
