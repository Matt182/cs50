#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int height, i, j;
    printf("Height: ");
    
    height = GetInt();
    while(height > 23 || height < 0) {
        printf("Retry: ");
        height = GetInt();
    }
    
    for (i = 0; i < height; i++) {
        for (j = 0; j < (height-1)-i; j++) {
            printf(" ");
        }
        for (j = 0; j < i+2; j++) {
            printf("#");
        }
        printf("\n");
    }
}