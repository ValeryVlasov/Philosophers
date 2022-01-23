/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrounds <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:52:31 by tgrounds          #+#    #+#             */
/*   Updated: 2022/01/20 13:52:59 by tgrounds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_fork(t_philo *philo)
{
	if (philo->num % 2)
	{
		usleep(900);
		pthread_mutex_lock(&philo->table->forks_m[philo->left_fork]);
		print_state(philo, FORK);
		if (philo->table->philo_num == 1)
			pthread_mutex_lock(&philo->table->one_philo_m);
		else
		{
			pthread_mutex_lock(&philo->table->forks_m[philo->right_fork]);
			print_state(philo, FORK);
		}
	}
	else
	{
		pthread_mutex_lock(&philo->table->forks_m[philo->right_fork]);
		print_state(philo, FORK);
		pthread_mutex_lock(&philo->table->forks_m[philo->left_fork]);
		print_state(philo, FORK);
	}
}

void	eat(t_philo *philo)
{
	take_fork(philo);
	print_state(philo, EAT);
	philo->last_eat = get_time(philo->table->time_start);
	my_sleep(philo->table->time_start, philo->table->time_to_eat * 1000);
	if (philo->num % 2)
	{
		pthread_mutex_unlock(&philo->table->forks_m[philo->left_fork]);
		pthread_mutex_unlock(&philo->table->forks_m[philo->right_fork]);
	}
	else
	{
		pthread_mutex_unlock(&philo->table->forks_m[philo->right_fork]);
		pthread_mutex_unlock(&philo->table->forks_m[philo->left_fork]);
	}
}

void	*routine(void *phil)
{
	int		i;
	int		eat_times;
	t_philo	*philo;

	i = -1;
	philo = (t_philo *)phil;
	eat_times = philo->table->count_must_eat;
	while (1)
	{
		if (eat_times > 0 && ++i >= eat_times)
		{
			philo->ate_enough = 1;
			break ;
		}
		print_state(philo, THINK);
		eat(philo);
		print_state(philo, SLEEP);
		my_sleep(philo->table->time_start, philo->table->time_to_sleep * 1000);
	}
	return (NULL);
}
