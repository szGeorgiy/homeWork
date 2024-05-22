#include <stdio.h>

# define MASS_SIZE 5

int get_int_min(int* mass, int len){
    int min = mass[0];
    for(int i = 1; i < len; i++){
        if(mass[i] < min){
            min = mass[i];
        }
    }
    return min;
}

void get_int_mass(int* mass, int len){
    for(int i = 0; i < len; i++){
        scanf("%d", &mass[i]);
    }
}

int main(void){
    int mass[MASS_SIZE] = {0};
    int min;
    get_int_mass(mass, MASS_SIZE);
    min = get_int_min(mass, MASS_SIZE);
    printf("%d", min);
    return 0;
}