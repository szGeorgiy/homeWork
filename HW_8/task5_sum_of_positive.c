#include <stdio.h>

#define MASS_LEN 10

void get_int_mass(int* mass, int len){
    for(int i = 0; i < len; i++){
        scanf("%d", &mass[i]);
    }
}

int sum_positive(int* mass, int len){
    int ret = 0;
    for(int i = 0; i < len; i++){
        if(mass[i] > 0){
            ret += mass[i];
        }
    }
    return ret;
}

int main(void){
    int mass[MASS_LEN];
    int sum;
    get_int_mass(mass, MASS_LEN);
    sum = sum_positive(mass, MASS_LEN);
    printf("%d", sum);
    return 0;
}