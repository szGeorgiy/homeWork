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

void write_file_char(FILE *file, char *mass, int len){
    int count = 0;
    while (count < len){
        fprintf(file, "%c", mass[count]);
        count++;
    }
}

int find_longes_word(char *in_mass, int len, char *out_mass){
    int start_index = 0;
    int end_index = 1;
    int max_len = 0;
    int my_start_index = 0;
    int i_have_spase = 0;
    /* Длина слов от первого до предпоследнего */
    for(int i = 1; i < len; i++){
        if(in_mass[i] == ' '){
            i_have_spase = 1;
            end_index = i - 1;
            if(end_index - start_index > max_len){
                max_len = end_index - start_index + 1;
                my_start_index = start_index;
            }
            start_index = i + 1;
        }
    }
    /* Если последнее слово больше */
    if (len - end_index > max_len){
        max_len = len - end_index;
        my_start_index = end_index + 2;
    }
    if(i_have_spase){
        for(int i = 0; i < max_len; i++){
            out_mass[i] = in_mass[i + my_start_index];
        }
        return max_len;
    } else {
        for(int i = 0; i < len; i++){
            out_mass[i] = in_mass[i];
        }
        return len;
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

    out_mass_len = find_longes_word(in_mass, in_mass_len, out_mass);
    write_file_char(output_file, out_mass, out_mass_len);
    fclose(input_file);
    fclose(output_file);
    return 0;
}