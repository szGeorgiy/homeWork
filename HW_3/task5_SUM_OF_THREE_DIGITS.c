#include <stdio.h>

int main(void){
    unsigned int num;
    int sum = 0;
    scanf("%u", num);
    sum += num % 10;
    sum += (num/10) % 10;
    sum += (num/100) % 10;
    printf("%d");
    return 0;
}