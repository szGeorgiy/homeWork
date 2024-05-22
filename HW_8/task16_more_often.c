#include <stdio.h>

#define MASS_LEN 10

int print_mass(int* mass, int len){
    if(len > 1){
        printf("%d", mass[0]);
        for(int i = 1; i<len; i++){
            printf(" %d", mass[i]);
        }
    }
}

void get_int_mass(int* mass, int len){
    for(int i = 0; i < len; i++){
        scanf("%d", &mass[i]);
    }
}

int get_max_posicion(int* mass, int len){
    int max = mass[0];
    int posicion = 0;
    for(int i = 1; i < len; i++){
        if(mass[i] > max){
            max = mass[i];
            posicion = i;
        }
    }
    return posicion;
}

void calc_frequensi(int* mass, int len, int* out_mass){
    int count;
    for(int i = 0; i < len; i++){
        count = 0;
        for(int j = 0; j < len; j++){
            if(mass[i] == mass[j]){
                count++;
            }
        }
        out_mass[i] = count;
    }
}

int main(void){
    int mass[MASS_LEN] = {0};
    int freq_mass[MASS_LEN] = {0};
    get_int_mass(mass, MASS_LEN);
    calc_frequensi(mass, MASS_LEN, freq_mass);
    printf("%d", mass[get_max_posicion(freq_mass, MASS_LEN)]);
    return 0;
}