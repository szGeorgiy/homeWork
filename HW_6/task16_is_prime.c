#include <stdio.h>

int NOD(int num, int divider){
    while (num > 0){
        if (num > divider){
            num -= divider;
        }
        if (num < divider){
            divider -= num;
        }
        if (num == divider){
            return num;
        }
    }
}

int is_prime(int number){
    int condition = 1;
    int tmp;
    int grownd = number / 2;
    for(int i = 2; i <= grownd; i++){
        tmp = NOD(i, number);
        if (tmp != 1){
            condition = 0;
            break;
        }
    }
    return condition;
}

int main(void){
    int number;
    scanf("%d", &number);
    if (number <=1){
        printf("NO");
        return 0;
    }
    if(is_prime(number)){
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}