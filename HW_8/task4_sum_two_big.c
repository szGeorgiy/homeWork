#include <stdio.h>

#define MASS_LEN 10

void get_int_mass(int* mass, int len){
    for(int i = 0; i < len; i++){
        scanf("%d", &mass[i]);
    }
}

void bubble_sort_int(int* mass, int len){
    int tmp;
    for(int i = 0; i < len; i++){
        for(int j = i; j < len; j++){
            if(mass[i] > mass[j]){
                tmp = mass[j];
                mass[j] = mass[i];
                mass[i] = tmp;
            }
        }
    }
}

int main(void){
    int mass[MASS_LEN] = {0};
    int sum;
    get_int_mass(mass, MASS_LEN);
    bubble_sort_int(mass, MASS_LEN);
    sum = mass[MASS_LEN - 1] + mass[MASS_LEN - 2];
    printf("%d", sum);
    return 0;
}