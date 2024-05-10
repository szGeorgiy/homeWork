#include <stdio.h>

void printf_sequence(int number){
    if(number > 0){
        printf("%d ", number);
        printf_sequence(number-1);
    }
}

int main(void){
    int number;
    scanf("%d", &number);
    printf_sequence(number);
    return 0;
}