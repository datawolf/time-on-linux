#include <stdio.h>
#include <time.h>
#include <limits.h>

int main (int argc, char **argv)
{
    time_t      time;
    char        *char_time;

    time = INT_MIN;
    char_time = ctime(&time);

    printf("time = %d  : %s", INT_MIN, char_time);

    return 0;
}
