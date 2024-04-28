#include <stdio.h>

unsigned int sum_of_digits(unsigned int number){
    unsigned int res = 0;
    while (number > 0){
        res += number % 10;
        number /= 10;
    }
    return res;
}

unsigned int mult_of_digits(unsigned int number){
    unsigned int res = 1;
    if(number == 0){
        return 0;
    }
    while(number > 0){
        res *= number % 10;
        number /= 10;
    }
    return res;
}

int main(void){
    unsigned int counter = 10;
    unsigned int ground;
    int sum, mult;
    scanf("%u", &ground);
    while (counter <= ground){
        sum = sum_of_digits(counter);
        mult = mult_of_digits(counter);
        if( sum == mult){
            printf("%u", counter);
            counter++;
            break;
        }
        counter++;
    }
    while( counter <= ground){
        sum = sum_of_digits(counter);
        mult = mult_of_digits(counter);
        if(sum == mult){
            printf(" %u", counter);
        }
        counter++;
    }
    return 0;
}