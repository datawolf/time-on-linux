#include <stdio.h>
#include <time.h>



// 相对时间休眠
/*
int main(int argc, char **argv)
{
    struct timespec ts = { .tv_sec = 1,
                        .tv_nsec = 500000000};
    int ret;

    ret = clock_nanosleep(CLOCK_MONOTONIC, 0, &ts, NULL);

    if (ret)
    {
        perror("clock_nanosleep");
    }

    return 0;
}
*/
//绝对时间休眠
//对于有些实时进程有非常确切的时序要求，就需要使用绝对的
//休眠来避免可能出现的竞争条件。
int main(int argc, char **argv)
{
    struct  timespec    ts;
    int     ret;

    ret = clock_gettime(CLOCK_MONOTONIC, &ts);

    if (ret)
    {
        perror("clock_gettime");
        return;
    }

    ts.tv_sec += 1;
    printf("We want to sleep until sec = %ld, nsec = %ld\n",
            ts.tv_sec, ts.tv_nsec);

    ret = clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &ts, NULL);

    if (ret)
        perror("clock_nanosleep");

    return 0;
}
