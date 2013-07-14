#include <stdio.h>
#include <time.h>

int main ( int argc, char **argv)
{
    long i = 1000L;
    clock_t     start, finish;
    double      duration;

    printf("Time to do %ld empty loops is ", i);

    start = clock();
    while(i--)
    {
        system("cd");
    }
    finish = clock();

    duration = (double) (finish - start) / CLOCKS_PER_SEC;
    printf("%f seconds\n", duration);

    return 0;
}
