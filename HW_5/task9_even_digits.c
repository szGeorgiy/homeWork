#include <stdio.h>

int main(void){
    int num;
    int even = 1;
    int condition;
    scanf("%d", &num);
    while(num > 0){
        condition = (num % 10) & 1;
        if(condition){
            even = 0;
            break;
        }
        num /= 10;
    }
    if (even){
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}