/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrounds <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:54:23 by tgrounds          #+#    #+#             */
/*   Updated: 2022/01/20 13:54:31 by tgrounds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	everyone_ate(t_table table)
{
	int	i;

	i = -1;
	while (++i < table.philo_num)
	{
		if (table.philos[i].ate_enough == 0)
			return (0);
	}
	return (1);
}

void	print_state(t_philo *philo, char *state)
{
	char	*str;

	if (!philo || !state)
		return ;
	str = ft_itoa(philo->num);
	pthread_mutex_lock(&philo->table->print_m);
	ft_putstrs_fd(ft_itoa((int)((get_time(philo->table->time_start)) / 1000)), " ", str, 1);
	ft_putstrs_fd(" ", state, "\n", 1);
	pthread_mutex_unlock(&philo->table->print_m);
	delete_mem(str);
}

void	check_philos(t_table *table)
{
	long long	save;
	int			i;

	i = -1;
	long long temp;
	while (++i < table->philo_num)
	{
		save = table->philos[i].last_eat;
		if ((temp = get_time(table->time_start)) - save >= table->time_to_die * 1000)
		{
			if (!table->philos[i].ate_enough)
			{
				pthread_mutex_lock(&table->print_m);
				printf("%lld %d %s\nlast eat = %lld, to_die = %d, temp = %lld\n", get_time(table->time_start) / 1000, i + 1, DIED, save, table->time_to_die * 1000, temp);
//			print_state(&table->philos[i], DIED);
				table->is_sm1_dead = 1;
				return ;
			}
		}
	}
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5 || argc > 6)
		return (print_err("Bad argument\n"));
	if (validation(argv, &table) == 0)
		return (1);
	init_phil(&table);
	while (table.is_sm1_dead != 1)
	{
		if (everyone_ate(table))
		{
			pthread_mutex_lock(&table.print_m);
			ft_putstr_fd(MEAL, 1);
			ft_putstr_fd("\n", 1);
			break ;
		}
		usleep(1000);
		check_philos(&table);
	}
	return (0);
}
