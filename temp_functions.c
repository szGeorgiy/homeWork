#ifndef TEMP_C
#define TEMP_C

#include "temp_functions.h"

int test(int argc, char *argv[]){
    return 0;
}

int take_month(char month[]){
    int ret = 0;
    char ch[3] = {0};
    int ch_len = 0;
    while (month[ch_len]){
        ch[ch_len] = month[ch_len];
        ch_len++;
        if (ch_len >= 2){
            break;
        }
    }
    int condition;
    if (ch_len >= 2){
        condition = ch[0] >= '0' && ch[0] <= '9';
        condition &= ch[1] >= '0' && ch[1] <= '9';
        ret += (ch[0] - '0') * 10;
        ret += ch[1] - '0';
    } else {
        condition = ch[0] >= '0' && ch[0] <= '9';
        ret = ch[0] - '0';
    }

    if (ret >= 1 && ret <= 12){
        return ret;
    }
    printf("============================\n");
    printf("Некорректное значение месяца\n");
    printf("============================\n");
    return 0;
}

void analize_flag(int argc, char *argv[]){
    if (argc > 1){
        for(int i = 1; i < argc; i++){
            if (strcmp(argv[i], FILE_PATH) == 0){
                flags.file_flag = 1;
                if (argc - 1 - i < 1){
                    /* Не указан путь к файлу */
                    printf("======================\n");
                    printf("Не указан путь к файлу\n");
                    printf("======================\n");
                    flags.error_flag = 1;
                } else {
                    /* Заромнить путь к файлу */
                    flags.csv_path = argv[i + 1];
                }
            }
            if (strcmp(argv[i], MONTH) == 0){
                flags.month_flag = 1;
                if (argc - 1 - i < 1){
                    /* не указан месяц */
                    printf("========================\n");
                    printf("Неправильно указан месяц\n");
                    printf("========================\n");
                    flags.error_flag = 1;
                } else {
                    /* Запомнить месяц */
                    int month = 0;
                    month = take_month(argv[i + 1]);
                    if(month){
                        flags.month = month;
                    } else {
                        flags.error_flag = 1;
                    }
                }
            }
            if (strcmp(argv[i], HELP) == 0){
                flags.help_flag = 1;
            }
        }
    } else {
        /* Не указаны аргументы коммандной строки */
        flags.help_flag = 1;
    }
    /* Если не удалось распознать аргуметны */
    int condition = 0;
    condition += flags.file_flag;
    condition += flags.month_flag;
    condition += flags.help_flag;
    if (condition == 0){
        /* Вывести вспомогательное сообщение */
        flags.help_flag = 1;
    }
}

void init_year(FILE *file, year_statistic *stat){
    for(int i = 0; i < 12; i++){
        stat->month[i].month = i + 1;
    }
}

void printf_year_statistic(year_statistic *stat){
    for(int i = 0; i < 12; i++){
        printf("month %d\n", stat->month[i].month);
    }
}

// int add_struct(measurement *meas, int len){
//     meas = (measurement *) realloc(meas, len + 1);
//     return len + 1;
// }
int read_file(FILE *file, measurement *data, int len){
    /* Прочитать строку из файла*/
    int condition = 0;
    int data_count = 0;
    char line[256] = {0};
    char *stop_condition;
    int line_count = 0;
    while (1){
        stop_condition = fgets(line, sizeof(line), file);
        if (stop_condition == NULL){
            break;
        }
        line_count++;

        condition = sscanf(line,
            "%d;%d;%d;%d;%d;%d",
            &data[data_count].year,
            &data[data_count].month,
            &data[data_count].day,
            &data[data_count].hour,
            &data[data_count].minut,
            &data[data_count].temperature);

        if (condition != 6 ){
            // printf("condition %d\n", condition);
            printf("-------------------------\n");
            printf("Ошибка чтения строки №%d\n", line_count - 1);
            printf("-------------------------\n");
            continue;
        } else {
            data = (measurement *) realloc(data, sizeof(measurement) * (data_count+3));
            data_count++;
        }
    }
    return data_count;
}

void printf_measurement(measurement *meas, int len){
    printf("Year Month Day Hour Minute Temp\n");
    for(int i = 0; i < len; i++){
        printf("%d %d     %d  %d    %d      %d\n", meas[i].year, meas[i].month, meas[i].day, meas[i].hour, meas[i].minut, meas[i].temperature);
    }
}

void calc_middle(year_statistic *year_stat, measurement *mass, int len){
    int meaning[12] = {0};
    int quantity[12] = {0};
    int month;
    float mid = 0;
    int number = 0;
    for (int i = 0; i < len; i++){
        month = mass[i].month - 1;
        meaning[month] += mass[i].temperature;
        quantity[month] += 1;
        mid += mass[i].temperature;
        number++;
    }
    for(int i = 0; i < 12; i++){
        year_stat->month[i].middle_temp = (float) meaning[i] / quantity[i];
    }
    year_stat->middle_temp = mid / number;
}

void calc_min(year_statistic *year_stat, measurement *mass, int len){
    int meaning[12] = {0};
    int first[12] = {0};
    int month;
    int condition;
    for (int i = 0; i < len; i++){
        month = mass[i].month - 1;
        if (first[month] == 0){
            meaning[month] = mass[i].temperature;
            first[month] = 1;
        } else {
            condition = meaning[month] > mass[i].temperature;
            if(condition){
                meaning[month] = mass[i].temperature;
            }
        }
    }
    int min = meaning[0];
    for(int i = 0; i < 12; i++){
        year_stat->month[i].min_temp = meaning[i];
        if (min > meaning[i]){
            min = meaning[i];
        }
    }
    year_stat->min_temp = min;
}

void calc_max(year_statistic *year_stat, measurement *mass, int len){
    int meaning[12] = {0};
    int first[12] = {0};
    int month;
    int condition;
    for (int i = 0; i < len; i++){
        month = mass[i].month - 1;
        if (first[month] == 0){
            meaning[month] = mass[i].temperature;
            first[month] = 1;
        } else {
            condition = meaning[month] < mass[i].temperature;
            if(condition){
                meaning[month] = mass[i].temperature;
            }
        }
    }
    int max = meaning[0];
    for(int i = 0; i < 12; i++){
        year_stat->month[i].max_temp = meaning[i];
        if (max < meaning[i]){
            max = meaning[i];
        }
    }
    year_stat->max_temp = max;
}

void take_str_month(char* month, int number){
    switch (number)
    {
    case 1:
        strcpy(month, "Январе");
        break;
    case 2:
        strcpy(month, "Феврале");
        break;
    case 3:
        strcpy(month, "Марте");
        break;
    case 4:
        strcpy(month, "Апреле");
        break;
    case 5:
        strcpy(month, "Мае");
        break;
    case 6:
        strcpy(month, "Июне");
        break;
    case 7:
        strcpy(month, "Июле");
        break;
    case 8:
        strcpy(month, "Авгусе");
        break;
    case 9:
        strcpy(month, "Сентябре");
        break;
    case 10:
        strcpy(month, "Октябре");
        break;
    case 11:
        strcpy(month, "Ноябре");
        break;
    case 12:
        strcpy(month, "Декабре");
        break;
    default:
        strcpy(month, "NON");
        break;
    }
}

void print_month_statistic(year_statistic *year_stat, int mes){
    char ch[20] = {0};
    take_str_month(ch, mes);
    printf("Средняя температура\t\tв %s составила: %.1f\n",ch,year_stat->month[mes - 1].middle_temp);
    printf("Минимальная температура\t\tв %s составила: %d\n", ch, year_stat->month[mes - 1].min_temp);
    printf("Максимальная температура\tв %s составила: %d\n", ch, year_stat->month[mes - 1].max_temp);
    printf("-------------------------------------------------------\n");
}

void print_year_statistic(year_statistic *year_stat){
    printf("            |=================|\n");
    printf("            |Статистика за год|\n");
    printf("            |=================|\n");
    printf("\n");
    printf("Средняя температура      за год составила: %.1f\n",year_stat->middle_temp);
    printf("Минимальная температура  за год составила: %d\n", year_stat->min_temp);
    printf("Максимальная температура за год составила: %d\n", year_stat->max_temp);
    printf("\n");
    printf("            |=====================|\n");
    printf("            |Статистика по месяцам|\n");
    printf("            |=====================|\n");
    printf("\n");
    for(int i = 1; i < 13; i++){
        print_month_statistic(year_stat, i);
    }
}

#endif