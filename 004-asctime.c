#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
    struct  tm      *ptr;       /* the time struct */
    time_t          current, one_day_before;
    char            *char_ptr1, *char_ptr2;

    current = time(NULL);
    ptr = localtime(&current);
    char_ptr1 = asctime(ptr);

    printf("The current time is : %s", char_ptr1);

    one_day_before = current - 24*60*60;
    ptr = localtime(&one_day_before);
    char_ptr2 = asctime(ptr);

    printf("The time before one day is : %s", char_ptr2);
}
