#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int minutes, botles;
    printf("minutes: ");
    minutes = GetInt();
    botles = 12 * minutes;
    printf("bottles: %d\n", botles);
}