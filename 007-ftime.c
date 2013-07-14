#include <stdio.h>
#include <sys/timeb.h>

int main(int argc, char **argv)
{
    struct  timeb   tp;
    time_t  time;

    ftime(&tp);
    time = tp.time;

    printf("the current time is : %d\n", time);
    printf("the millitm is : %d\n", tp.millitm);
    //timezone以分钟为单位，表示本地时间和UTC时间的偏离。
    //负值表示东时区。例如北京为东8区，该值为-480（60*8）
    printf("the timezone is : %d\n", tp.timezone);
    printf("the dstflag is : %d\n", tp.dstflag);

    return 0;
}
