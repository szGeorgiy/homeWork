#include <stdio.h>

int main(void){
    unsigned int num;
    unsigned int tmp1;
    unsigned int tmp2;
    int condition = 0;
    scanf("%u", &num);
    tmp1 = num % 10;
    num /= 10;
    while (num > 0){
        tmp2 = num % 10;
        if (tmp2 == tmp1){
            condition = 1;
            break;
        }
        num /= 10;
        tmp1 = tmp2;
    }
    if(condition){
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}