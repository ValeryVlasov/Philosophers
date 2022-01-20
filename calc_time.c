/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrounds <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:53:09 by tgrounds          #+#    #+#             */
/*   Updated: 2022/01/20 15:46:06 by tgrounds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	convert_time(struct timeval time)
{
	return ((long long)(time.tv_sec * 1000000 + time.tv_usec));
}

long long	get_time(long long last_time)
{
	struct timeval	new_time;

	gettimeofday(&new_time, NULL);
	return (convert_time(new_time) - last_time);
}

void	my_sleep(t_philo *philo, long long mcs)
{
	long long	cur;
	long long	start;

	start = get_time(philo->table->time_start);
	cur = start;
	while (cur - start < mcs)
	{
		usleep(100);//TODO
		cur = get_time(philo->table->time_start);
	}
}
