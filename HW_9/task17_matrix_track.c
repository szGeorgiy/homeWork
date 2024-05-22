#include <stdio.h>
#include <math.h>

#define MASS_LEN 25

void get_int_mass(int* mass, int len){
    for(int i = 0; i < len; i++){
        scanf("%d", &mass[i]);
    }
}

int main(void){
    int matrix[MASS_LEN];
    int track = 0;
    int sqr = (int) sqrt(MASS_LEN);
    get_int_mass(matrix, MASS_LEN);
    for(int i = 0; i < sqr; i++){
        track += matrix[i * sqr + i];
    }
    printf("%d", track);
    return 0;
}