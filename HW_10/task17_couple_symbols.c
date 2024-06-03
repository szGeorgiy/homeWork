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

void swap_couple(char *in_mass){
    char tmp;
    int count_1 = 0;
    int count_2 = 1;
    int end_condition = 0;
    while (in_mass[count_1]){
        printf("count 1 = %d count 2 = %d\n", count_1, count_2);
        if (in_mass[count_1] != ' '){

            /* найти индекс следующего символа */
            count_2 = count_1 + 1;
            while (1){
                /* Елси подходящего элемента нет закончить выполнение программы */
                if (in_mass[count_2] == 0){
                    end_condition = 1;
                    break;
                }
                if (in_mass[count_2] != ' '){
                    break;
                }
                count_2++;
            }

            /* Закончить цикл */
            if(end_condition){
                break;
            }

            /* SWAP */
            tmp = in_mass[count_1];
            in_mass[count_1] = in_mass[count_2];
            in_mass[count_2] = tmp;
            
            count_1 = count_2 + 1;
        } else {
            count_1++;
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
    in_mass_len = read_file_char(input_file, in_mass);

    swap_couple(in_mass);

    write_file_char(output_file, in_mass);
    fclose(input_file);
    fclose(output_file);
    return 0;
}