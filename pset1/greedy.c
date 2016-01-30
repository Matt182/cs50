#include <cs50.h>
#include <stdio.h>

int main(void) {
    float change;
    int res, zz;
    res = 0;
    printf("O hai! How much change is owned?\n");
    change = GetFloat();
    while (change < 0){
        printf("How much change is owned?\n");
        change = GetFloat();
    }

    
    while (change >= 0.25){
        change -= 0.25;
        res++;
    }
    zz = change * 100;
    while (zz >= 10){
        zz -= 10;
        //printf("%d ", zz);
        res++;
    }
    while (zz >= 5){
        zz -= 5;
        //printf("%d ", zz);
        res++;
    }
    while (zz >=1){
        zz -= 1;
        //printf("%d ", zz);
        res++;
    }
    printf("%d\n", res);
}