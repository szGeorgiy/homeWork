#include <stdio.h>

#define FILE_LEN 100

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

void get_petson(char *line, char *name, char *surname){
    int low_range = 0;
    int high_range = 0;
    int count = 0;
    /* Найти Фамилию */
    while(1){
        if(line[count] == ' '){
            high_range = count;
            break;
        }
        count++;
    }
    /* Запомнить Фамилию */
    for(int i = 0; i < high_range; i++){
        surname[i] = line[i];
    }
    /* Найти Имя */
    low_range = high_range + 1;
    count = low_range;
    while (1){
        if (line[count] == ' '){
            high_range = count;
            break;
        }
        count++;
    }
    /* Запомнить Имя*/
    for(int i = low_range; i < high_range; i++){
        name[i - low_range] = line[i];
    }
}

int create_out(char *out_mass, char *name, char *surname){
    /*Hello, Vasiliy Pupkin!*/
    int count = 0;
    char hello[7] = "Hello, ";
    for(int i = 0; i < sizeof(hello); i++){
        out_mass[count] = hello[i];
        count++;
    }
    int i = 0;
    while (name[i] != 0){
        out_mass[count] = name[i];
        i++;
        count++;
    }
    out_mass[count] = ' ';
    count++;
    i = 0;
    while (surname[i] != 0){
        out_mass[count] = surname[i];
        i++;
        count++;
    }
    out_mass[count] = '!';
    count++;
    return count;
}

int surname_len;
int name_len;

int main(void){
    FILE *input_file;
    input_file = fopen("input.txt", "r");
    FILE *output_file;
    output_file = fopen("output.txt", "w");
    char in_mass[FILE_LEN] = {0};
    int in_mass_len;
    char name[FILE_LEN] = {0};
    char surname[FILE_LEN] = {0};
    char out_mass[FILE_LEN] = {0};
    int out_mass_len;
    in_mass_len = read_file_char(input_file, in_mass);
    
    get_petson(in_mass, name, surname);
    out_mass_len = create_out(out_mass, name, surname);
    write_file_char(output_file, out_mass, out_mass_len);

    fclose(input_file);
    fclose(output_file);
    return 0;
}
