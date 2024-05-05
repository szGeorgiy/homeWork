#include <stdio.h>

unsigned int sum(unsigned int num){
    unsigned int res = 0;
    for(int i = 0; i <= num; i++){
        res += i;
    }
    return res;
}

int main(void){
    unsigned int num, res;
    scanf("%d", &num);
    res = sum(num);
    printf("%u", res);
    return 0;
}