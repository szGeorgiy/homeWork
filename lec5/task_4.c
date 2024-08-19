#include <stdio.h>

int calc_zeros(int num){
    int ret = 0;
    while (num){
        if ((num & 1) == 0){
            ret++;
        }
        num >>= 1;
    }
    return ret;
}

int main(void){
    int N, K;
    scanf("%d%d", &N, &K);
    int ret = 0;
    // printf("%d %d\n", N, K);
    for (int i = 1; i <= N; i++){
        if (calc_zeros(i) == K){
            ret++;
        }
    }
    printf("%d", ret);
    return 0;
}