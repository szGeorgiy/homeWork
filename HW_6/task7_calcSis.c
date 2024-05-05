#include <stdio.h>

void convert_and_print(unsigned int number, unsigned int base){
    unsigned int tmp;
    tmp = number % base;
    number /= base;
    if (number > 0){
        convert_and_print(number, base);
        printf("%u", tmp);
    } else {
        printf("%u", tmp);
    }
}

int main(void){
    unsigned int N, P;
    scanf("%u%u", &N, &P);
    convert_and_print(N, P);
    return 0;   
}