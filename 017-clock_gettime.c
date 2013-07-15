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

    sleep(3);

    for (i = 0; clocks[i] != (clockid_t) -1; i++)
    {
        struct      timespec        ts;
        int         ret;

        ret = clock_gettime(clocks[i], &ts);

        if (ret != 0)
            perror("clock_gettime");
        else
            printf("clock = %d sec = %ld nsec = %ld\n",
                    clocks[i], ts.tv_sec, ts.tv_nsec);
    }

    return EXIT_SUCCESS;
}
