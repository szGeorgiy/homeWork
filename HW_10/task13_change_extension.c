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

int get_last_posicion(char *mass, int len, char symbol){
    int posicion = 0;
    for(int i = 0; i < len; i++){
        if (mass[i] == symbol){
            posicion = i;
        }
    }
    return posicion;
}

void copy_mass(char *copy, char *paste, int len){
    for(int i = 0; i < len; i++){
        paste[i] = copy[i];
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
    input_file = fopen("input.txt", "r");
    FILE *output_file;
    output_file = fopen("output.txt", "w");
    char in_mass[FILE_LEN] = {0};
    int in_mass_len;
    char out_mass[FILE_LEN] = {0};
    int out_mass_len;
    in_mass_len = read_file_char(input_file, in_mass);
    char html[] = "html";
    char dot_html[] = ".html";
    int last_slash;
    int last_dot;

    last_slash = get_last_posicion(in_mass, in_mass_len, '/');
    last_dot = get_last_posicion(in_mass, in_mass_len, '.');

    printf("in mass len = %d\n", in_mass_len);
    printf("ld = %d, ls = %d\n", last_dot, last_slash);

    if (last_dot > last_slash){
        copy_mass(in_mass, out_mass, last_dot);
        write_file_char(output_file, out_mass, last_dot);
        fprintf(output_file, ".html");
    } else {
        copy_mass(in_mass, out_mass, in_mass_len);
        write_file_char(output_file, out_mass, in_mass_len);
        fprintf(output_file, ".html");
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}
