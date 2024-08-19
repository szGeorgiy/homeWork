#include <stdio.h>
#include <stdint.h>

uint32_t calc_ones(uint32_t number){
    uint32_t ret = 0;
    while (number){
        if (number & 1){
            ret++;
        }
        number >>= 1;
    }
    return ret;
}

int main(void){
    uint32_t N;
    scanf("%u", &N);
    printf("%u", calc_ones(N));
    return 0;
}