#include <stdio.h>

int main(void){
    int num;
    int max;
    int condition = 1;
    int tmp;
    scanf("%d", &num);
    max = num % 10;
    num /= 10;
    while (num > 0){
        tmp = num % 10;
        if (max <= tmp){
            condition = 0;
            break;
        }
        max = num % 10;
        num /= 10;
    }
    if (condition){
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}