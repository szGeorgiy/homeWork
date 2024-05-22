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

int nuber_remainder(int *mass, int len, int divider, int remainder){
    int ret = 0;
    for(int i = 0; i < len; i++){
        if (mass[i] % divider == remainder){
            ret++;
        }
    }
    return ret;
}

int multiplicate_digits(int number, int divider, int remainder){
    int ret = 1;
    int tmp;
    while (number > 0){
        tmp = number % 10;
        if (tmp % divider == remainder){
            ret *= tmp;
        }
        number /= 10;
    }
    return ret;   
}

void mass_transform(int *mass, int len, int divider, int remainder){
    for(int i = 0; i < len; i++){
        if (mass[i] % divider == remainder){
            mass[i] = multiplicate_digits(mass[i], divider, remainder);
        }
    }
}

int main(void){
    int mass[MASS_LEN];
    int number_even;
    int number_odd;
    get_int_mass(mass, MASS_LEN);
    number_even = nuber_remainder(mass, MASS_LEN, 2, 0);
    number_odd = nuber_remainder(mass, MASS_LEN, 2, 1);
    if (number_even > number_odd){
        mass_transform(mass, MASS_LEN, 2, 1);
    } else {
        mass_transform(mass, MASS_LEN, 2, 0);
    }
    print_mass(mass, MASS_LEN);
    return 0;
}