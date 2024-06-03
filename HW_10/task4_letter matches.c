#include <stdio.h>

#define MAX_WORD_LEN 100

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

int get_first_word(char *in_mass, char *out_mass){
    int count = 0;
    while (1){
        if (in_mass[count] != ' '){
            out_mass[count] = in_mass[count];
            count++;
        } else {
            break;
        }
    }
    return count;
}

int get_second_word(char *in_mass, char *second_word, int start, int end){
    for(int i = start; i < end; i++){
        second_word[i - start] = in_mass[i];
    }
    return end - start;
}

void get_unique_symbols(char *in_mass, char *out_mass){
    int in_count = 0;
    int i = 0;
    int out_count = 0;
    int tmp;
    while (in_mass[in_count]){
        tmp = 0;
        i = 0;
        /* сколько раз элемент встречается в массиве */
        while (in_mass[i]){
            if (in_mass[in_count] == in_mass[i]){
                tmp++;
            }
            i++;
        }
        /* Если один запомнить */
        if (tmp == 1){
            out_mass[out_count] = in_mass[in_count];
            out_count++;
        }
        in_count++;
    }
}

void get_coincidences(char *out_mass, char *mass1, char *mass2){
    int count;
    int out_count = 0;
    while (*mass1 && *mass2){
        count = 0;
        while (mass2[count]){
            if (*mass1 == mass2[count]){
                out_mass[out_count] = *mass1;
                out_count++;
                break;
            }
            count++;
        }
        mass1++;
    }
}

void write_file_char(FILE *file, char *mass){
    int count = 0;
    if (mass[count]){
        fprintf(file, "%c", mass[count]);
    }
    count++;
    while (mass[count]){
        fprintf(file, " %c", mass[count]);
        count++;
    }
}

int main(void){
    FILE *input_file;
    FILE *output_file;
    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");
    char in_mass[2 * MAX_WORD_LEN + 1] = {0};
    int in_mass_len;
    char out_mass[2 * MAX_WORD_LEN + 1] = {0};
    char first_word[MAX_WORD_LEN] = {0};
    int first_word_len;
    char second_word[MAX_WORD_LEN] = {0};
    int second_word_len;

    in_mass_len = read_file_char(input_file, in_mass);
    
    /* Выдилить слова */
    first_word_len = get_first_word(in_mass, first_word);
    second_word_len = get_second_word(in_mass, second_word, first_word_len + 1, in_mass_len);

    /* Получить уникальные символы */
    char unique_symbols_1[MAX_WORD_LEN] = {0};
    char unique_symbols_2[MAX_WORD_LEN] = {0};
    get_unique_symbols(first_word, unique_symbols_1);
    get_unique_symbols(second_word, unique_symbols_2);

    /* Уникальные в двух словах */
    get_coincidences(out_mass, unique_symbols_1, unique_symbols_2);

    write_file_char(output_file, out_mass);
    fclose(input_file);
    fclose(output_file);
    return 0;
}