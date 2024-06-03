#include <stdio.h>

int read_file_int(FILE *file, char *mass){
    int num;
    int count = 0;
    while (fscanf(file, "%d", &num) == 1){
        mass[count] = num;
        count++;
    }
    return count;
}

int number_to_char(char *mass, int number){
    int tmp;
    if (number > 9){
        tmp = number % 10;
        mass[1] = tmp + '0';
        number /= 10;
        tmp = number % 10;
        mass[0] = tmp + '0';
        return 2;
    } else {
        mass[0] = number + '0';
        return 1;
    }
}

int fill_mass(char *mass, int number){
    int count = 0;
    char character;
    int i = 0;
    while (count < number){
        character = 'A' + (i % 26);
        mass[count] = character;
        count++;
        character = '2' + 2 * (i % 4); 
        mass[count] = character;
        count++;
        i++;
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
    FILE *input_file;
    FILE *output_file;
    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");
    int in_mass[1];
    int in_mass_len;
    in_mass_len = read_file_int(input_file, in_mass);
    char out_mass[100];
    int out_mass_len;
    out_mass_len = fill_mass(out_mass, in_mass[0]);
    write_file_char(output_file, out_mass, out_mass_len);
    fclose(input_file);
    fclose(output_file);
    return 0;
}