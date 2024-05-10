#include <stdio.h>

int sum_digits(int num){
    static int ret = 0;
    ret += num % 10;
    if(num > 0){
        sum_digits(num / 10);
    }
}

int main(void){
    int num;
    scanf("%d", &num);
    printf("%d", sum_digits(num));
    return 0;
}