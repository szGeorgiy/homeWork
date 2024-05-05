#include <stdio.h>

int middle (int num1, int num2){
    int res;
    res = (num1 + num2)/2;
    return res;
}

int main(void){
    int num1, num2;
    int res;
    scanf("%d%d", &num1, &num2);
    res = middle(num1, num2);
    printf("%d", res);
    return 0;
}