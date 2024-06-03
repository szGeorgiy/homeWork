#include <stdio.h>

#define FILE_LEN 1000

int is_symbol(char symbol){
    int condition = 1;
    condition &= symbol != '\n';
    condition &= symbol != '\r';
    condition &= symbol != 0;
    return condition;
}

int read_file_char(FILE *file, char *mass){
    char symbol;
    int count = 0;
    while (fscanf(file, "%c", &symbol) == 1){
        if (is_symbol(symbol)){
            mass[count] = symbol;
            count++;
        } else {
            break;
        }
    }
    return count;
}

int calc_a_ending(char *mass){
    int ret = 0;
    int count = 0;
    while (1){
        /* Условие выхода */
        if (mass[count] == 0){
            if (mass[count - 1] == 'a'){
                ret++;
            }
            break;
        }
        if (mass[count] == ' '){
            if (mass[count - 1] == 'a'){
                ret++;
            }
        }
        count++;
    }
    return ret;
}

int main(void){
    FILE *input_file;
    input_file = fopen("input.txt", "r");
    FILE *output_file;
    output_file = fopen("output.txt", "w");
    char in_mass[FILE_LEN] = {0};
    int out;

    read_file_char(input_file, in_mass);
    out = calc_a_ending(in_mass);
    fprintf(output_file, "%d", out);

    fclose(input_file);
    fclose(output_file);
    return 0;
}