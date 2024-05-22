#include <stdio.h>;

#define MASS_LEN 10

void get_int_mass(int* mass, int len){
    for(int i = 0; i < len; i++){
        scanf("%d", &mass[i]);
    }
}

int print_mass(int* mass, int len){
    if(len > 1){
        printf("%d", mass[0]);
        for(int i = 1; i<len; i++){
            printf(" %d", mass[i]);
        }
    }
}

void ascending_sort(int* mass, int bottom, int up){
    int tmp;
    for(int i = bottom; i < up; i++){
        for(int j = i; j < up; j++){
            if(mass[i] > mass[j]){
                tmp = mass[j];
                mass[j] = mass[i];
                mass[i] = tmp;
            }
        }
    }
}

void descending_sort(int* mass, int bottom, int up){
    int tmp;
    for(int i = bottom; i < up; i++){
        for(int j = i; j < up; j++){
            if(mass[i] < mass[j]){
                tmp = mass[j];
                mass[j] = mass[i];
                mass[i] = tmp;
            }
        }
    }
}

int main(void){
    int input_mass[MASS_LEN] = {0};
    get_int_mass(input_mass, MASS_LEN);
    ascending_sort(input_mass, 0, MASS_LEN/2);
    descending_sort(input_mass,MASS_LEN / 2, MASS_LEN);
    print_mass(input_mass, MASS_LEN);
    return 0;
}