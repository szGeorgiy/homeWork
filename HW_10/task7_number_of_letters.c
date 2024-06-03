#include <stdio.h>

#define FILE_LEN 10000

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

const char low_dictionary[] = "qwertyuiopasdfghjklzxcvbnm";
const char high_dictionary[] = "QWERTYUIOPASDFGHJKLZXCVBNM";

void count_symbols(char *in_mass, int len, int *out_mass){
    char tmp;
    int condition;
    int low_count = 0;
    int high_count = 0;
    for(int i = 0; i < len; i++){
        tmp = in_mass[i];
        condition = 1;
        for(int x = 0; x < 27; x++){
            if (low_dictionary[x] == tmp){
                low_count++;
                condition = 0;
                break;
            }
        }
        if (condition){
            for(int x = 0; x < 27; x++){
                if (high_dictionary[x] == tmp){
                    high_count++;
                    break;
                }
            }
        }
    }
    out_mass[0] = low_count;
    out_mass[1] = high_count;
}

int main(void){
    FILE *input_file;
    FILE *output_file;
    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");
    char in_mass[FILE_LEN] = {0};
    int in_mass_len;
    int out_mass[2] = {0};
    int out_mass_len = 2;
    in_mass_len = read_file_char(input_file, in_mass);
    
    count_symbols(in_mass, in_mass_len, out_mass);
    fprintf(output_file, "%d %d", out_mass[0], out_mass[1]);
    fclose(input_file);
    fclose(output_file);
    return 0;
}