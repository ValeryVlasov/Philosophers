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

typedef struct s_params
{

}   t_params;

typedef struct s_philo
{
	pthread_t *thread;
	struct timeval time;
	struct timezone tz;
	int philo_num;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int count_must_eat;
	char *mode;
	pthread_mutex_t mutex;
}   t_philo;