#include <stdio.h>

unsigned int factorial(unsigned int num){
    unsigned int ret = 1;
    for (int i = 2; i <= num; i++){
        ret *= i;
    }
    return ret;
}

float power(float num, unsigned int pow){
    float ret = 1;
    for(int i = 0; i < pow; i++){
        ret *= num;
    }
    return ret;
}

float sinus(float x){
    float ret;
    int sign;
    ret = x;
    for(int i = 1; i <= 9; i++){
        if (i & 1){
            sign = -1;
        } else {
            sign = 1;
        }
        ret += sign*(power(x, i + i + 1) / factorial(i + i + 1));
    }
    return ret;
}

int main(void){
    float x, sin;
    scanf("%f", &x);
    sin = sinus(x*3.1415/180);
    printf("%.3f", sin);
    return 0;
}