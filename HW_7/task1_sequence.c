#include <stdio.h>

void printf_sequence(int number){
    if(number > 1){
        printf_sequence(number-1);
    }
    printf("%d ", number);
}

int main(void){
    int number;
    scanf("%d", &number);
    printf_sequence(number);
    return 0;
}