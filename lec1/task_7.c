#include <stdio.h>
#include <stdint.h>

uint32_t my_func(uint32_t number){
    uint32_t ret;
    uint8_t N1 = 0;
    uint8_t N2 = 0;
    uint8_t N3 = 0;
    uint8_t N4 = 0;
    N1 = number;
    number >>= 8;
    N2 = number;
    number >>= 8;
    N3 = number;
    number >>=8;
    N4 = number;
    N4 = ~N4;
    ret = N4;
    ret <<= 8;
    ret |= N3;
    ret <<= 8;
    ret |= N2;
    ret <<= 8;
    ret |= N1;
    return ret;
    /*Я хочу в Индию*/
}

int main(void){
    uint32_t N;
    scanf("%u", &N);
    printf("%u", my_func(N));
    return 0;
}