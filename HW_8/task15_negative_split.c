#include <stdio.h>

#define MASS_LEN 10

void get_int_mass(int* mass, int len){
    for(int i = 0; i < len; i++){
        scanf("%d", &mass[i]);
    }
}

int positive_condition(int number){
    if(number > 0){
        return 1;
    } else {
        return 0;
    }
}

int negative_condition(int number){
    if(number < 0){
        return 1;
    } else {
        return 0;
    }
}

int migration_positive(int* base_mass, int len, int* out_mass){
    int count = 0;
    for(int i = 0; i < len; i++){
        if(positive_condition(base_mass[i])){
            out_mass[count] = base_mass[i];
            count++;
        }
    }
    return count;
}

int migration_negative(int* base_mass, int len, int* out_mass){
    int count = 0;
    for(int i = 0; i < len; i++){
        if(negative_condition(base_mass[i])){
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
    int positive_mass[MASS_LEN] = {0};
    int negative_mass[MASS_LEN] = {0};
    int positive_size;
    int negative_size;
    get_int_mass(input_mass, MASS_LEN);
    positive_size = migration_positive(input_mass, MASS_LEN, positive_mass);
    negative_size = migration_negative(input_mass, MASS_LEN, negative_mass);
    print_mass(positive_mass, positive_size);
    printf(" ");
    print_mass(negative_mass, negative_size);
    return 0;
}