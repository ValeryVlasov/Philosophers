#include "philosophers.h"

unsigned long get_time(struct timeval tv)
{
	int i_tv = tv.tv_usec / 1000 + tv.tv_sec * 1000;
	gettimeofday(&tv, NULL);
	int i_tv2 = tv.tv_usec / 1000 + tv.tv_sec * 1000;
	printf("Прошло времени с момента запуска программы - %d\n", i_tv2 - i_tv);
	return (i_tv2 - i_tv);
}

int everyone_ate(t_table *table)
{
	int i;

	i = -1;
	while (++i < table->philo_num)
	{
		if (table->philos[i].ate_enough == 0)
			return (0);
	}
	return (1);
}

void print_state(t_philo *philo, char *state)
{
	char *str;

	if (!philo || !state)
		return ;
	str = ft_itoa(philo->num);
	pthread_mutex_lock(philo->table->print_m);
	ft_putstrs_fd(NULL, " ", str, 1);//TODO: calc time
	ft_putstrs_fd(" ", state, "\n", 1);
	pthread_mutex_unlock(philo->table->print_m);
	delete_mem(str);
}

int main(int argc, char **argv)
{
	t_table table;

	if (argc < 5 || argc > 6)
		return (print_err("Bad argument\n"));
	if (validation(argv, &table) == 0)
		return (1);
	init_phil(&table);
	while (table.is_sm1_dead != 1)
	{
		if (everyone_ate(table))
		{
			ft_putstr_fd(MEAL, 1);
			ft_putstr_fd("\n", 1);
			break ;
		}
	}
	return (0);
}