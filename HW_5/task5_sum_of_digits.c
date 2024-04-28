#include <stdio.h>

int main(void){
    unsigned int num;
    unsigned int sum = 0;
    scanf("%u", &num);
    while (num > 0){
        sum += num % 10;
        num /= 10;
    }
    printf("%u", sum);
    return 0;
}