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

int is_palindrom(char *str){
    int ret = 1;
    int end_index = 0;
    while(1){
        if (str[end_index] == 0){
            break;
        }
        end_index++;
    }
    for(int i = 0; i < end_index; i++){
        if (str[i] != str[end_index - i - 1]){
            ret = 0;
            break;
        }
    }
    return ret;
}

int main(void){
    FILE *input_file;
    FILE *output_file;
    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");
    char in_mass[FILE_LEN] = {0};
    int in_mass_len;
    in_mass_len = read_file_char(input_file, in_mass);
    if (is_palindrom(in_mass)){
        fprintf(output_file, "YES");
    } else {
        fprintf(output_file, "NO");
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}