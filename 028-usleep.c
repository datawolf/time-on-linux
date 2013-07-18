#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv)
{
    unsigned int    usec = 2000000;

    /* 为了达到最大的可移植性，应该不依赖usleep的返回值*/
    usleep(usec);

    return 0;
}

/**
 * 进行错误检查的使用方法

errno = 0;
usleep(1000);
if (error)
    perror("usleep");

*/
