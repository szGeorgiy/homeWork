#include <stdio.h>

int main(void){
    int a, b, c;
    float res;
    scanf("%d%d%d", &a, &b, &c);
    res = ((float) a + (float) b + (float) c) / 3;
    printf("%.2f", res);
    return 0;
}