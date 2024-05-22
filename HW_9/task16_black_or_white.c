#include <stdio.h>

int main(void){
    char symbol;
    int number;
    scanf("%c%d", &symbol, &number);
    if (symbol % 2 == 0){
        if (number % 2){
            printf("WHITE");
        } else {
            printf("BLACK");
        }
    } else {
        if (number % 2 == 0){
            printf("WHITE");
        } else {
            printf("BLACK");
        }
    }
    return 0;
}