#include <stdio.h>
#include <time.h>


int main(int argc, char **argv)
{
    struct tm       *tm_loc, * tm_gm;
    time_t          t;

    t = time(NULL);
    tm_loc = localtime(&t);

    printf("Local Time and date: %s", asctime(tm_loc));

    tm_gm = gmtime(&t);
    printf("Coordinated Universal Time and date: %s", asctime(tm_gm));

    return 0;
}
