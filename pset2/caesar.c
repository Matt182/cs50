#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, string argv[]){
    
    if(argc > 2 || argc < 2){
        return 0;
    }
    
    int k = atoi(argv[1]);
    while(k > 25){
        k -= 26;
    }
    string text = GetString();
    int temp = text[0];
    int i = 0;
    while(temp != 0){
        if(temp > 64 && temp < 91){
            if(temp + k > 90){
                text[i] += (k - 26);
            } else {
                text[i] += k;
            }
        } else if(temp > 96 && temp < 123){
            if(temp + k > 122){
                text[i] += (k - 26);
            } else {
                text[i] += k;
            }
        } else {
            printf("%c", text[i]);
            i++;
            temp = text[i];
            continue;
        }
        printf("%c", text[i]);
        i++;
        temp = text[i];
    }
    printf("\n");
}