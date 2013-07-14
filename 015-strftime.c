#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( int argc, char **argv)
{
    char outstr[200];
    time_t  t;
    struct  tm  *tmp;

    t = time(NULL);
    tmp = localtime(&t);
    if (tmp == NULL)
    {
        perror("localtime");
        exit(EXIT_FAILURE);
    }
    
    if (strftime(outstr, sizeof(outstr), argv[1], tmp) == 0)
    {
        fprintf(stderr, "strftime returned 0");
        exit(EXIT_FAILURE);
    }

    printf("Result string is \"%s\"\n", outstr);

    exit(EXIT_SUCCESS);
}   /* main */

/*

$ gcc 015-strftime.c -o 015-strftime
$ ./015-strftime "%m"
Result string is "07"
$ ./015-strftime "%5m"
Result string is "00007"
$ ./015-strftime "%_5m"
Result string is "    7"
$ ./015-strftime "%H%p"
Result string is "18PM"

   */
