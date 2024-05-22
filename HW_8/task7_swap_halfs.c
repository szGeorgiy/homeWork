#include <stdio.h>

#define MASS_LEN 10
#define FIRST_HIGH_CONDITION MASS_LEN / 4
#define SECOND_LOW_CONDITION MASS_LEN / 2
#define SECOND_HIGH_CONDITION MASS_LEN * 3 / 4
#define ADDRESS_SHIFT(i) i + (MASS_LEN / 4 - (i % (MASS_LEN / 2))) * 2

void get_int_mass(int* mass, int len){
    for(int i = 0; i < len; i++){
        scanf("%d", &mass[i]);
    }
}

int main(void){
    int mass[MASS_LEN] = {0};
    int tmp = 0;
    int bool;
    get_int_mass(mass, MASS_LEN);
    for(int i = 0; i < MASS_LEN; i++){
        if(i < FIRST_HIGH_CONDITION){
            tmp = mass[i]; 
            mass[i] = mass[ADDRESS_SHIFT(i)];
            mass[ADDRESS_SHIFT(i)] = tmp;
        }
        if(i >= SECOND_LOW_CONDITION && i < SECOND_HIGH_CONDITION){
            tmp = mass[i]; 
            mass[i] = mass[ADDRESS_SHIFT(i)];
            mass[ADDRESS_SHIFT(i)] = tmp;
        }
        printf("%d ", mass[i]);
    }
    return 0;
}