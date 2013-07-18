#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>


static void sig_alarm(int signo)
{
    /* nothing to do, just return to interrupt the read. */
    printf("time out\n");
}

int main(int argc, char **argv)
{
    int     n;
    char    line[300];

    if (signal(SIGALRM, sig_alarm) == SIG_ERR)
    {
        perror("signal(SIGALRM) error");
        exit (0);
    }
    
    alarm(10);
    if ((n = read(STDIN_FILENO, line, 300)) < 0)
    {
        perror("read error");
        exit(0);
    }

    alarm(0);

    write(STDOUT_FILENO, line, n);

    exit(0);
}
/*
 * 在linux下，系统调用是重新启动的，当从SIGALRM信号
 * 处理程序返回时，read并不被中断，此时，设置时间
 * 限制不起作用。i
 *
 * 详细请参考：APUE page 256页
 *
 * */


