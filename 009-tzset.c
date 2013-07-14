#include <stdio.h>
#include <time.h>


int main( int argc, char **argv)
{
    time_t          td;

    putenv("TZ=PST8PDT");
    tzset();

    time(&td);

    printf("The Current time = %s", asctime(localtime(&td)));

    return 0;
}
