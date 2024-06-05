#ifndef TEMP_H
#define TEMP_H

/* Стандартные библиотеки */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Дефайны*/
#define FILE_PATH "-f"
#define HELP "-h"
#define MONTH "-m"

/* Структуры */

/** Структура хранит аргументы командной строки
 *  и путь к файлу
*/
typedef struct cmd_flags
{
    /* Путь до файла */
    char* csv_path;
    /* Флаг файла */
    int file_flag;
    /* Месяц */
    int month;
    /* Флаг месяца */
    int month_flag;
    /* Флаг помощи */
    int help_flag;
    /* Флаг ошибки */
    int error_flag;
}cmd_flags;

extern cmd_flags flags;

/* Хранит результаты одного измерения */
typedef struct measurement
{
    int status;
    int year;
    int month;
    int day;
    int hour;
    int minut;
    int temperature;
}measurement;

/* Хранит статистику за месяц */
typedef struct month_statistic
{
    int year;
    int month;
    float middle_temp;
    int min_temp;
    int max_temp;
}month_statistic;

/* Хранит статистику за год */
typedef struct year_statistic
{
    float middle_temp;
    int min_temp;
    int max_temp;
    month_statistic month[12];
}year_statistic;

/* Функции */

int test(int argc, char *argv[]);

int take_month(char month[]);

void analize_flag(int argc, char *argv[]);

void printf_year_statistic(year_statistic *stat);

int read_file(FILE *file, measurement *data, int len);

void printf_measurement(measurement *meas, int len);

void init_year(FILE* file, year_statistic* stat);

void calc_middle(year_statistic *year_stat, measurement *mass, int len);

void calc_min(year_statistic *year_stat, measurement *mass, int len);

void calc_max(year_statistic *year_stat, measurement *mass, int len);

void print_year_statistic(year_statistic *year_stat);

void print_month_statistic(year_statistic *year_stat, int month);

void take_str_month(char* month, int number);

#endif