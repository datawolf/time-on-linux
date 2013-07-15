#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>



static void pr_times(clock_t t, struct tms *start, struct tms *end);
static void do_cmd(char *cmd);

int main(int argc, char ** argv)
{
    int     i;

    for (i = 1; i < argc; i++)
        do_cmd(argv[i]);

    exit(0);
}


static void pr_times(clock_t t, struct tms *start, struct tms *end)
{
    static long     clktck = 0;
    
    if (clktck == 0)
        if ((clktck = sysconf(_SC_CLK_TCK)) < 0)
            perror("sysconf");

    printf("\t: real  %7.2f\n", t / (double)clktck);
    printf("\t: user %7.2f\n", (end->tms_utime - start->tms_utime) / (double)clktck);
    printf("\t: sys %7.2f\n",(end->tms_stime - start->tms_stime) / (double)clktck);
    printf("\t: child user %7.2f\n",(end->tms_cutime - start->tms_cutime) / (double)clktck);
    printf("\t: child sys %7.2f\n",(end->tms_cstime - start->tms_cstime) / (double)clktck);
}

static void do_cmd(char *cmd)
{
    struct  tms tmsstart, tmsend;
    clock_t start, end;
    int status;

    printf("command: %s\n", cmd);
    
    if ((start = times(&tmsstart)) == -1)
        perror("times");
    
    if ((status = system(cmd)) < 0)
        perror("system");

    if ((end = times(&tmsend)) == -1)
        perror("times");

    pr_times(end-start, &tmsstart, &tmsend);
}

/*

$ ./a.out "sleep 5" date
command: sleep 5
        : real     5.00
        : user    0.00
        : sys    0.00
        : child user    0.00
        : child sys    0.00
command: date
2013年 07月 15日 星期一 09:56:26 CST
        : real     0.00
        : user    0.00
        : sys    0.00
        : child user    0.00
        : child sys    0.00

*/
