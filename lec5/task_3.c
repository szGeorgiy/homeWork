#include <stdio.h>

int calc(int num1, int num2, char operation){
    /* В зависимости от символа выбираем операцию */
    switch (operation)
    {
    case '+':
        num1 += num2;
        break;
    case '-':
        num1 -= num2;
    case '*':
        num1 = num1 * num2;
        break;
    case '/':
        num1 /= num2;
        break;
    default:
        printf("UNDEFIND OPERATION\n");
        return 0;
    }
    return num1;
}

int polish_calc(char *symbols, int sym_len, int *numbers){
    /* В массиве символов хранятся операции 
    *  В массиве чисел значения над которыми осуществляем операции
    */
    int ret;
    /* Первый раз считаем в любом случае */
    ret = calc(numbers[0], numbers[1], symbols[0]);
    int sym_count = 1;
    int num_count = 2;
    /* Дальше считаем, пока не кончатся символы операций */
    while (sym_len - 1){
        ret = calc(ret, numbers[num_count], symbols[sym_count]);
        num_count++;
        sym_count++;
        sym_len--;
    }
    return ret;
}

int get_obj(char *cup, char *is_number, char *is_dot){
    char tmp;
    int count = 0;
    /* Считывать до пробела или точки */
    while (1){
        scanf("%c", &tmp);
        if (tmp == ' '){
            break;
        }
        if (tmp == '.'){
            *is_dot = 1;
            break;
        }
        cup[count] = tmp;
        count++;
    }
    /* Распознать число или символ операции */
    if (cup[0] >= '0' && cup[0] <= '9'){
        *is_number = 1;
    } else {
        *is_number = 0;
    }
    /* Вернуть число считываемых символов */
    return count;
}

int convert_to_num(char *cup, int len){
    /* Преобразовать последовательность символов в число */
    int ret = 0;
    int count = 0;
    int tmp;
    while (len){
        tmp = (int) (cup[count] - '0');
        for (int i = 1; i < len; i++){
            tmp *= 10;
        }
        ret += tmp;
        count++;
        len--;
    }
    return ret;
}

int is_symbol(char *cup){
    /* Распознаём валидные символы */
    int ret = 0;
    switch (cup[0]){
    case '+':
        ret = 1;
        break;
    case '-':
        ret = 1;
        break;
    case '*':
        ret = 1;
        break;
    case '/':
        ret = 1;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

int main(void){
    /* Массив символов операций */
    char symbols[1000] = {0};
    int sym_count = 0;
    /* Массив значений */
    int numbers[1000] = {0};
    int num_count = 0;
    /* Стакан */
    char tmp[100] = {0};
    int tmp_count;
    /* Флаг "Число" */
    char is_number;
    /* Флаг "Точка" */
    char is_dot = 0;
    /* Результат */
    int ret;

    /* Цикл чтения/распознавания символов */
    while (1){
        tmp_count = get_obj(tmp, &is_number, &is_dot);
        if (is_number){
            numbers[num_count] = convert_to_num(tmp, tmp_count);
            num_count++;
        } else {
            if (is_symbol(tmp)){
                symbols[sym_count] = tmp[0];
                sym_count++;
            }
        }
        if (is_dot){
            break;
        }
    }

    /* Тестовый вывод чисел */
    for (int i = 0; i < num_count; i++){
        printf("%d ", numbers[i]);
    }
    printf("\n");

    /* Тестовый вывод символов операций */
    for (int i = 0; i < sym_count; i++){
        printf("%c ", symbols[i]);
    }
    printf("\n");

    ret = polish_calc(symbols, sym_count, numbers);
    printf("%d\n", ret);
    return 0;
}