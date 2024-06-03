#include <stdio.h>

#define FILE_LEN

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

void write_file_char(FILE *file, char *mass){
    int count = 0;
    while (mass[count] != 0){
        fprintf(file, "%c", mass[count]);
        count++;
    }
}

void soundex(char *str, char *out_mass){

}


int main(void){
    FILE *input_file;
    input_file = fopen("input.txt", "r");
    FILE *output_file;
    output_file = fopen("output.txt", "w");
    char in_mass[FILE_LEN] = {0};
    int in_mass_len;
    char out_mass[FILE_LEN] = {0};

    in_mass_len = read_file_char(input_file, in_mass);

    soundex(in_mass, out_mass);

    write_file_char(output_file, out_mass);
    fclose(input_file);
    fclose(output_file);
    return 0;
}