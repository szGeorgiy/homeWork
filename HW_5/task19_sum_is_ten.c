#include <stdio.h>

unsigned int sum_of_digits(unsigned int number){
    unsigned int res = 0;
    while (number > 0){
        res += number % 10;
        number /= 10;
    }
    return res;
}

int main(void){
    unsigned int num;
    int condition;
    scanf("%u", &num);
    condition = sum_of_digits(num) == 10;
    if(condition){
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}