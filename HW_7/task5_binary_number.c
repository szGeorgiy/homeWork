#include <stdio.h>

void print_binary(int num){
    int tmp;
    tmp = num % 2;
    num /= 2;
    if(num > 0){
        print_binary(num);
    }
    printf("%d", tmp);
}

int main(void){
    int num;
    scanf("%d", &num);
    print_binary(num);
    return 0;
}