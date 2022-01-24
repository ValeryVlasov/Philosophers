/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrounds <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:53:21 by tgrounds          #+#    #+#             */
/*   Updated: 2022/01/20 13:54:19 by tgrounds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	print_err(char *msg)
{
	printf("%s", msg);
	return (1);
}

static void	mute_destroy(pthread_mutex_t *mutex)
{
	pthread_mutex_unlock(mutex);
	pthread_mutex_destroy(mutex);
}

void	err_handle(t_table *table, char *msg)
{
	int	i;

	i = -1;
	ft_putstr_fd(msg, 2);
	if (table)
	{
		mute_destroy(&table->one_philo_m);
		while (++i < table->philo_num)
			mute_destroy(&table->forks_m[i]);
		delete_mem(table->forks_m);
		delete_mem(table->philos);
		delete_mem(table->threads);
		mute_destroy(&table->print_m);
	}
	exit(1);
}
