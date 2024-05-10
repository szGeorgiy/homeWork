#include <stdio.h>

void print_odd(void){
    int num;
    scanf("%d", &num);
    if(num){
        if(num & 1){
            printf("%d ", num);
        }
        print_odd();
    }
}

int main(void){
    print_odd();
    return 0;
}