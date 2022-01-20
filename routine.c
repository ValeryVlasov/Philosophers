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

void	take_fork(t_philo *philo, pthread_mutex_t first, pthread_mutex_t second)
{
//	pthread_mutex_lock(&first);
//	print_state(philo, LEFT_FORK);
////	if (philo->table->philo_num == 1)
////		usleep(100000);
//	pthread_mutex_lock(&second);
//	print_state(philo, RIGHT_FORK);
}

void	take_fork2(t_philo *philo)
{

	if (philo->num % 2)
	{
		pthread_mutex_lock(&philo->table->forks_m[philo->num - 1]);
		print_state(philo, LEFT_FORK);
		pthread_mutex_lock(&philo->table->forks_m[right(philo->num, philo->table->philo_num) - 1]);
		print_state(philo, RIGHT_FORK);
	}
	else
	{
		pthread_mutex_lock(&philo->table->forks_m[right(philo->num, philo->table->philo_num) - 1]);
		print_state(philo, RIGHT_FORK);
		pthread_mutex_lock(&philo->table->forks_m[philo->num - 1]);
		print_state(philo, LEFT_FORK);
	}
}

void	eat(t_philo *philo)
{
//	if (philo->num % 2)
//	{
////		usleep(100);
//		take_fork(philo, philo->left_fork, philo->right_fork);
//	}
//	else
//		take_fork(philo, philo->right_fork, philo->left_fork);
	take_fork2(philo);
	print_state(philo, EAT);
	philo->last_eat = get_time(philo->table->time_start);
	my_sleep(philo, philo->table->time_to_eat * 1000);
	if (philo->num % 2)
	{
		pthread_mutex_unlock(&philo->table->forks_m[philo->num - 1]);
		pthread_mutex_unlock(&philo->table->forks_m[right(philo->num, philo->table->philo_num) - 1]);
	}
	else
	{
		pthread_mutex_unlock(&philo->table->forks_m[right(philo->num, philo->table->philo_num) - 1]);
		pthread_mutex_unlock(&philo->table->forks_m[philo->num - 1]);
	}
}

void	*routine(void *phil)
{
	int		i;
	int 	eat_times;
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
		my_sleep(philo, philo->table->time_to_sleep * 1000);
	}
	return (NULL);
}
