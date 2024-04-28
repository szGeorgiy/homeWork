#include <stdio.h>

int main(void){
    unsigned int num;
    unsigned int tmp;
    unsigned int min;
    unsigned int max;
    scanf("%u", &num);
    if(num == 0){
        printf("0");
        return 0;
    }
    min = num % 10;
    max = num % 10;
    while(num > 0){
        tmp = num % 10;
        min = tmp < min ? tmp : min;
        max = tmp > max ? tmp : max;
        num /= 10;
    }
    printf("%u %u", min, max);
    return 0;
}