#include <stdio.h>
#include <time.h>

#define LOOP_LIMITS 0XFFFFFFF

int main(int argc, char **argv)
{
    time_t      time1, time2;

    unsigned long   t;
    
    time1 = time(NULL);
    for ( t = 0; t < LOOP_LIMITS; t++)
        ;
    time2 = time(NULL);

    printf("The loop took %f seconds\n", difftime(time2, time1));
    printf("The loop took %f seconds\n", time2 - time1);
}
