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

void transform_mass(char *in_mass, char *out_mass, int len){
    char tmp;
    for(int i = 0; i < len; i++){
        tmp = in_mass[i];
        switch (tmp){
        case 'a':
            tmp = 'b';
            break;
        case 'A':
            tmp = 'B';
            break;
        case 'b':
            tmp = 'a';
            break;
        case 'B':
            tmp = 'A';
            break;
        default:
            break;
        }
        out_mass[i] = tmp;
    }
}

void write_file_char(FILE *file, char *mass, int len){
    int count = 0;
    while (count < len){
        fprintf(file, "%c", mass[count]);
        count++;
    }
}

int main(void){
    FILE *input_file;
    FILE *output_file;
    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");
    char in_mass[FILE_LEN] = {0};
    int in_mass_len;
    char out_mass[FILE_LEN] = {0};
    int out_mass_len;
    in_mass_len = read_file_char(input_file, in_mass);
    out_mass_len = in_mass_len;
    transform_mass(in_mass, out_mass, in_mass_len);
    write_file_char(output_file, out_mass, out_mass_len);
    fclose(input_file);
    fclose(output_file);
    return 0;
}