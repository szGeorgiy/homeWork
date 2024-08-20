#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 104
// #define DEBAG

void take_prefix(char *line, char *prefix){
    int count = 0;
    char tmp;
    while (1){
        tmp = line[count];
        if (tmp == 0 || tmp == '_'){
            break;
        }
        count++;
    }
    if (count == 0){
        while (1){
            tmp = line[count];
            if (tmp == 0){
                break;
            }
            prefix[count] = line[count];
            count++;
        }
    } else {
        for (int i = 0; i < count; i++){
            prefix[i] = line[i];
        }
    }
}

void take_suffix(char *line, char *suffix){
    int index = 0;
    int count = 0;
    char tmp;
    while (1){
        tmp = line[count];
        if (tmp == '_'){
            index = count;
        }
        if (tmp == 0){
            break;
        }
        count++;
    }
    if (index == 0){
        count = 0;
        while (1){
            tmp = line[count];
            if (tmp == 0){
                break;
            }
            suffix[count] = line[count];
            count++; 
        }
    } else {
        index++;
        count = 0;
        while (1){
            tmp = line[index + count];
            if (tmp == 0){
                break;
            }
            suffix [count] = tmp;
            count++;
        }
    }
}

int comparsion_inclusion(char *prefix, char *suffix){
    int ret = 0;
    int pre_len = strlen(prefix);
    int suf_len = strlen(suffix);
    char tmp1[MAX_STRING_SIZE] = {0};
    char tmp2[MAX_STRING_SIZE] = {0};
    int count_hight;

    #ifdef DEBAG
    printf("prefix len = %lu\n", strlen(prefix));
    printf("suffix len = %lu\n", strlen(suffix));
    #endif

    if (pre_len > suf_len){
        count_hight = suf_len;
    } else {
        count_hight = pre_len;
    }
    for (int i = 1; i <= count_hight; i++){
        memset(tmp1, 0, MAX_STRING_SIZE);
        memset(tmp2, 0, MAX_STRING_SIZE);
        
        for (int j = 0; j < i; j++){
            tmp1[j] = prefix[j];
            tmp2[j] = suffix[suf_len - i + j];
        }

        #ifdef DEBAG
        printf("tmp1 %s\n", tmp1);
        printf("tmp2 %s\n", tmp2);
        #endif

        if (strcmp(tmp1, tmp2) == 0){
            ret = i;
        }
    }
    return ret;
}

int main(void){
    char line_1[MAX_STRING_SIZE] = {0};
    char line_2[MAX_STRING_SIZE] = {0};
    char prefix_1[MAX_STRING_SIZE] = {0};
    char prefix_2[MAX_STRING_SIZE] = {0};
    char suffix_1[MAX_STRING_SIZE] = {0};
    char suffix_2[MAX_STRING_SIZE] = {0};
    int ret_1, ret_2;
    /* Читаем первую строку */
    char tmp;
    int count = 0;
    while (1){
        scanf("%c", &tmp);
        if (tmp == '\n'){
            break;
        }
        line_1[count] = tmp;
        count++;
    }

    /* Читаем вторую строку */
    count = 0;
    while (1){
        scanf("%c", &tmp);
        if (tmp == '\n'){
            break;
        }
        line_2[count] = tmp;
        count++;
    }

    /* Выделяем префиксы */
    take_prefix(line_1, prefix_1);
    take_prefix(line_2, prefix_2);
    
    /* Выделяем суффиксы */
    take_suffix(line_1, suffix_1);
    take_suffix(line_2, suffix_2);

    #ifdef DEBAG
    /*Тестовый вывод*/
    printf("prefix1\n");
    printf("%s\n", prefix_1);
    printf("prefix2\n");
    printf("%s\n", prefix_2);
    printf("suffix1\n");
    printf("%s\n", suffix_1);
    printf("suffix2\n");
    printf("%s\n", suffix_2);
    #endif

    /* Непосредственное решение задачи */
    #ifdef DEBAG
    printf("ret1 pref1 suf2\n");
    #endif

    ret_1 = comparsion_inclusion(prefix_1, suffix_2);

    #ifdef DEBAG
    printf("ret2 pref2 suf1\n");
    #endif

    ret_2 = comparsion_inclusion(prefix_2, suffix_1);


    printf("%d %d", ret_1, ret_2);
    return 0;
}
/*
don't_panic
nick_is_a_mastodon
*/
/*
monty_python
python_has_list_comprehensions
*/