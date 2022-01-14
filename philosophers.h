#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

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