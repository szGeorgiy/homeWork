#include <stdio.h>

unsigned int NOD(unsigned int num, unsigned int divider){
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

int main(void){
    unsigned int num1, num2;
    scanf("%u%u", &num1, &num2);
    printf("%u", NOD(num1, num2));
    return 0;
}