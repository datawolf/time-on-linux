#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv)
{
    unsigned int    s = 5;

    /*保证休眠5秒钟*/
    while((s = sleep(s)))
    {};

    return 0;
}
