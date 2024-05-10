#include <stdio.h>

void printf_digits(int number){
    int tmp;
    tmp = number % 10;
    number /= 10;
    if(number > 0){
        printf_digits(number);
    }
    printf("%d ", tmp);
}

int main(void){
    int number;
    scanf("%d", &number);
    printf_digits(number);
    return 0;
}