#include <stdio.h>

#define LEN 1000

int is_symbol(char symbol){
    int condition = 1;
    condition &= symbol != '\n';
    condition &= symbol != '\r';
    condition &= symbol != 0;
    return condition;
}

int read_file_char(FILE *file, char *mass, int max_len){
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

int main(void){
    FILE *input_file;
    FILE *output_file;
    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");
    char in_mass[LEN] = {0};
    int in_mass_len;
    char out_mass[LEN] = {0};
    int out_mass_len;
    in_mass_len = read_file_char(input_file, in_mass, LEN);
    /* Первый элемент */
    // int condition = 1;
    int tmp;
    for(int i = 0; i < in_mass_len - 1; i++){
        if (in_mass[i] == in_mass[in_mass_len-1]){
            tmp = i;
            fprintf(output_file, "%d", i);
            break;
        }
    }
    for(int i = tmp + 1; i < in_mass_len - 1; i++){
        if (in_mass[i] == in_mass[in_mass_len-1]){
            fprintf(output_file, " %d", i);
        }
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}