#include <stdio.h>

void print_even(unsigned int number){
    if (number & 1){
        printf("NO");
    } else {
        printf("YES");
    }
}

unsigned int sum_of_digits(unsigned int number){
    unsigned int ret = 0;
    while (number > 0){
        ret += number % 10;
        number /= 10;
    }
    return ret;
}

int main(void){
    unsigned int number;
    scanf("%u", &number);
    print_even(sum_of_digits(number));
    return 0;
}