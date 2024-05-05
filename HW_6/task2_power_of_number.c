#include <stdio.h>

int power(int num, unsigned int pow){
    int res;
    if (pow == 0){
        return 1;
    } else {
        res = num;
        for(unsigned int i = 1; i < pow; i++){
            res *= num;
        }
    }
    return res;
}

int main(void){
    int n;
    unsigned int p;
    int res;
    scanf("%d%u", &n, &p);
    res = power(n, p);
    printf("%d", res);
    return 0;
}