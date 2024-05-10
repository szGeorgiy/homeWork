#include <stdio.h>

int is_prime(int n, int delitel){
    static int conditon = 1;
    if (n == 1){
        return 0;
    }
    if (delitel > 1){
        if ( (n % delitel) == 0){
            conditon = 0;
        } else {
            is_prime( n, delitel - 1);
        }
    }
    return conditon;
}

int main(void){
    int num;
    scanf("%d", &num);
    if (is_prime(num, num / 2)){
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}