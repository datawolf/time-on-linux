#include <stdio.h>
#include <time.h>
#include <limits.h>

int main (int argc, char **argv)
{
    time_t      time;
    char        *char_time;

    time = 0x7fffffff+1;
    char_time = asctime(gmtime(&time));

    printf("time = %d  : %s", time, char_time);

    time = 0x7fffffff;
    char_time = asctime(gmtime(&time));

    printf("time = %d  : %s", time, char_time);

    time = 0xffffffff+1;
    char_time = asctime(gmtime(&time));

    printf("time = %d  : %s", time, char_time);
    
    time = 0xffffffff;
    char_time = asctime(gmtime(&time));

    printf("time = %d  : %s", time, char_time);


    time = -1;
    char_time = asctime(gmtime(&time));

    printf("time = %d  : %s", time, char_time);

    
    time = 0;
    char_time = asctime(gmtime(&time));

    printf("time = %d  : %s", time, char_time);
    return 0;
}
