#include <stdio.h>
#include <time.h>


int main( int argc, char **argv)
{
    struct  tm      tm_time;
    time_t          t;
    
    tm_time.tm_year = 2013-1900;
    tm_time.tm_mon = 6;
    tm_time.tm_mday = 14;
    tm_time.tm_hour = 11;
    tm_time.tm_min = 12;
    tm_time.tm_sec = 13;
    tm_time.tm_isdst = 0;

    t = mktime(&tm_time);

    printf("The time is %s", ctime(&t));

    return 0;
}
