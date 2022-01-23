/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrounds <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:54:34 by tgrounds          #+#    #+#             */
/*   Updated: 2022/01/20 13:54:34 by tgrounds         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# define FORK "has taken a fork"
# define LEFT_FORK "has taken a left fork"
# define RIGHT_FORK "has taken a right fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"
# define MEAL "Everyone finish with meal"

struct	s_table;

typedef struct s_philo
{
	int				ate_enough;
	int				num;
	long long		last_eat;
	struct s_table	*table;
	int				right_fork;
	int				left_fork;
}				t_philo;

typedef struct s_table
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				count_must_eat;
	int				is_sm1_dead;
	long long		time_start;
	t_philo			*philos;
	pthread_t		*threads;
	pthread_mutex_t	print_m;
	pthread_mutex_t	one_philo_m;
	pthread_mutex_t	*forks_m;
}				t_table;

void		print_state(t_philo *philo, char *state);

//philo_num.c
int			right(int n, int amount);
int			left(int n, int amount);

//errors
void		err_handle(char *msg);
int			print_err(char *msg);

//init.c
void		init_phil(t_table *table);
int			validation(char **args, t_table *table);

//routine.c
void		*routine(void *phil);

//utils.c
int			ft_putstrs_fd(char *before, char *str, char *after, int fd);
void		*delete_mem(void *ptr);
int			ft_atoi(const char *str);
int			ft_strlen(const char *str);
char		*ft_itoa(int n);
void		ft_putstr_fd(char *s, int fd);

//calc_time.c
long long	get_time(long long last_time);
long long	convert_time(struct timeval time);
void		my_sleep(long long time_start, long long mcs);

#endif
