#include <stdio.h>

int main(void){
    int a, b, c;
    int sum = 0;
    int mult = 0;
    scanf("%d%d%d", &a, &b, &c);
    sum = a + b + c;
    mult = a * b * c;
    printf("%d+%d+%d=%d\n", a, b, c, sum);
    printf("%d*%d*%d=%d", a, b, c, mult);
    return 0;
}