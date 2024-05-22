#include <stdio.h>
#include <math.h>

#define MASS_LEN 100

void get_int_mass(int* mass, int len){
    for(int i = 0; i < len; i++){
        scanf("%d", &mass[i]);
    }
}

int get_max_in_line(int *mass, int len, int line){
    int low_range = 0;
    int high_range = 0;
    int len_line = (int) sqrt(len);
    low_range = len_line * line;
    high_range = len_line * (line + 1);
    // printf("low = %d high = %d\n", low_range, high_range);
    int ret = mass[low_range];
    for(int i = low_range + 1; i < high_range; i++){
        if (mass[i] > ret){
            ret = mass[i];
        }
    }
    return ret;
}

int main(void){
    int matrix[MASS_LEN];
    int line_len = (int) sqrt(MASS_LEN);
    int sum = 0;
    get_int_mass(matrix, MASS_LEN);
    for(int i = 0; i < line_len; i++){
        sum += get_max_in_line(matrix, MASS_LEN, i);
    }
    printf("%d", sum);
    return 0;
}