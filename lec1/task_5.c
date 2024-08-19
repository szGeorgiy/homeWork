#include <stdio.h>

unsigned int take_max(unsigned int num, unsigned int bits){
    unsigned int max;
    unsigned int mask = 0;
    for(int i = 0; i < bits; i++){
        mask <<= 1;
        mask |= 1;
    }
    max = num & mask;
    unsigned int tmp;
    while (num > 0){
        num >>= 1;
        tmp = num & mask;
        if (tmp > max){
            max = tmp;
        }
    }
    return max;
}

int main(void){
    unsigned int N;
    unsigned int K;
    scanf("%u", &N);
    scanf("%u", &K);
    printf("%u", take_max(N, K));
    return 0;
}