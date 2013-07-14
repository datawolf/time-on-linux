#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
    time_t          current, one_day_before;
    char            *char_ptr1, *char_ptr2;

    current = time(NULL);
    char_ptr1 = ctime(&current);

    printf("The current time is : %s", char_ptr1);

    one_day_before = current - 24*60*60;
    char_ptr2 = ctime(&one_day_before);

    printf("The time before one day is : %s", char_ptr2);
}
