#include <cs50.h>
#include <stdio.h>
#include <math.h>

int getDigitFromNum( long num, int digit );
long power(int num, int digit);

int main(void) {
    
    int sum1 = 0;
    int productRes = 0;
    
    printf("Number: ");
    long number = GetLongLong();
    if (number >= 1000000000000 && number < 10000000000000) { //visa 13 digits
        printf("%d\n", (int)(number/1000000000000));
        if (number/1000000000000 == 4){
            for (int i = 0; i < 13; i += 2) {
                productRes = getDigitFromNum(number, i)*2;
                if (productRes > 9) {
                    sum1 += getDigitFromNum(productRes, 0);
                    sum1 += getDigitFromNum(productRes, 1);
                } else {
                    sum1 += productRes;
                }
            }
            for (int i = 1; i < 13; i += 2) {
                sum1 += getDigitFromNum(number, i);
            }
            printf("%d", sum1);
        } else {
            printf("not Visa");
        }
    } else if (number >= 100000000000000 && number < 10000000000000000) { //amex
        for (int i = 1; i < 15; i += 2) {
            productRes = getDigitFromNum(number, i)*2;
            printf("%d ", productRes);
            if (productRes > 9) {
                sum1 += getDigitFromNum(productRes, 0);
                sum1 += getDigitFromNum(productRes, 1);
            } else {
                sum1 += productRes;
            }
        }
        printf("\n%d\n", sum1);
        for (int i = 0; i < 15; i += 2) {
            sum1 += getDigitFromNum(number, i);
        }
        printf("%d\n", sum1);
    } else if (number >= 1000000000000000 && number < 100000000000000000) {
        
    } else {
        printf("not a number");
    }
    
}

    int getDigitFromNum( long num, int digit)
    {
        num /= power( 10, digit);
        //printf("gdf: %d, ", (int)num);
        return num % 10;
    }
    
    long power(int num, int digit)
    {
        long res = 1;
        for (int i = 0; i < digit; i++)
        {
            res *= num;
        }
        //printf("pow: %li", res);
    return res;
    }

