#include <stdio.h>

int main(void){
    unsigned int num;
    unsigned int max = 0;

    scanf("%d", &num);
    
    max = num % 10;
    num = num / 10;
    
    if (max < num % 10){
        max = num % 10;
    }
    num = num / 10;
    
    if (max < num % 10){
        max = num % 10;
    }
    printf("%d", max);
    return 0;
}