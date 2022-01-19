#ifndef PHILO
# define PHILO

#include "libft/libft.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
//usleep - microsec
//sleep - sec
//task - millisec
//struct timeval {
//	time_t       tv_sec;   /* seconds since Jan. 1, 1970 */
//	suseconds_t  tv_usec;  /* and microseconds */
//};
//
//struct timezone {
//	int     tz_minuteswest; /* of Greenwich */
//	int     tz_dsttime;     /* type of dst correction to apply */
//};

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"
# define MEAL "Everyone finish with meal"

struct s_table;

typedef struct s_philo
{
	pthread_mutex_t left_fork;
	pthread_mutex_t right_fork;
	struct s_table *table;
	long long last_eat;
	int ate_enough;
	int num;
}   t_philo;

typedef struct s_table//Eating->Sleeping->Thinking->Eating...
{
	pthread_mutex_t *forks_m;
	pthread_mutex_t print_m;
	pthread_t *threads;//counting starts with 0
	t_philo *philos;//counting starts with 1
	struct timeval time;
	int philo_num;//
	int time_to_die;//
	int time_to_eat;//
	int time_to_sleep;//
	int count_must_eat;//
	int is_sm1_dead;//
}   t_table;
//table->time.tv_sec * 1000 + table->time.tv_usec / 1000
void print_state(t_philo *philo, char *state);

//philo_num.c
int right(int n, int amount);//n = num of philo, which starts with 1
int left(int n, int amount);

//errors
void err_handle(char *msg);
int print_err(char *msg);

//init.c
void init_phil(t_table *table);
int validation(char **args, t_table *table);

//routine.c
void *routine(void *phil);

//utils.c
int	ft_putstrs_fd(char *before, char *str, char *after, int fd);
void	*delete_mem(void *ptr);

#endif