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

void write_file_char(FILE *file, char *mass){
    int count = 0;
    while (mass[count] != 0){
        fprintf(file, "%c", mass[count]);
        count++;
    }
}

void copy_with_norepeat(char *in_mass, char *out_mass){
    int in_count = 0;
    int out_count = 0;
    int original_condition;
    int tmp;
    char original_symbols[FILE_LEN] = {0};
    while (1){
        /* Условие выхода */
        if (in_mass[in_count] == 0){
            break;
        }
        /* Игнорировать пробелы */
        if (in_mass[in_count] == ' '){
            in_count++;
            continue;
        }
        /* Проверка на оригинальность */
        original_condition = 1;
        tmp = 0;
        while (original_symbols[tmp] != 0){
            if (in_mass[in_count] == original_symbols[tmp]){
                original_condition = 0;
                break;
            }
            tmp++;
        }

        if (original_condition){
            /* Считать элемент оригинальным */
            original_symbols[tmp] = in_mass[in_count];
            /* Запомнить его */
            out_mass[out_count] = in_mass[in_count];
            out_count++;
        }
        in_count++;
    }
}

int main(void){
    FILE *input_file;
    input_file = fopen("input.txt", "r");
    FILE *output_file;
    output_file = fopen("output.txt", "w");
    char in_mass[FILE_LEN] = {0};
    char out_mass[FILE_LEN] = {0};

    read_file_char(input_file, in_mass);
    copy_with_norepeat(in_mass, out_mass);
    write_file_char(output_file, out_mass);

    fclose(input_file);
    fclose(output_file);
    return 0;
}