#include <stdio.h>

int main(void){
    int a, b, c;
    int sum = 0;
    scanf("%d%d%d", &a, &b, &c);
    sum = a + b + c;
    printf("%d+%d+%d=%d", a, b, c, sum);
    return 0;
}