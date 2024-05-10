#include <stdio.h>

void print_prime_factors(int num, int factor){
    int condition;
    condition = num % factor;
    if(condition == 0){
        printf("%d ", factor);
        print_prime_factors(num / factor, factor);
    } else {
        if( factor < num){
            print_prime_factors(num, factor + 1);
        }
    }
}

int main(void){
    int num;
    scanf("%d", &num);
    print_prime_factors(num, 2);
    return 0;
}