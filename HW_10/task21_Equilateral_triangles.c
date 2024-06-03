#include <stdio.h>
#include <string.h>

#define FILE_LEN 2000

int is_symbol(char symbol){
    int condition = 1;
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

int calc_symbol(char *mass, char symbol){
    int ret = 0;
    while (*mass){
        if (*mass == symbol){
            ret++;
        }
        mass++;
    }
    return ret;
}

int it_may_be(int rocks){
    if (rocks <= 1){
        return 0;
    }
    int tmp = 1;
    for(int i = 2; i < rocks; i++){
        tmp += i;
        if (rocks == tmp){
            return 1;
        }
        if (rocks < tmp){
            return 0;
        }
    }
}

void make_triangles(FILE *file, int rocks){
    int lines = 0;
    /* Количество линий */
    for(int i = 1; rocks > 0; i++){
        lines++;
        rocks -= i;
    }
    int shift;
    for(int i = 1; i <= lines; i++){
        /* Напечатать пробелы */
        shift = lines - i;
        for(int x = 0; x < shift; x++){
            fprintf(file, " ");
        }
        /* Строка из камней */
        fprintf(file, "*");
        for(int x = 1; x < i; x++){
            fprintf(file, " *");
        }
        if(i != lines){
            fprintf(file, "\n");
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
    int out_mass_len;
    int rocks;
    int condition;

    in_mass_len = read_file_char(input_file, in_mass);

    rocks = calc_symbol(in_mass, '*');
    condition = it_may_be(rocks);
    printf("rock %d, cond %d\n", rocks, condition);
    if (condition){
        make_triangles(output_file, rocks);
    } else {
        fprintf(output_file, "NO");
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}