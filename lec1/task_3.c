#include <stdio.h>
#include <stdint.h>

uint32_t cycle_right_roll(uint32_t number, uint32_t roll){
    uint32_t tmp;
    for(int i = 0; i < roll; i++){
        tmp = number & 1;
        tmp <<= 31;
        number >>= 1;
        number |= tmp;
    }
    return number;
}

int main(void){
    uint32_t  N;
    uint32_t K; 
    scanf("%u", &N);
    scanf("%u", &K);
    printf("%u", cycle_right_roll(N, K));
    return 0;
}