#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>


int main(int argc, char **argv)
{
    struct timeval  tv;
    struct timezone tz;
    time_t  now;

    /* the smallest time_t-sized value */
    time_t  beginning_of_time = 1L<<(sizeof(time_t)*8 - 1);
    /* the largest time_t-sized value*/
    time_t  end_of_time = ~beginning_of_time;

    printf("time_t is %d bits long\n", sizeof(time_t)*8);

    gettimeofday(&tv, &tz);

    now = tv.tv_sec;

    printf("Current time of day represented as a struct timeval:\n"
            "tv.tv_sec = 0x%08x, tv.tv_usec = 0x%08x\n"
            "tz.tz_minuteswest = 0x%08x, tz.tz_dsttime = 0x%08x\n\n",
            tv.tv_sec, tv.tv_usec, tz.tz_minuteswest, tz.tz_dsttime);

    printf("Demonstrating ctime() %s:\n",
            sizeof(time_t)*8 <= 32 ? "" :
            " (May hang after printing first line; press control-C");

    printf("time is now %s", ctime(&now));
    printf("time begins %s", ctime(&beginning_of_time));
    printf("time ends %s", ctime(&end_of_time));

    exit(0);


}

/**
在32位机器上执行结果。

time_t is 32 bits long
Current time of day represented as a struct timeval:
tv.tv_sec = 0x51e63edc, tv.tv_usec = 0x000e5752
tz.tz_minuteswest = 0xfffffe20, tz.tz_dsttime = 0x00000000

Demonstrating ctime() :
time is now Wed Jul 17 14:51:08 2013
time begins Sat Dec 14 04:51:44 1901
time ends Tue Jan 19 11:14:07 2038


**/

