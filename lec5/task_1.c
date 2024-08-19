#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

unsigned long int combinations_n_3(int n){
    unsigned long int ret = 1;
    unsigned long int tmp = n - (n - 3);
    for (unsigned long int i = tmp; i <= n; i++){
        ret *= i;
    }
    ret /= 6;
    return ret;
}

int in_mass(uint32_t *mas, size_t len, uint32_t word){
    int tmp = 0;
    for (int i = 0; i < len; i++){
        tmp = mas[i] == word;
        if (tmp == 1){
            break;
        }
    }
    return tmp;
}

void my_print(uint32_t num){
    char s1;
    char s2;
    char s3;
    s3 = (char) num;
    num >>= 8;
    s2 = (char) num;
    num >>= 8;
    s1 = (char) num;
    printf("%c%c%c\n", s1, s2, s3);
}

int main (void){
    /* Чтение числа, как строки */
    char *string = malloc(1024);
    int count;
    scanf("%s", string);
    count = strlen(string);
    if (count < 3){
        printf("0\n");
        return 0;
    }
    /* Заполанение массива строк */
    uint32_t *words = malloc(sizeof(int));
    uint32_t word;
    size_t words_count;
    word = ((int) string[0]) << 16;
    word |= ((int) string[1]) << 8;
    word |= (int) string[2];
    words_count = 1;
    words[0] = word;
    int tmp;
    // printf("count = %d\n", count);
    for (int i0 = 0; i0 < count - 2; i0++){
        for (int i1 = i0 + 1; i1 < count - 1; i1++){
            for (int i2 = i1 + 1; i2 < count; i2++){
                /* Формируем слово из 3 символов */
                word = ((int) string[i0]) << 16;
                word |= ((int) string[i1]) << 8;
                word |= (int) string[i2];
                
                /* Если слово уникально - добавить в массив, увеличить счётчик*/
                tmp = in_mass(words, words_count, word);
                // printf("%c%c%c\n", string[i0], string[i1], string[i2]);
                // my_print(word);
                // printf("%d\n\n", tmp);
                if (!tmp){
                    words = (int *) realloc(words, sizeof(int)*words_count+1);
                    words[words_count] = word;
                    words_count++;
                }
            }
        }
    }

    /* Вывод информации */
    printf("всего слов %lu\n", words_count);
    for (int i = 0; i < words_count; i++){
        my_print(words[i]);
    }
    // int mas_count = 0;
    // printf("%d\n", mas_count);
    
    return 0;
}