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

void write_file_char(FILE *file, char *mass, int len){
    int count = 0;
    while (mass[count] != 0){
        fprintf(file, "%c", mass[count]);
        count++;
    }
}

void change_word(char *in_mass, char *out_mass, char *cut, char *paste){
    int out_count = 0;
    int cut_len = 0;
    int paste_len = 0;
    /* Получить длинну строки cut */
    while (cut[cut_len] != 0){
        cut_len++;
    }
    /* Получить длинну строки paste */
    while (paste[paste_len] != 0){
        paste_len++;
    }
    int condition;
    for(int i = 0; in_mass[i] != 0; i++){
        /* Если i - индекс первого элемента
           заменяемого слова
        */
        condition = 1;
        for(int x = 0; x < cut_len; x++){
            if (in_mass[i + x] != cut[x]){
                condition = 0;
                break;
            }
        }
        if (condition){
            /* заменяем слово */
            for(int y = 0; y < paste_len; y++){
                out_mass[out_count] = paste[y];
                out_count++;
            }
            i += cut_len - 1;
        } else {
            /* просто запоминаем элемент */
            out_mass[out_count] = in_mass[i];
            out_count++;
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
    in_mass_len = read_file_char(input_file, in_mass);
    
    char *str1 = "Cao";
    char *str2 = "Ling";
    change_word(in_mass, out_mass, str1, str2);

    write_file_char(output_file, out_mass, out_mass_len);
    fclose(input_file);
    fclose(output_file);
    return 0;
}