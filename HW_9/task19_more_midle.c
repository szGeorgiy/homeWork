#include <stdio.h>
#include <math.h>

#define MASS_LEN 25

void get_int_mass(int* mass, int len){
    for(int i = 0; i < len; i++){
        scanf("%d", &mass[i]);
    }
}

int get_midle(int *mass, int len){
    int ret = 0;
    int line_len = (int) sqrt(len);
    for(int i = 0; i < line_len; i++){
        ret += mass[i * line_len + i];
    }
    ret /= line_len;
    return ret;
}

int main(void){
    int matrix[MASS_LEN];
    int line_len = (int) sqrt(MASS_LEN);
    int midle;
    int my_numbers = 0;
    get_int_mass(matrix, MASS_LEN);
    midle = get_midle(matrix, MASS_LEN);
    for(int i = 0; i < MASS_LEN; i++){
        if (matrix[i] > midle){
            my_numbers++;
        }
    }
    printf("%d", my_numbers);
    return 0;
}