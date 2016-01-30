#include <stdio.h>
#include <cs50.h>

/*
* Takes name and surname and output first letters in appercase
*/

int main(void){
    string s = GetString();
    char temp = s[0];
    if(temp > 64 && temp < 91){
        printf("%c", temp);
    } else {
        printf("%c", temp-32);
    }

    int i = 0;
    while (temp != 0){
        if(temp == 32){
            if(s[i+1] > 64 && s[i+1] < 91){
                printf("%c", s[i+1]);
            } else {
                printf("%c", s[i+1]-32);
            }
        }
        i++;
        temp = s[i];
    }
    printf("\n");

}