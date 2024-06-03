#include <stdio.h>
#include <string.h>

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
        if (count >= FILE_LEN){
            mass[count] = 0;
            break;
        }
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

void to_low(char *mass){
    int count = 0;
    while (mass[count]){
        if (mass[count] >= 'A' && mass[count] <= 'Z'){
            mass[count] = mass[count] + 0x20;
        }
        count++;
    }
}

void freq_analize(char *str, int *mass){
    int count = 0;
    while (str[count]){
        if(str[count] >= 'a' && str[count] <= 'z'){
            mass[str[count] - 'a']++;
        }
        count++;
    }
}

void create_palindrom(int *freq, char *palindrom){
    char ret[FILE_LEN] = {0};
    /* Найти символ с нечётным количеством повторений */
    int have_odd = 0;
    int odd_posicion = 0;
    for(int i = 0; i < 26; i++){
        if(freq[i] % 2 == 1){
            have_odd = 1;
            odd_posicion = i;
            break;
        }
    }
    
    /* Для создания половины декрементировать нечётные счётчики */
    if (have_odd){
        for(int i = 0; i < 26; i++){
            if (freq[i] % 2 == 1){
                freq[i]--;
            }
        }
    }
    /* Составить половину повторяющегося текста */
    char half[FILE_LEN] = {0};
    int half_count = 0;
    int condition;
    for(int i = 0; i < 26; i++){
        condition = (freq[i] % 2 == 0) && (freq[i] != 0);
        if (condition){
            for(int x = 0; x < freq[i] / 2; x++){
                half[half_count] = i + 'a';
                half_count++;
            }
        }
    }

    int ret_count = 0;
    for(int i = 0; i < half_count; i++){
        ret[ret_count] = half[i];
        ret_count++;
    }

    if (have_odd) {
        printf("добавление нечётного\n");
        ret[ret_count] = odd_posicion + 'a';
        ret_count++;
    }

    for(int i = half_count - 1; i >= 0; i--){
        ret[ret_count] = half[i];
        ret_count++;
    }

    int tmp;
    if (have_odd){
        tmp = 2 * half_count + 1;
    } else {
        tmp = 2 * half_count;
    }
    for (int i = 0; i < tmp; i++){
        palindrom[i] = ret[i];
    }
}

int main(void){
    FILE *input_file;
    input_file = fopen("input.txt", "r");
    FILE *output_file;
    output_file = fopen("output.txt", "w");
    char in_mass[FILE_LEN + 1] = {0};
    int in_mass_len;
    char out_mass[FILE_LEN + 1] = {0};
    in_mass_len = read_file_char(input_file, in_mass);
    
    int alfabet_count[26] = {0};

    to_low(in_mass);
    freq_analize(in_mass, alfabet_count);
    create_palindrom(alfabet_count, out_mass);

    write_file_char(output_file, out_mass);
    fclose(input_file);
    fclose(output_file);
    return 0;
}