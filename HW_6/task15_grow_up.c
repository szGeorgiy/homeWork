#include <stdio.h>

int grow_up(int number){
    int tmp1 = 0, tmp2 = 0;
    int condition = 1;
    tmp1 = number % 10;
    number /= 10;
    while (number > 0){
        tmp2 = tmp1;
        tmp1 = number % 10;
        number /= 10;
        if (tmp2 <= tmp1){
            condition = 0;
        }
    }
    return condition;
}

int main(void){
    int number;
    scanf("%u", &number);
    if (grow_up(number)){
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}