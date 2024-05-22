#include <stdio.h>

#define MASS_LEN 10

void get_int_mass(int* mass, int len){
    for(int i = 0; i < len; i++){
        scanf("%d", &mass[i]);
    }
}

int main(void){
    int mass[MASS_LEN] = {0};
    int max_posicion = 1;
    int max;
    int min_posicion = 1;
    int min;
    get_int_mass(mass, MASS_LEN);
    max = mass[0];
    min = mass[0];
    for(int i = 1; i < MASS_LEN; i++){
        if(max < mass[i]){
            max = mass[i];
            max_posicion = i + 1;
        }
        if(min > mass[i]){
            min = mass[i];
            min_posicion = i + 1;
        }
    }
    printf("%d %d %d %d", max_posicion, max, min_posicion, min);
    return 0;
}