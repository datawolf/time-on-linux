#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main()
{
    long    hz;

    hz = sysconf(_SC_CLK_TCK);

    if (hz == -1)
        perror("sysconf");

    printf("_SC_CLK_TCK = %d\n", hz);
    return 0;
}
