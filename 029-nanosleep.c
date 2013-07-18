#include <stdio.h>
#include <time.h>

/*
 * 基本用法
 * */
int main(int argc, char **argv)
{

    int ret;

    struct  timespec    req = {
        .tv_sec = 0,
        .tv_nsec = 200
    };

    // 休眠 200 ns
    ret = nanosleep(&req, NULL);
    
    if (ret)
        perror("nanosleep");

    return 0;
}

/**
 * 中断后可以继续休眠
 *
 * */
/*
struct  timespec    req = { .tv_sec = 0,
                            .tv_usec = 1939};
struct  timespec    rem;
int     ret;

retry:
ret = nanosleep(&req, &rem);
if (ret)
{
    if (errno == EINTR)
    {
        req.tv_sec = rem.tv_sec;
        req.tv_usec = rem.tv_usec;
        goto    retry;
    }
}

*/
/**
 * 另一种用法，可读性较差
 */

/*

struct  timespec    req = { .tv_sec = 1,
                            .tv_usec = 0};
struct  timespec    rem;

struct  timespec  *a = &req;
struct  timespec  *b = &rem;

//  sleep 1 seconds
while (nanosleep(a, b) && errno == EINTR)
{
    struct  timespec    *tmp = a;
    a = b;
    b = tmp;
}

*/
