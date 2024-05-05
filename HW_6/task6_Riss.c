#include <stdio.h>
#include <stdint.h>

int main(void){
    // uint64_t num;
    uint64_t num;
    uint64_t res;
    scanf("%lu", &num);
    res = 1lu << (num - 1);
    printf("%lu", res);
    return 0;
}