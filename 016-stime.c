#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    time_t      t;
    int         ret;

    t = time(NULL);

    t -= 60*60;
    
    ret = stime(&t);

    if (ret != 0)
    {
        perror("stime");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;

}
