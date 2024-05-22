#include <stdio.h>

#define MASS_LEN 12

void get_int_mass(int* mass, int len){
    for(int i = 0; i < len; i++){
        scanf("%d", &mass[i]);
    }
}

float get_middle(int* mass, int len){
    float ret = 0;
    for(int i = 0; i < len; i++){
        ret += mass[i];
    }
    ret /= len;
    return ret;
}

int main(void){
    int mass[MASS_LEN];
    float middle;
    get_int_mass(mass, MASS_LEN);
    middle = get_middle(mass, MASS_LEN);
    printf("%.2f", middle);
    return 0;
}