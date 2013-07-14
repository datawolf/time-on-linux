#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
    time_t          current;

    current = time(NULL);

    printf("The current time is : %s", asctime(localtime(&current)));

    return 0;
}
