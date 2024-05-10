#include <stdio.h>

void print_digits(int num){
    int tmp;
    tmp = num % 10;
    if (num / 10 > 0){
        print_digits(num / 10);
    }
    printf("%d ", tmp);
}

int main(void){
    int num;
    scanf("%d", &num);
    print_digits(num);
    return 0;
}