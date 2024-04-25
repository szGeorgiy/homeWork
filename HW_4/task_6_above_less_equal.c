#include <stdio.h>

int main(void){
    int num1, num2;
    scanf("%d%d", &num1, &num2);
    if(num1 < num2){
        printf("Less");
    } else if (num1 > num2) {
        printf("Above");
    } else {
        printf("Equal");
    }
    return 0;
}