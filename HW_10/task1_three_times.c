#include <stdio.h>

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

int main(void){
    char line[100] = {0};
    int line_len = 0;
    char symbol;
    int condition;
    FILE *input_file;
    FILE *output_file;
    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");
    /* Прочитать файл */
    line_len = read_file_char(input_file, line);
    fclose(input_file);
    /* Записать в файл */
    for(int i = 0; i < 2; i++){
        write_file_char(output_file, line, line_len);
        fprintf(output_file, ", ");
    }
    write_file_char(output_file, line, line_len);
    fprintf(output_file, " %d", line_len);
    fclose(output_file);
    return 0;
}