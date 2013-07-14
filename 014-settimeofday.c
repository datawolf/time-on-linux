#include <stdio.h>
#include <sys/time.h>


int main(int argc, char **argv)
{
    struct  timeval     tv;
    struct  timezone    tz;
    int state;

    gettimeofday(&tv, &tz);

    printf("****** Before call function settimeofday: ******\n");
    printf("tv_sec : %d\n", tv.tv_sec );
    printf("tv_usec : %d\n", tv.tv_usec );
    printf("tz_minuteswest : %d\n", tz.tz_minuteswest);
    printf("tz_dsttime : %d\n", tz.tz_dsttime );

    tv.tv_sec -= 60*60;
    tz.tz_minuteswest -= 1;
    
    state = settimeofday(&tv, &tz);

    if (state != 0)
    {
        perror("Failed settimeofday");
        exit(1);
    }

    
    gettimeofday(&tv, &tz);

    printf("****** After call function settimeofday: ******\n");
    printf("tv_sec : %d\n", tv.tv_sec );
    printf("tv_usec : %d\n", tv.tv_usec );
    printf("tz_minuteswest : %d\n", tz.tz_minuteswest);
    printf("tz_dsttime : %d\n", tz.tz_dsttime );

    return 0;
}

/*
$ date
2013年 07月 14日 星期日 17:28:10 CST
$ sudo ./014-settimeofday
****** Before call function settimeofday: ******
tv_sec : 1373794094
tv_usec : 715280
tz_minuteswest : -482
tz_dsttime : 0
****** After call function settimeofday: ******
tv_sec : 1373797694
tv_usec : 715298
tz_minuteswest : -483
tz_dsttime : 0
$ date
2013年 07月 14日 星期日 18:28:18 CST

*/
