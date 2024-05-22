#include <stdio.h>

#define MASS_LEN 12

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

void int_right_roll(int* mass, int len, int rolls){
    /* Если количество циклических сдвигов равно
       длинне массива, то сдвига не происходит
    */
    while (rolls >= len){
        rolls -= len;
    }
    if(rolls){
        /* Временный массив хранит элементы "вытолкнутые вправо"*/
        int tmp_mass[rolls];
        for(int i = 0; i < rolls; i++){
            tmp_mass[i] = mass[i+(len - rolls)];
        }
        /* Сдвинуть элементы массива на rolls */
        for(int i = len - 1; i > rolls - 1; i--){
            mass[i] = mass[i - rolls];
        }
        /* Добавить вытолкнутые элементы */
        for(int i = 0; i < rolls; i++){
            mass[i] = tmp_mass[i];
        }

    }
}


int main(void){
    int input_mass[MASS_LEN] = {0};
    get_int_mass(input_mass, MASS_LEN);
    int_right_roll(input_mass, MASS_LEN,4);
    print_mass(input_mass, MASS_LEN);
}