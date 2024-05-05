#include <stdio.h>

unsigned int factorial(unsigned int number){
    unsigned int res = 1;
    for(int i = 1; i <= number; i++){
        res *= i;
    }
    return res;
}

int main(void){
    unsigned int num, fact;
    scanf("%u", &num);
    printf("%u", factorial(num));
    return 0;
}