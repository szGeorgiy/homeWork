#include <stdio.h>

#define MASS_LEN 30

void get_int_mass(int* mass, int len){
    for(int i = 0; i < len; i++){
        scanf("%d", &mass[i]);
    }
}

void print_to_min_posicion(int *mass, int len){
    int min = mass[0];
    int min_posicion_1 = 0;
    int min_posicion_2;
    int tmp;
    for (int i = 1; i < len; i++){
        if (mass[i] < min){
            min = mass[i];
            min_posicion_1 = i;
        }
    }
    mass[min_posicion_1] = ((unsigned int) ~0 ) >> 1;
    min = mass[0];
    min_posicion_2 = 0;
    for (int i = 1; i < len; i++){
        if (mass[i] < min){
            min = mass[i];
            min_posicion_2 = i;
        }
    }
    if(min_posicion_1 > min_posicion_2){
        tmp = min_posicion_1;
        min_posicion_1 = min_posicion_2;
        min_posicion_2 = tmp;
    }
    printf("%d %d", min_posicion_1, min_posicion_2);
}

int main(void){
    int mass[MASS_LEN] = {0};
    get_int_mass(mass, MASS_LEN);
    print_to_min_posicion(mass, MASS_LEN);
    return 0;
}