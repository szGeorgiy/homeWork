#include <stdio.h>
#include <string.h>

#define FILE_LEN 2000

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

void copy_with_no_repeat(char *in_mass, char *out_mass, char symbol){
    int in_count = 0;
    int out_count = 0;
    int condition;
    /* Не читать символ в начале */
    while (in_mass[in_count] == symbol){
        in_count++;
    }
    /* Копировать без повторений */
    condition = 1;
    while (in_mass[in_count]){
        /* Если символ совпадает */
        if (in_mass[in_count] == symbol){
            if (condition){
                out_mass[out_count] = in_mass[in_count];
                out_count++;
                in_count++;
                condition = 0;
            } else {
                in_count++;
            }
        /* Если не совпадает */
        } else {
            condition = 1;
            out_mass[out_count] = in_mass[in_count];
            out_count++;
            in_count++;
        }
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

    in_mass_len = read_file_char(input_file, in_mass);
    
    copy_with_no_repeat(in_mass, out_mass, ' ');

    write_file_char(output_file, out_mass);
    fclose(input_file);
    fclose(output_file);
    return 0;
}