#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

/*
сделать граници если цифра больше по кодировке ascii
*/

int main(int argc, string argv[]){
    string codeWord = argv[1];
    string message = GetString();
    string tempStr = message;
    char z = message[0];
    int i = 0;
    int j = 0;
    
    while (z != 0){
        z = tempStr[i];
        if (z == 32){
            tempStr[i] = (char)32;
            printf("%c", tempStr[i]);
            i++;
            continue;
        }

        
        if (z > 64 && z < 91){
            tempStr[i] += (codeWord[j] - 97);
            if (tempStr[i] > 90) {
                tempStr[i] = 64 + (tempStr[i]-90);
            }
        } else if (z > 96 && z < 123) {
            tempStr[i] += (codeWord[j] - 97);
            if (tempStr[i] > 122) {
                tempStr[i] = 96 + (tempStr[i]-122);
            }
        } else {
            tempStr[i] = z;
        }
        
        printf("%c", tempStr[i]);
        i++;
        if (codeWord[j+1] != 0){
            j++;
        } else {
            j = 0;
        }
    }
    printf("\n");
/*    
    z = message[0];
    i = 0;
    while (z != 0){
        if (z == 32){
            printf("%c", message[i]);
            i++;
            z = message[i];
            continue;
        }
        message[i] = message[i] + (tempStr[i]-97);
        printf("%c", message[i]);
        i++;
        z = message[i];
    }
*/    
}