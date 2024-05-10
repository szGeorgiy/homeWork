#include <stdio.h>

int recurs_power(int num, int pow){
    static int ret = 1;
    if (pow > 0){
        ret *= num;
        recurs_power(num, pow - 1);
    } else {
        return 1;
    }
    return ret;
}

int main(void){
    int num, pow;
    int res;
    scanf("%d%d", &num, &pow);
    res = recurs_power(num, pow);
    printf("%d", res);
    return 0;
}