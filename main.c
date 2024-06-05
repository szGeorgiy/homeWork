#include "temp_functions.h"

cmd_flags flags = {
    .csv_path = NULL,
    .file_flag = 0,
    .help_flag = 0,
    .month = 0,
    .month_flag =0,
    .error_flag = 0
};

int main (int argc, char **argv){

    analize_flag(argc, argv);

    if (flags.error_flag){
        if (flags.file_flag){
            printf("===============================\n");
            printf("Неправильно указан путь к файлу\n");
            printf("===============================\n");
        } else if (flags.month_flag){
            printf("========================\n");
            printf("Неправильно указан месяц\n");
            printf("========================\n");
        }
    } else {
        if (flags.help_flag){
            /* Вспомогательное сообщение */
            printf("Програма выводит статистику по кажому месяцу\n");
            printf(" * Среднемесячная температура\n");
            printf(" * Минимальная температура в текущем месяце\n");
            printf(" * Максимальная температура в текущем месяце\n");
            printf(" * Среднегодовая температура\n");
            printf(" * Минимальная температура\n");
            printf(" * Максимальная температура\n");
            printf("\n");
            printf("Ключи:\n");
            printf("-h Описание функционала приложения\n");
            printf("-m <file_name.csv> если задан данный ключ,\n");
            printf("   то выводится только статистика за указанный месяц\n");
            printf("-f <номер месяца> входной файл csv для обработки\n");
        }
        if (flags.file_flag){
            FILE *my_file = fopen(flags.csv_path, "r");
            if (my_file == NULL){
                printf("===================\n");
                printf("Ошибка чтения файла\n");
                printf("===================\n");
            } else {
                /* Выполнение основной части программы */
                year_statistic my_year = {0};
                init_year(my_file, &my_year);
                int num_of_lines = 0;
                measurement *readed_lines;
                readed_lines = (measurement *) malloc(sizeof(measurement));
                // num_of_lines = read_file(my_file, readed_lines, num_of_lines);

                /**
                 * Я не знаю почему, но этот код работает корректно
                 * только если я заупскаю его так.
                */

                /* Start read_file */
                int condition = 0;
                int data_count = 0;
                char line[256] = {0};
                char *stop_condition;
                int line_count = 0;
                while (1){
                    stop_condition = fgets(line, sizeof(line), my_file);
                    if (stop_condition == NULL){
                        break;
                    }
                    line_count++;

                    condition = sscanf(line,
                        "%d;%d;%d;%d;%d;%d",
                        &readed_lines[data_count].year,
                        &readed_lines[data_count].month,
                        &readed_lines[data_count].day,
                        &readed_lines[data_count].hour,
                        &readed_lines[data_count].minut,
                        &readed_lines[data_count].temperature);

                    if( condition != 6 ){
                        printf("-------------------------\n");
                        printf("Ошибка чтения строки №%d\n", line_count - 1);
                        printf("-------------------------\n");
                        continue;
                    } else {
                        data_count++;
                        readed_lines = (measurement * ) realloc(readed_lines, sizeof(measurement) * (data_count + 1));
                    }
                }
                num_of_lines = data_count;
                /* end read_file */

                /* Расчёт статистических параметров */
                calc_middle(&my_year, readed_lines, num_of_lines);
                calc_min(&my_year, readed_lines, num_of_lines);
                calc_max(&my_year, readed_lines, num_of_lines);

                if (flags.month_flag){
                    /* Вывести информацию только за месяц */
                    print_month_statistic(&my_year, flags.month);
                } else {
                    /* Вывести всю информацию */
                    print_year_statistic(&my_year);
                }
            }
        } else {
            if (flags.month_flag){
                printf("======================\n");
                printf("Не указан путь к файлу\n");
                printf("======================\n");
            }
        }
    }
    return 0;
}