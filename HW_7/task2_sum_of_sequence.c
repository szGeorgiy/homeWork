#include <stdio.h>

int rec_sum(int number){
    static int res = 0;
    if(number > 1){
        rec_sum(number-1);
    }
    res += number;
    return res;
}

int main(void){
    int number, sum;
    scanf("%d", &number);
    sum = rec_sum(number);
    printf("%d", sum);
    return 0;
}