#include <stdio.h>

#define MASS_LEN 10

void get_int_mass(int* mass, int len){
    for(int i = 0; i < len; i++){
        scanf("%d", &mass[i]);
    }
}

int condition(int number){
    number /= 10;
    if(number % 10 == 0){
        return 1;
    } else {
        return 0;
    }
}

int migration_int_mass(int* base_mass, int len, int* out_mass){
    int count = 0;
    for(int i = 0; i < len; i++){
        if(condition(base_mass[i])){
            out_mass[count] = base_mass[i];
            count++;
        }
    }
    return count;
}

int print_mass(int* mass, int len){
    if(len > 1){
        printf("%d", mass[0]);
        for(int i = 1; i<len; i++){
            printf(" %d", mass[i]);
        }
    }
}

int main(void){
    int input_mass[MASS_LEN] = {0};
    int output_mass[MASS_LEN] = {0};
    int output_size;
    get_int_mass(input_mass, MASS_LEN);
    output_size = migration_int_mass(input_mass, MASS_LEN, output_mass);
    print_mass(output_mass, output_size);
    return 0;
}