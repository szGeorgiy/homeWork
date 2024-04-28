#include <stdio.h>

int main(void){
    unsigned int num1, num2;
    scanf("%u%u", &num1, &num2);
    while( num1 != num2){
        if(num1 > num2){
            num1 -= num2;
        } else {
            num2 -= num1;
        }
    }
    printf("%u", num1);
    return 0;
}