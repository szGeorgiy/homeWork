#include <stdio.h>

unsigned int SUMM(unsigned int number){
    unsigned int sum = 0;
    while(number > 0){
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

unsigned int MULT(unsigned int number){
    unsigned int mult = 1;
    if(number == 0){
        return 0;
    }
    while (number > 0){
        mult *= number % 10;
        number /= 10;
    }
    return mult;
}

int is_happy_number(unsigned int number){
    if(SUMM(number) == MULT(number)){
        return 1;
    } else {
        return 0;
    }
}

int main(void){
    unsigned int number;
    scanf("%u", &number);
    if(is_happy_number(number)){
        printf("YES");
    } else {
        printf("NO");
    };
    return 0;
}