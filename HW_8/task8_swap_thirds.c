#include <stdio.h>

#define MASS_LEN 12

#define ADDRESS_LOW(i) i * MASS_LEN / 3
#define ADDRESS_HIGH(i) ADDRESS_LOW(i) + MASS_LEN / 3 - 1

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

void inversion_part(int* mass, int bottom, int up){
    int tmp;
    int my_len;
    int half_len;
    my_len = (up - bottom ) / 2;
    for(int i = 0; i <= my_len; i++){
        tmp = mass[bottom + i];
        mass[bottom + i] = mass[up - i];
        mass[up - i] = tmp; 
    }
}

int main(void){
    int mass[MASS_LEN] = {0};
    get_int_mass(mass, MASS_LEN);
    for(int i = 0; i < 3; i++){
        inversion_part(mass, ADDRESS_LOW(i), ADDRESS_HIGH(i));
    }
    print_mass(mass, MASS_LEN);
    return 0;
}