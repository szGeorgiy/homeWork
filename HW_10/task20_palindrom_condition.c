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

int main(void){
    FILE *input_file;
    input_file = fopen("input.txt", "r");
    char in_mass[FILE_LEN] = {0};
    int in_mass_len;
    int alfabet[26] = {0};
    int odd_numbers = 0;
    in_mass_len = read_file_char(input_file, in_mass);

    to_low(in_mass);
    freq_analize(in_mass, alfabet);

    for(int i = 0; i < 26; i++){
        if (alfabet[i] % 2 == 1){
            odd_numbers++;
        }
    }
    
    if (odd_numbers > 1){
        printf("NO");
    } else {
        printf("YES");
    }

    fclose(input_file);
    return 0;
}