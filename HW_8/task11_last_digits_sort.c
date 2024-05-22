#include <stdio.h>

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

int condition(int num1, int num2){
    int condition;
    condition = num1 % 10 > num2 % 10;
    return condition;
}

void condition_bubble_sort(int* mass, int len){
    int tmp;
    for(int i = 0; i < len; i++){
        for(int j = i; j < len; j++){
            if(condition(mass[i], mass[j])){
                tmp = mass[j];
                mass[j] = mass[i];
                mass[i] = tmp;
            }
        }
    }
}

int main(void){
    int mass[MASS_LEN] = {0};
    get_int_mass(mass, MASS_LEN);
    condition_bubble_sort(mass, MASS_LEN);
    print_mass(mass, MASS_LEN);
    return 0;
}