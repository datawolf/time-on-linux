#include <stdio.h>
#include <sys/select.h>

int main(int argc, char **argv)
{
    struct  timeval     tv = {
        .tv_sec = 1,
        .tv_usec = 500000
    };

    select (0, NULL, NULL, NULL, &tv);

    return 0;
}
