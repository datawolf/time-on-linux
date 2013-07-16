/**
    gcc -lrt    -o 019-getdate  019-getdate.c
*/

#define _GNU_SOURCE     500
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main( int argc, char **argv)
{
    struct  tm      *tmp;
    int     j;

    for (j = 1;  j < argc; j++)
    {
        tmp = getdate(argv[j]);

        if ( tmp == NULL)
        {
            printf("Call %d failed: getdate_err = %d\n",
                    j, getdate_err);
            continue;
        }

        printf("Call %d (\"%s\") successded:\n", j, argv[j]);
        printf("   tm_sec =  %d\n", tmp->tm_sec);
        printf("   tm_min =  %d\n", tmp->tm_min);
        printf("   tm_hour =  %d\n", tmp->tm_hour);
        printf("   tm_mday =  %d\n", tmp->tm_mday);
        printf("   tm_mon =  %d\n", tmp->tm_mon);
        printf("   tm_year =  %d\n", tmp->tm_year);
        printf("   tm_wday =  %d\n", tmp->tm_wday);
        printf("   tm_yday =  %d\n", tmp->tm_yday);
        printf("   tm_isdst =  %d\n", tmp->tm_isdst);
    }

    exit(EXIT_SUCCESS);
}

/*

$ TFILE=$PWD/tfile
$ echo '%A'  > $TFILE
$ echo '%T'  >> $TFILE
$ echo '%F' >> $TFILE
$ cat tfile 
%A
%T
%F
$ date
Tue Jul 16 15:50:36 CST 2013
$ export  DATEMSK=$TFILE
$ ./019-getdate Tuesday '2009-12-28' '12:22:34'
Call 1 ("Tuesday") successded:
   tm_sec =  22
   tm_min =  51
   tm_hour =  15
   tm_mday =  16
   tm_mon =  6
   tm_year =  113
   tm_wday =  2
   tm_yday =  196
   tm_isdst =  0
Call 2 ("2009-12-28") successded:
   tm_sec =  22
   tm_min =  51
   tm_hour =  15
   tm_mday =  28
   tm_mon =  11
   tm_year =  109
   tm_wday =  1
   tm_yday =  361
   tm_isdst =  0
Call 3 ("12:22:34") successded:
   tm_sec =  34
   tm_min =  22
   tm_hour =  12
   tm_mday =  17
   tm_mon =  6
   tm_year =  113
   tm_wday =  3
   tm_yday =  197
   tm_isdst =  0

*/
