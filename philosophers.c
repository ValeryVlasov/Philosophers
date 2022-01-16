#include "philosophers.h"
#include <math.h>

void get_time(struct timeval tv, struct timezone tz)
{
	int i_tv = tv.tv_usec;
	int i_tz = tz.tz_dsttime;
	gettimeofday(&tv, &tz);
	printf("Прошло времени с момента запуска программы - %d\n", tv.tv_usec - i_tv);
}


void *func()
{
	char *a;
	for (int i = 0; i < 1 << 20; i++)
	{
		a = malloc(1);
		ft_bzero(a, 1);
//		ft_memset(a, *(int *)(arg), 1);
		free(a);
//		(*(int *)arg)++;
	}
	return (NULL);
}

void begin_work(t_philo *phi)
{
	gettimeofday(&phi->time, &phi->tz);
}

void print_status(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex);
	printf("%lu\t%d %s\n", get_time(philo->time.tv, philo->tz), i + 1, philo->thread.mode);
	pthread_mutex_unlock(philo->mutex);
}

int print_err(char *msg)
{
	printf("%s", msg);
	return (1);
}

void err_handle(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

void init_mute_thread(t_philo *philo)
{
	int ret;
	int i;

	i = -1;
	printf("num = %d\n", philo->philo_num);
	while (++i < philo->philo_num)
	{
		ret = pthread_create(&philo->thread[i], NULL, func, NULL);
		if (ret)
		{
			err_handle("Creating thread failed\n");
		}
		else
		{
			ret = pthread_detach(philo->thread[i]);
			if (ret)
			{
				err_handle("Detaching thread failed\n");
			}
		}
	}
	ret = pthread_mutex_init(&philo->mutex, NULL);
	if (ret)
	{
		err_handle("Initialization mutex failed\n");
	}
}

void init_phil(t_philo *philo, char **argv)
{
	philo->philo_num = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->count_must_eat = ft_atoi(argv[5]);
	philo->thread = (pthread_t *)malloc(sizeof(pthread_t) * philo->philo_num);
	if (!philo->thread)
		err_handle("Malloc failed\n");
	ft_putstr_fd("sdaf\n", 2);
	init_mute_thread(philo);
}

int main(int argc, char **argv, char **envp)
{
	t_philo philo;

	if (argc < 5 || argc > 6)
		return (print_err("Bad argument\n"));
	begin_work(&philo);
	init_phil(&philo, argv);

	return (0);
}