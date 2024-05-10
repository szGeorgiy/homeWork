#include <stdio.h>

int amount_ones(int num){
    static int ret = 0;
    ret += num & 1;
    if(num > 0){
        amount_ones(num >> 1);
    }
}

int main(void){
    int num;
    int amount;
    scanf("%d", &num);
    amount = amount_ones(num);
    printf("%d", amount);
    return 0;
}