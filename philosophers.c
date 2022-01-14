#include "philosophers.h"

void *foo()
{
	for (int i = 0; i < 10; i++)
	{
		sleep(1);
		printf("i = %d\n", i);
	}
	return (NULL);
}

void *foo2()
{
	for (int j = 0; j < 5; j++)
	{
		sleep(2);
		printf("j = %d\n", j);
	}
	return (NULL);
}

void get_time(struct timeval tv, struct timezone tz)
{
	int i_tv = tv.tv_usec;
	int i_tz = tz.tz_dsttime;
	gettimeofday(&tv, &tz);
	printf("Прошло времени с момента запуска программы - %d\n", tv.tv_usec - i_tv);
}



#include <math.h>

int main(int argc, char **argv, char **envp)
{
	pthread_t thread;
	struct timeval tv1;
	struct timezone tz;
	int count = 0;

//	printf("time = %d, tv = %ld, tz dst = %d, tz minute= %d\n", gettimeofday(&tv1, &tz), (long)(tv1.tv_sec), tz.tz_dsttime, tz.tz_minuteswest);
	thread = pthread_create(&thread, NULL, , NULL);
	get_time(tv1, tz);
	return (0);
}