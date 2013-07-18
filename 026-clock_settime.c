/**
 * 编译时使用参数  -lrt
 * 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    clockid_t       clocks[] = 
    {
        CLOCK_REALTIME,
        CLOCK_MONOTONIC,
        CLOCK_PROCESS_CPUTIME_ID,
        CLOCK_THREAD_CPUTIME_ID,
        (clockid_t) -1
    };

    int     i;
    struct      timespec        ts;
    int         ret;
    
    ret = clock_gettime(clocks[0], &ts);

    if (ret != 0)
        perror("clock_gettime");
    else
        printf("clock = %d sec = %ld nsec = %ld\n",
            clocks[0], ts.tv_sec, ts.tv_nsec);

    ts.tv_sec -= 3600;
    ret = clock_settime(clocks[0], &ts);

    if (ret != 0)
        perror("clock_settime");
    return EXIT_SUCCESS;
}
