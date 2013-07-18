#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * 获取时间来源的分辨率
 * 编译时使用参数  -lrt
 */


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
        struct      timespec        res;
        int         ret;

        ret = clock_getres(clocks[i], &res);

        if (ret != 0)
            perror("clock_gettime");
        else
            printf("clock = %d sec = %ld nsec = %ld\n",
                    clocks[i], res.tv_sec, res.tv_nsec);
    }

    return EXIT_SUCCESS;
}

/**
clock = 0 sec = 0 nsec = 1
clock = 1 sec = 0 nsec = 1
clock = 2 sec = 0 nsec = 1
clock = 3 sec = 0 nsec = 1

从结果上来看，这四个时间来源都绑定到了分辨率较高的定时器上。
TSC（Timestamp counter）时间戳计数器，它能够提供那秒级的分辨率。
*/
