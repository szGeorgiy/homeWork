#include <stdio.h>

int main(void){
    unsigned int num;
    unsigned int d1, d2, d3;
    unsigned int mult;
    scanf("%u", &num);
    d1 = num % 10;
    num = num / 10;
    d2 = num % 10;
    num = num / 10;
    d3 = num % 10;
    mult = d1 * d2 * d3;
    printf("%u", mult);
}